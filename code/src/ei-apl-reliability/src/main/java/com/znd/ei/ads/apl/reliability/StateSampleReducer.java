package com.znd.ei.ads.apl.reliability;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.redisson.api.mapreduce.RReducer;

import com.znd.ei.ads.AdsUtils;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.ads.config.StateEstimateConfig;
import com.znd.ei.memdb.MemIndexable;
import com.znd.ei.memdb.MemTableRepository;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;

public class StateSampleReducer implements
		RReducer<Integer, StateEstimateResult> {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1043243453245L;

	@Override
	public StateEstimateResult reduce(Integer reducedKey,
			Iterator<StateEstimateResult> iter) {
		synchronized (AdsUtils.shareMemoryLocker) {
			System.out.println(String.format(
					"StateSampleReducer.reduce reducedKey = %s", reducedKey));

			StateEstimateResult result = null;
			if (iter.hasNext()) {
				result = iter.next();
			} else
				return null;

			// TODO : write state sample to share memory
			ReliabilityApl apl = ReliabilityApl.INSTANCE;
			
			clearTable(apl.fStateDao);
			clearTable(apl.fStateFDevDao);
			clearTable(apl.mIslandDao);
			clearTable(apl.ovlDevDao);
			clearTable(apl.ovlAdDao);
			
			int statIndex = result.getState().getMemIndex();
			
			apl.fStateDao.saveOrUpdate(result.getState());
			List<FStateFDev> devs = result.getDevs();
			for (FStateFDev dev  : devs) {
				dev.setFStateNo(0);
			}
			apl.fStateFDevDao.saveOrUpdate(result.getDevs());
			
			
			// TODO : call state estimate;
			ReliabilityApl.callStateEstimate(result.getState(),
					new StateEstimateConfig());

					
			result.setState(load(apl.fStateDao, statIndex));
			
			result.setDevs(loadAll(apl.fStateFDevDao, statIndex));
			result.setMislands(loadAll(apl.mIslandDao, statIndex));
			result.setOvlAds(loadAll(apl.ovlAdDao, statIndex));
			result.setOvlDevs(loadAll(apl.ovlDevDao, statIndex));
			
			return result;
		}
	}
	
	public static <T> void clearTable( MemTableRepository<T> dao)
	{
		dao.deleteAll();
	}
	
	private <T extends MemIndexable> T load(MemTableRepository<T> dao, Integer statIndex) {
		Iterable<T> devIter = dao.findAll();
		Iterator<T> devIt = devIter.iterator();
		
		if (devIt.hasNext()) {
			T rec = devIt.next();
			rec.setMemIndex(statIndex);
			return rec;			
		}
		return null;
	}
	
	private <T extends MemIndexable> List<T> loadAll(MemTableRepository<T> dao, Integer statIndex) {
		Iterable<T> devIter = dao.findAll();
		Iterator<T> devIt = devIter.iterator();

		List<T> records = new ArrayList<T>();
		while (devIt.hasNext()) {
			T rec = devIt.next();
			rec.setMemIndex(statIndex);
			records.add(rec);			
		}
		return records;
	}

}