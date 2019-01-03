package com.znd.reliability.server.impl;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.TimeUnit;

import org.redisson.api.RSemaphore;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.CreateFlag;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.exception.MessageException;
import com.znd.bus.task.AQueue;
import com.znd.bus.util.TimeCount;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.ei.memdb.reliabilty.domain.System;
import com.znd.exception.AplException;
import com.znd.reliability.buffer.FStateBuffer;
import com.znd.reliability.buffer.FStateFDevBuffer;
import com.znd.reliability.buffer.FStateMIslandBuffer;
import com.znd.reliability.buffer.FStateOvlAdBuffer;
import com.znd.reliability.buffer.FStateOvlDevBuffer;
import com.znd.reliability.buffer.SystemBuffer;
import com.znd.reliability.model.RequestEstimate;
import com.znd.reliability.model.ResponseEstimate;
import com.znd.reliability.model.ResponseEstimate.Content;
import com.znd.reliability.server.PrBufferServer;

public class PrBufferServerImpl implements PrBufferServer {

	private static final Logger LOGGER = LoggerFactory
			.getLogger(PrBufferServerImpl.class);
	
	//任务
	private final AQueue<RequestEstimate> taskList;
	//结果本地缓存
	private BlockingQueue<ResponseEstimate> localResultList = new LinkedBlockingQueue<ResponseEstimate>();
	private final RSemaphore resultSemaphore;
	
	
	private final FStateBuffer fstateMapper;
	private final FStateFDevBuffer devMapper;
	private final FStateOvlAdBuffer ovlAdMapper;
	private final FStateOvlDevBuffer ovlDevMapper;
	private final FStateMIslandBuffer islandMapper;
	private final SystemBuffer systemBuffer;
	
	public static final String TYPE_PACKAGE = "com.znd.ei.memdb.reliabilty.domain";
	public static final String MAPPER_PACKAGE = "com.znd.reliability.buffer";
	
	private final CalcJob job;

	private BufferFactory factory;
	
	public PrBufferServerImpl(Buffer parentBuffer, CalcJob job) {
//		
//		if (job == null || job.getModelId() == null || job.getModelId().isEmpty()) {
//			throw new AplException("job is null or job name is empty :"+job);
//		}
		this.job = job;
		String dbId = job.getId();
		BufferConfig config = parentBuffer.getConfig();
		AQueue<RequestEstimate> taskList = config.getList(job.getId()+":task");
		if (taskList == null)
			throw new AplException("Cann't create task list : "+job.getId());
		
		this.taskList = taskList;
		this.resultSemaphore = config.getSemaphore(job.getId()+":result:semaphore");
				
		BufferFactoryBuilder builder  = new BufferFactoryBuilder();
		 factory = null;
		new TimeCount.Builder().name("build buffer").runnable(new Runnable() {
			
			@Override
			public void run() {
				try {
					factory = builder.build(dbId, CreateFlag.UPDATE, TYPE_PACKAGE, MAPPER_PACKAGE, config);
				} catch (BindingException | BufferException | MessageException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					return;
				}
			}
		}).build().exec();
		
		Buffer buffer = factory.openSession();
			
		fstateMapper = factory.config().getMapper(FStateBuffer.class, buffer);
		devMapper = factory.config().getMapper(FStateFDevBuffer.class, buffer);
		ovlAdMapper = factory.config().getMapper(FStateOvlAdBuffer.class, buffer);
		ovlDevMapper = factory.config().getMapper(FStateOvlDevBuffer.class, buffer);
		islandMapper = factory.config().getMapper(FStateMIslandBuffer.class, buffer);
		systemBuffer = factory.config().getMapper(SystemBuffer.class, buffer);
	}
	
	public PrBufferServerImpl(CalcJob job) {	
		this(null, job);
	}
	
	@Override
	public void clear() {
		taskList.clear();
		fstateMapper.deleteAll();
		devMapper.deleteAll();
		ovlAdMapper.deleteAll();
		ovlDevMapper.deleteAll();
		islandMapper.deleteAll();
		systemBuffer.deleteAll();
	}

	public AQueue<RequestEstimate> getTaskList() {
		return taskList;
	}


