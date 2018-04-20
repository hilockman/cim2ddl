package com.znd.reliability.server;

import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.reliability.model.ResponseEstimate;

public interface BufferServer {

	void clear();
	
	void updateTasks(List<FState> fstates, List<FStateFDev> devs);

	void saveResult(ResponseEstimate result);

	List<FStateOvlDev> getAllOvlDevs();

	List<FStateOvlAd> getOvlAds();

	List<FState> getFStates();

	List<FStateMIsland> getIslands();
}
