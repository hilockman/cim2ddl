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

import com.znd.bus.channel.Channel;
import com.znd.bus.channel.Event;
import com.znd.bus.channel.Listener;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.bus.common.buffer.AdsNodeInfoBuffer;
import com.znd.bus.common.model.AdsNodeInfo;
import com.znd.client.Client;
import com.znd.config.ClientConfig;
import com.znd.event.AplContext;
import com.znd.event.EvenInvoker;
import com.znd.event.EvenInvokerRegistory;
import com.znd.exception.AplException;
import com.znd.model.SystemResourceInfo;
import com.znd.server.impl.SystemResourceServerImpl;


public class DefaultClient implements Client {	
	
	private final Logger logger = LoggerFactory
			.getLogger(DefaultClient.class);
	
	@Autowired
	private EvenInvokerRegistory evenListenerRegistory;

	@Autowired
	private ClientConfig config;
	
	@Autowired
	private AdsNodeInfoBuffer adsNodeBuffer;
	
	private AtomicBoolean exit = new AtomicBoolean(false);  
	
	private AdsNodeInfo node;
	
	@Autowired
	private Channel jobChannel;
	
	private ExecutorService pool =  Executors.newCachedThreadPool();
		
	@PostConstruct
	public void start() {
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
		
		jobChannel.register(new Listener() {
			
			@Override
			public void receive(Event e) {
				System.out.println("Receive message :"+e.getCode()+", content="+e.getContent());
				node.setAccMsgCount(node.getAccMsgCount()+1);
				node.setCurMsgCount(node.getAccMsgCount()+1);
				adsNodeBuffer.update(node);
				
				final EvenInvoker evenListener = evenListenerRegistory.find(e.getCode());
				if (evenListener != null)
				    pool.execute(()->{processEvent(evenListener, e);});
			     
		    } 
		});
	}

	public AdsNodeInfo getNode() {
		synchronized(node) {
		   return node;
		}
	}
	
	
	private void processEvent(EvenInvoker invoker, Event e){
		
		AplContext context = invoker.getContext();
		if (e.getCode() == MessageCodeEnum.stop_Job) {
			context.setQuit();
			long timeout = 60 * 1000 * 5;
			try {
				context.waitForJobQuit(timeout);
			} catch (InterruptedException e1) {
				throw new AplException("Fail to stop job， waiting is timeout :"+e.getContent(), e1);
			} finally {
				context.clear();
			}
			return;
		} else if (e.getCode() == MessageCodeEnum.created_Job) {
			//保存工作id到apl执行上下文中，用于方法调用
			context = invoker.getContext();
			context.setAttribute("jobId", e.getContent());
		}
		invoker.invoke(e.getContent());
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
		synchronized(node) {
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
