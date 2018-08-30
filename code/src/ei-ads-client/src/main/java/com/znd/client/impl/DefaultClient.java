package com.znd.client.impl;

import java.util.Date;
import java.util.UUID;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;

import com.znd.bus.channel.Channel;
import com.znd.bus.channel.Event;
import com.znd.bus.channel.ChannelMessage;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.bus.common.buffer.AdsNodeInfoBuffer;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.model.AdsNodeInfo;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.common.model.CalcJobStateEnum;
import com.znd.client.Client;
import com.znd.config.ClientConfig;
import com.znd.event.AplBean;
import com.znd.event.AplContext;
import com.znd.event.EvenInvoker;
import com.znd.event.EvenInvokerRegistory;
import com.znd.exception.AplException;
import com.znd.exception.EventException;
import com.znd.memory.ShareMemHolder;
import com.znd.model.SystemResourceInfo;
import com.znd.server.impl.SystemResourceServerImpl;


public class DefaultClient implements Client {	
	
	private final Logger logger = LoggerFactory
			.getLogger(DefaultClient.class);
	
	//@Autowired
	private EvenInvokerRegistory evenListenerRegistory = new EvenInvokerRegistory();

	@Autowired
	private ClientConfig config;
	
	@Autowired
	private AdsNodeInfoBuffer adsNodeBuffer;
	
	private AtomicBoolean exit = new AtomicBoolean(false);  
	
	private AdsNodeInfo node;
	
	private Byte nodeUplateFlag = 0;
	
	@Autowired
	private Channel jobChannel;
	
	@Autowired
	private CalcJobBuffer calcJobBuffer;
	
	
	private ExecutorService pool =  Executors.newCachedThreadPool();
	
	@Autowired
    private ApplicationContext context;
		
	
	@Autowired
	private ShareMemHolder shareMemHolder;
	
	public DefaultClient() {
		
	}
	@PostConstruct
	public void start() {
		
		evenListenerRegistory.init(context);
		config.getThreadPool().execute(new Runnable() {
			
			@Override
			public void run() {
				init();
				
				System.out.println("Client started.");
				while (!exit.get()) {
					heatBeat();
					
					try {
						
						Thread.sleep(config.getHeartbeat());
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						
					}
				}
				
				
				destory();
				System.out.println("Client exit.");
			}
		});
		
		jobChannel.register((e)-> {pool.execute(()->{processEvent(e);});});
	}

	private void processEvent(Event e) {
		System.out.println("Receive message :"+e.getCode()+", content="+e.getContent());
		synchronized (nodeUplateFlag) {
		  node.setAccMsgCount(node.getAccMsgCount()+1);
		  node.setCurMsgCount(node.getAccMsgCount()+1);
		  adsNodeBuffer.update(node);
		}
		
		//if (e.getCode() == MessageCodeEnum.created_Job || e.getCode() == MessageCodeEnum.stop_Job
		
		String content = e.getContent();
		CalcJob job = null;
		if (content != null && !content.isEmpty())
		   job  = calcJobBuffer.findById(content);
		
		if (job != null) {
			
			AplBean aplBean = evenListenerRegistory.findApl(job.getTypeId());
		    if (aplBean == null) {
		    	logger.info("Can't process job :id = {} ,type= {}", job.getId(), job.getTypeId());
		    	return;
		    }
		    
		    final AplContext context = aplBean.getContext();
		    if (e.getCode().compareTo(MessageCodeEnum.stop_Job.name()) == 0) {
		    	
				context.setQuit();
				long timeout = 60 * 1000 * 5;
				try {
					context.waitForJobQuit(timeout);
					logger.info("Job finished : "+ job.getId());
				} catch (InterruptedException e1) {
					throw new AplException("Fail to stop job， waiting is timeout :"+e.getContent(), e1);
				} finally {
					context.clear();
					shareMemHolder.clear();
				}
	    	
				return;
			} else if (e.getCode().compareTo(MessageCodeEnum.start_job.name()) == 0) {
				context.setRunning(true);
//				job.setStart(new Date());
//				job.setElapse(null);
//				job.setEnd(null);
				job.setState(CalcJobStateEnum.running);
				calcJobBuffer.update(job);
				synchronized (nodeUplateFlag) {
					Integer count = node.getJobCount();
					if (count == null)
						count = 0;
					
					node.setJobCount(count+1);
					adsNodeBuffer.update(node);	
				}
				
				
			}
		    
			//保存工作id到apl执行上下文中，用于方法调用
		    final EvenInvoker evenListener = evenListenerRegistory.find(job.getTypeId(), e.getCode());
		    
			context.setAttribute("jobId", job.getId());
			context.setAttribute("job", job);
			
		    if (evenListener != null) {
		    	
		    	try {
		           evenListener.invoke(e.getContent());
		    	} catch (EventException e3) {
		    		e3.printStackTrace();
		    		job.setState(CalcJobStateEnum.abnormal);
		    		calcJobBuffer.update(job);
		    		context.clear();
		    		throw e3;
		    	}
		        MessageCodeEnum outMessage = evenListener.getOutputMessage();
		        if (outMessage != null && outMessage != MessageCodeEnum.none) { 		        	
		        	jobChannel.send(new ChannelMessage(outMessage, job.getId()));
		        } else { //job finished
		        	job.setState(CalcJobStateEnum.stop);
		        	job.setEnd(new Date());
		        	
		        	long elapse = -1;
		        	if (job.getStart() != null) {
		        		elapse = job.getEnd().getTime() - job.getStart().getTime();
		        	}
		        	
		        	logger.info("Job finished : "+ job.getId()+", elapse = "+elapse);
		        	
		        	job.setElapse(elapse);
		        	calcJobBuffer.update(job);
		        	
		        	
		        }
		    }
           
		    
		}
	}
		

	public AdsNodeInfo getNode() {		
		 return node;		
	}
	

	//初始化计算节点配置
	private void init() {

		//AdsNode node1 = adsNodeMapper.getNodeById("f42da8d0-2ba3-47b5-bb69-119a32e0c23c");
		String url = "http://"+config.getIp()+":"+config.getPort();
		//List<AdsNode> nodes = adsNodeMapper.findAll();
		node = adsNodeBuffer.getNodeByUrl(url);
		
		if (node == null) {
			
			node = new AdsNodeInfo();
			node.setId(UUID.randomUUID().toString());
			node.setLastUpdate(new Date());
			node.setName(config.getHostName());
			node.setUrl(url);
			adsNodeBuffer.insert(node);			
			logger.info("Succeed to regist ads node : {}, url : {}", node.getName(), node.getUrl());			
		} else {
			node.setName(config.getHostName());
		}
		
	}

	//更新buffer中的节点表对应计算节点时间。
	private void heatBeat() {
		synchronized(nodeUplateFlag) {
		  logger.debug("update node time.");
		  node.setLastUpdate(new Date());
		  
		  SystemResourceInfo info = SystemResourceServerImpl.createSystemResourceInfo();
		  node.setCpuRate(info.getCpu().getLoad());
		  node.setMemoryRate(info.getMemory().getGlobalUsedMemoryRate());
		  adsNodeBuffer.update(node);
		  
		}
	}
	
	//更改节点状态
	private void destory() {
		
	}
	
	@PreDestroy
	public void close() {
		exit.set(true);
	}
}
