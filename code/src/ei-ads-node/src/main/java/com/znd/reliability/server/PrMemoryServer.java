package com.znd.reliability.server;

import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.ei.memdb.reliabilty.domain.System;
public interface PrMemoryServer {

	List<FState> findAllFStates();
	
	List<FStateFDev> findAllFStateFDevs();
	
	List<System> findAllSystems();

	void clear();

	void saveOvlDevs(List<FStateOvlDev> ovlDevs);

	void saveOvlAds(List<FStateOvlAd> ovlAds);

	void saveFStates(List<FState> fstates);

	void saveIslands(List<FStateMIsland> islands);
	
	void clearFState();
	
	void clearFStateFDev();
}
