package com.znd.reliability.server;

import java.util.List;
import java.util.concurrent.TimeUnit;

import com.znd.bus.task.AQueue;
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
	
	int getResultSize();

	/**
	 * 存入所有结果
	 * @param semophore 
	 */
	void flushResult();
	
    /**
     * 等待所有结果上传完成
     */
    void waitForFinished(long waitTime, TimeUnit unit) throws InterruptedException;
	
	List<FStateOvlDev> getAllOvlDevs();

	List<FStateOvlAd> getOvlAds();

	List<FState> getFStates();

	List<FStateMIsland> getIslands();
	
	AQueue<RequestEstimate> getTaskList();
	

	void saveSystems(List<System> systems);
	
//    RSemaphore getResultSemaphore();
    

}
