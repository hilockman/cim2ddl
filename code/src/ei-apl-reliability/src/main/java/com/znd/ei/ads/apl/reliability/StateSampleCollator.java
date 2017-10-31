package com.znd.ei.ads.apl.reliability;

import static com.znd.ei.ads.apl.reliability.AppUtil.clearAndSave;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.redisson.api.mapreduce.RCollator;

import com.znd.ei.ads.AdsUtils;
import com.znd.ei.ads.apl.reliability.bean.ReliabilityIndexResult;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.ads.config.StateEstimateConfig;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;

public class StateSampleCollator implements
		RCollator<Integer, StateEstimateResult, ReliabilityIndexResult> {

	public static <T> Class<T> getType(List<T> records) {
		Class<T> clazz = null;
		try {
			 clazz = (Class<T>) records.get(0).getClass();
			} catch (SecurityException e) {
				e.printStackTrace();
			}	
		
		return clazz;
	}
	
	
	public static void main(String [] args) {
		List<FState> fstates = new ArrayList<FState>();
		fstates.add(new FState());
		System.out.println(StateSampleCollator.getType(fstates).getName());
		//System.out.println(StateSampleCollator.<FStateMIsland>getType().getName());
	}
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 9455435232543251L;

	public static int count = 0;
	


	@Override
	public ReliabilityIndexResult collate(
			Map<Integer, StateEstimateResult> resultMap) {
		synchronized (AdsUtils.shareMemoryLocker) {
			System.out.println(String.format(
					"ReliabilityIndexResult.collate index = %s", count++));

			// TODO : 
			ReliabilityApl apl = ReliabilityApl.INSTANCE;
			
			System.out.println("write StateEstimateResults to local share memory");
		
			Set<Entry<Integer, StateEstimateResult>> s = resultMap.entrySet();
			List<FState> fstates = new ArrayList<>();
			List<FStateFDev> fstateDevs = new ArrayList<>();
			List<FStateMIsland> mislands = new ArrayList<FStateMIsland>();
			List<FStateOvlDev> ovlDevs = new ArrayList<FStateOvlDev>();
			List<FStateOvlAd> ovlAds = new ArrayList<FStateOvlAd>();
			
			for (Entry<Integer, StateEstimateResult> e : s) {
				StateEstimateResult rt = e.getValue();
				fstates.add(rt.getState());
				if (rt.getDevs() != null);
					fstateDevs.addAll(rt.getDevs());
				if (rt.getMislands() != null)
					mislands.addAll(rt.getMislands());
				if (rt.getOvlDevs() != null)
					ovlDevs.addAll(rt.getOvlDevs());
				if (rt.getOvlAds() != null) {
					ovlAds.addAll(rt.getOvlAds());
				}				
			}
			
			
			clearAndSave(fstates, apl.fStateDao);
			clearAndSave(fstateDevs, apl.fStateFDevDao);
			clearAndSave(mislands, apl.mIslandDao);
			clearAndSave(ovlDevs, apl.ovlDevDao);
			clearAndSave(ovlAds, apl.ovlAdDao);
					
			// TODO : call reliability index;
			ReliabilityApl.callReliabilityIndex(new StateEstimateConfig());
			Iterable<com.znd.ei.memdb.reliabilty.domain.System> results = apl.systemDao.findAll();
			
			ReliabilityIndexResult result = new ReliabilityIndexResult();
			if (results != null) {
				Iterator<com.znd.ei.memdb.reliabilty.domain.System> it = results.iterator();
				while (it.hasNext()) {
					result.setSys(it.next());
					break;
				}
			}
			return result;
		}
	}

}
