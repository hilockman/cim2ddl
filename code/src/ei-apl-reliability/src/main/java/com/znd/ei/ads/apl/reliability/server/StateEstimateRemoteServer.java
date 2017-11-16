package com.znd.ei.ads.apl.reliability.server;

import java.util.concurrent.Callable;
import java.util.concurrent.Future;

import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.memdb.reliabilty.domain.FState;

public interface StateEstimateRemoteServer {

	void dataReady();
	
	Future<StateEstimateResult> calc(FState fstate);

	Future<StateEstimateResult> submit(Callable<StateEstimateResult> c);
	
	boolean isBusy();
	
	
}
