package com.znd.ei.ads.apl.reliability.server;

import com.znd.ei.ads.apl.reliability.ReliabilityNetBuffer;
import com.znd.ei.ads.config.PRAdequacySetting;

/**
 * Send command to State Estimate Server.  
 * @author wangheng
 *
 */
public interface StateEstimateServer {

	void exec(ReliabilityNetBuffer buffer, PRAdequacySetting setting);
	
	
}
	