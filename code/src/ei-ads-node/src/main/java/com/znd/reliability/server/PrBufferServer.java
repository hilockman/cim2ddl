package com.znd.reliability.server;

import java.util.List;

import com.znd.bus.task.TaskQueue;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.ei.memdb.reliabilty.domain.System;
import com.znd.reliability.model.RequestEstimate;
import com.znd.reliability.model.ResponseEstimate;

public interface PrBufferServer {

	void clear();
	
	void updateTasks(List<FState> fstates, List<FStateFDev> devs);

	void saveResult(ResponseEstimate result);

	/**
	 * 存入所有结果
	 */
	void flushResult();
	
	List<FStateOvlDev> getAllOvlDevs();

	List<FStateOvlAd> getOvlAds();

	List<FState> getFStates();

	List<FStateMIsland> getIslands();
	
	TaskQueue<RequestEstimate> getTaskList();

	void saveSystems(List<System> systems);
	
	
}