	public void updateTasks(List<FState> fstates,
			List<FStateFDev> devs) {

		//fstateMapper.insertList(fstates);
		
		//devMapper.insertList(devs);
			
		Collections.sort(fstates, (a, b)->a.getFStateID().compareTo(b.getFStateID()));
		Collections.sort(devs, (a, b)->a.getFStateId().compareTo(b.getFStateId()));

		int i = 0; 
		int j = 0;
		List<RequestEstimate> tasks = new ArrayList<RequestEstimate>();
		for (; i < fstates.size() ; i++) {
			FState fstate = fstates.get(i);
			//设置评估标志为1(否则分析结果有误）
			fstate.setEstimated(1);
			RequestEstimate task = new RequestEstimate();
			task.setValue(String.valueOf(fstate.getFStateID()));
			task.getContent().getFState().add(fstate);
			while (j < devs.size()) {
				FStateFDev dev = devs.get(j);
				int cmp = dev.getFStateId().compareTo(fstate.getFStateID());
				if (cmp < 0 ) {
					j++;
				} else if (cmp == 0) {
					task.getContent().getFStateFDev().add(dev);
					j++;
				} else {
					break;
				}
			}
			
			tasks.add(task);
		}
		
		Collections.reverse(tasks);
		
		LOGGER.info("Upload tasks..., size = {}.", fstates.size());
		taskList.addAll(tasks);	
		
		//wait for finishing uploading tasks
		Thread t = new Thread(new Runnable() {
			
			@Override
			public void run() {
				while (true) {
					if (taskList.size() != fstates.size()) {
						try {
							Thread.sleep(10);
						} catch (InterruptedException e) {
							e.printStackTrace();
							break;
						}
						continue;
					}
					
					break;
				}
			}
		});
		
		t.start();
		try {
			t.join();
//			taskList.syncLeftCount();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		LOGGER.info("Task is uploaded :" +tasks.size());
	}
	
	@Override
	public void flushResult() {
		List<FState> fstates = new ArrayList<>();
		List<FStateMIsland> islands = new ArrayList<>();
		List<FStateOvlAd> ovlAds  = new ArrayList<>();
		List<FStateOvlDev> ovlDevs = new ArrayList<>();
		int size = localResultList.size();
		LOGGER.info("resultList size : "+size);
		
		for (ResponseEstimate result : localResultList)  {
 			Content c = result.getContent();	
 			
 	 		
 	 		if (c.getFState() != null && !c.getFState().isEmpty()) {
 	 			fstates.addAll(c.getFState());
 	 		} else {
 	 			LOGGER.error("find no fstate in result : "+result);
 	 		}
 	 		
 	 		if (c.getFStateMIsland() != null && !c.getFStateMIsland().isEmpty()) {
 	 			islands.addAll(c.getFStateMIsland());
 	 		}
 	 		
 	 		if (c.getFStateOvlAd() != null && !c.getFStateOvlAd().isEmpty()) {
 	 			ovlAds.addAll(c.getFStateOvlAd());
 	 		}
 	 		
 	 		if (c.getFStateOvlDev() != null && !c.getFStateOvlDev().isEmpty()) {
 	 			ovlDevs.addAll(c.getFStateOvlDev());
 	 		} 			
 		}
 		
 		fstateMapper.insertList(fstates);
 		LOGGER.info("flush fstates size : "+fstates.size());
 		

 		islandMapper.insertList(islands);
 		LOGGER.info("flush islands size : "+islands.size());
 		

 		ovlAdMapper.insertList(ovlAds);
 		LOGGER.info("flush ovlAds size : "+ovlAds.size());
 		

 		ovlDevMapper.insertList(ovlDevs);
 		LOGGER.info("flush ovlDevs size : "+ovlDevs.size());
 		
 		
 		resultSemaphore.release(size);
 		LOGGER.info("result semaphore release : "+size);
	}
	
	@Override
	public void waitForFinished(long waitTime, TimeUnit unit) throws InterruptedException {
		resultSemaphore.tryAcquire(job.getMaxStep(), waitTime, unit);
	}
	
	@Override
	public void saveResult(ResponseEstimate result) {
		localResultList.offer(result);	
	}

	@Override
	public List<FStateOvlDev> getAllOvlDevs() {
		return ovlDevMapper.findAll();
	}

	@Override
	public List<FStateOvlAd> getOvlAds() {
		return ovlAdMapper.findAll();
	}

	@Override
	public List<FState> getFStates() {
		return fstateMapper.findAll();
	}

	@Override
	public List<FStateMIsland> getIslands() {
		return islandMapper.findAll();
	}

	@Override
	public void saveSystems(List<System> systems) {
		systemBuffer.insertList(systems);
	}

	@Override
	public int getResultSize() {
		return localResultList.size();
	}



//	public RSemaphore getResultSemaphore() {
//		return resultSemaphore;
//	}
//



}
