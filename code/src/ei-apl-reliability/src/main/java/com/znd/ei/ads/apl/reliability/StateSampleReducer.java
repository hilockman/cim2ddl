package com.znd.ei.ads.apl.reliability;

import java.util.Iterator;

import org.redisson.api.mapreduce.RReducer;

import com.znd.ei.ads.AdsUtils;

public class StateSampleReducer implements
		RReducer<Integer, StateEstimateResult> {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1043243453245L;

	private static int count = 0;

	@Override
	public StateEstimateResult reduce(Integer reducedKey,
			Iterator<StateEstimateResult> iter) {
		synchronized (AdsUtils.shareMemoryLocker) {
			System.out.println(String.format(
					"StateSampleReducer.reduce index = %s, reducedKey = %s",
					count++, reducedKey));

			StateEstimateResult result = null;
			if (iter.hasNext()) {
				result = iter.next();
			} else
				return null;
			
			

			// TODO : write state sample to share memory
			
			// TODO : call state estimate server;
			ReliabilityApl.callStateEstimate(result.getState(), new StateEstimateConfig());
			return result;
		}
	}

}