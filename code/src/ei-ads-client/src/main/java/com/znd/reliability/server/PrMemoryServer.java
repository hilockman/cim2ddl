package com.znd.reliability.server;

import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;

public interface PrMemoryServer {

	List<FState> findAllFStates();
	
	List<FStateFDev> findAllFStateFDevs();

	void clear();

	void saveOvlDevs(List<FStateOvlDev> ovlDevs);

	void saveOvlAds(List<FStateOvlAd> ovlAds);

	void saveFatates(List<FState> fstates);

	void saveIslands(List<FStateMIsland> islands);
}
