package com.znd.reliability.server.impl;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.CreateFlag;
import com.znd.bus.task.TaskQueue;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.exception.AplException;
import com.znd.reliability.buffer.FStateFDevBuffer;
import com.znd.reliability.buffer.FStateMIslandBuffer;
import com.znd.reliability.buffer.FStateBuffer;
import com.znd.reliability.buffer.FStateOvlAdBuffer;
import com.znd.reliability.buffer.FStateOvlDevBuffer;
import com.znd.reliability.model.RequestEstimate;
import com.znd.reliability.model.ResponseEstimate;
import com.znd.reliability.model.ResponseEstimate.Content;
import com.znd.reliability.server.BufferServer;

public class BufferServerImpl implements BufferServer {

	private static final Logger LOGGER = LoggerFactory
			.getLogger(BufferServerImpl.class);
	
	private final TaskQueue<RequestEstimate> taskList;
	private final FStateBuffer fstateMapper;
	private final FStateFDevBuffer devMapper;
	private final FStateOvlAdBuffer ovlAdMapper;
	private final FStateOvlDevBuffer ovlDevMapper;
	private final FStateMIslandBuffer islandMapper;
	
	public static final String TYPE_PACKAGE = "com.znd.ei.memdb.reliabilty.domain";
	public static final String MAPPER_PACKAGE = "com.znd.reliability.buffer";
	
	public BufferServerImpl(Buffer parentBuffer, CalcJob job) {
	
		if (job == null || job.getModelId() == null || job.getModelId().isEmpty()) {
			throw new AplException("job is null or job name is empty :"+job);
		}
		String modelName = job.getModelId();
		BufferConfig config = parentBuffer.getConfig();
		TaskQueue<RequestEstimate> taskList = config.getTaskList(job.getModelId()+":task:"+job.getId());
		if (taskList == null)
			throw new AplException("Cann't create task list : "+job.getId());
		
		this.taskList = taskList;
		BufferFactoryBuilder builder  = new BufferFactoryBuilder();
		
		BufferFactory factory = builder.build(modelName, CreateFlag.UPDATE, TYPE_PACKAGE, MAPPER_PACKAGE, config);
		Buffer buffer = factory.openSession();
			
		fstateMapper = factory.config().getMapper(FStateBuffer.class, buffer);
		devMapper = factory.config().getMapper(FStateFDevBuffer.class, buffer);
		ovlAdMapper = factory.config().getMapper(FStateOvlAdBuffer.class, buffer);
		ovlDevMapper = factory.config().getMapper(FStateOvlDevBuffer.class, buffer);
		islandMapper = factory.config().getMapper(FStateMIslandBuffer.class, buffer);
	}
	
	public BufferServerImpl(CalcJob job) {	
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
	}

	public TaskQueue<RequestEstimate> getTaskList() {
		return taskList;
	}

//	public FStateMapper getFstateMapper() {
//		return fstateMapper;
//	}
//
//	public FStateOvlAdMapper getFstateOvlAdMapper() {
//		return ovlAdMapper;
//	}
//
//	public FStateOvlDevMapper getFstateOvlDevMapper() {
//		return ovlDevMapper;
//	}
//
//	public FStateMIslandMapper getFstateMIsland() {
//		return mIslandMapper;
//	}

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
			taskList.syncLeftCount();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		LOGGER.info("Task is uploaded :" +taskList.size());
	}

	@Override
	public void saveResult(ResponseEstimate result) {
		  	
 		Content c = result.getContent();
 		List<FState> fstates = c.getFState();
 		if (fstates != null && !fstates.isEmpty()) {
 			fstateMapper.insertList(fstates);
 		}
 		
 		List<FStateMIsland> islands = c.getFStateMIsland();
 		if (islands != null && !islands.isEmpty()) {
 			islandMapper.insertList(islands);
 		}
 		
 		 List<FStateOvlAd> ovlAds = c.getFStateOvlAd();
 		if (ovlAds != null && !ovlAds.isEmpty()) {
 			ovlAdMapper.insertList(ovlAds);
 		}
 		
 		List<FStateOvlDev> ovlDevs = c.getFStateOvlDev();
 		if (ovlDevs != null && !ovlDevs.isEmpty()) {
 			ovlDevMapper.insertList(ovlDevs);
 		}
 		
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
}
