package com.znd.ei.ads.apl.reliability.server;

import com.znd.ei.ads.apl.reliability.ReliabilityCaseBuffer;
import com.znd.ei.ads.config.PRAdequacySetting;

public interface StateEstimateRemoteServer {

	void exec(ReliabilityCaseBuffer buffer, PRAdequacySetting setting);
	
	
}
	