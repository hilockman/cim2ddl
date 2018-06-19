package com.znd.ei.ads.apl.reliability.server;

import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.ei.ads.apl.reliability.ReliabilityNetBuffer;

/**
 * Send command to State Estimate Server.  
 * @author wangheng
 *
 */
public interface StateEstimateServer {

	void exec(ReliabilityNetBuffer buffer, PRAdequacySetting setting);
	
	
}
	