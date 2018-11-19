package com.znd.reliability.utils;

import com.znd.ads.model.dto.PRAdequacySetting;

/**
 * Send command to State Estimate Server.  
 * @author wangheng
 *
 */
public interface StateEstimateServer {

	void exec(PRAdequacySetting setting);
}
	