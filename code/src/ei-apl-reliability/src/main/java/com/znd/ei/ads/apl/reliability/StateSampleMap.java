package com.znd.ei.ads.apl.reliability;

import org.redisson.api.mapreduce.RCollector;
import org.redisson.api.mapreduce.RMapper;

import com.znd.ei.ads.AdsUtils;
import com.znd.ei.memdb.reliabilty.dao.FStateDao;

public class StateSampleMap  implements RMapper<Integer, StateSampleTask, Integer, StateEstimateResult> {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1999434204321L;

	public static int count = 0;
	@Override
    public void map(Integer key, StateSampleTask value, RCollector<Integer, StateEstimateResult> collector) {
		synchronized(AdsUtils.shareMemoryLocker)  {
			System.out.println(String.format("StateSampleMap.map index = %s, key = %s, value = %s", count++, key, value));
			FStateDao fstateDao = ReliabilityApl.INSTANCE.fStateDao;
			StateEstimateResult result = new StateEstimateResult();
			result.setState(value.getState());
			result.setDevs(value.getDevs());
	        collector.emit(key, result);	
		}	
    }
    
}