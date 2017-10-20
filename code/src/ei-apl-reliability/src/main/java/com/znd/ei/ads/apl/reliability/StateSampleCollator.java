package com.znd.ei.ads.apl.reliability;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.redisson.api.mapreduce.RCollator;

import com.znd.ei.ads.AdsUtils;
import com.znd.ei.memdb.reliabilty.dao.FStateDao;
import com.znd.ei.memdb.reliabilty.dao.FStateFDevDao;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;

public class StateSampleCollator implements
		RCollator<Integer, StateEstimateResult, ReliabilityIndexResult> {

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

			// TODO : write StateEstimateResult to local share memory

			Set<Entry<Integer, StateEstimateResult>> s = resultMap.entrySet();
			List<FState> fstates = new ArrayList<>();
			List<FStateFDev> fstateDevs = new ArrayList<>();
			for (Entry<Integer, StateEstimateResult> e : s) {
				StateEstimateResult rt = e.getValue();
				fstates.add(rt.getState());
				fstateDevs.addAll(rt.getDevs());
			}
			FStateDao dao = ReliabilityApl.INSTANCE.fStateDao;
			dao.deleteAll();
			dao.saveOrUpdate(fstates);

			FStateFDevDao defDao = ReliabilityApl.INSTANCE.fStateFDevDao;
			defDao.deleteAll();
			defDao.saveOrUpdate(fstateDevs);
			// TODO : call reliability index;

			ReliabilityIndexResult result = null;
			return result;
		}
	}

}
