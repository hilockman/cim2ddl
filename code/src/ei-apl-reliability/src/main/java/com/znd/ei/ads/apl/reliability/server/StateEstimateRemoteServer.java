package com.znd.ei.ads.apl.reliability.server;

import com.znd.ei.ads.apl.reliability.bean.DataReady;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.memdb.reliabilty.domain.FState;

public interface StateEstimateRemoteServer {

	String dataReady(DataReady settting);
	

	StateEstimateResult execute(FState state);

	
	
}
