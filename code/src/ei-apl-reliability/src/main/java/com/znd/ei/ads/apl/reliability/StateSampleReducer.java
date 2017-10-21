package com.znd.ei.ads.apl.reliability;
import java.util.Iterator;
import java.util.List;

import org.redisson.api.mapreduce.RReducer;

import com.znd.ei.ads.AdsUtils;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateConfig;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.memdb.MemTableRepository;
import com.znd.ei.memdb.reliabilty.domain.FState;
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
			
			AppUtil.clearTable(apl.fStateDao);
			AppUtil.clearTable(apl.fStateFDevDao);
			AppUtil.clearTable(apl.mIslandDao);
			AppUtil.clearTable(apl.ovlDevDao);
			AppUtil.clearTable(apl.ovlAdDao);
			
			int statIndex = result.getState().getMemIndex();
			
			apl.fStateDao.saveOrUpdate(result.getState());
			List<FStateFDev> devs = result.getDevs();
			for (FStateFDev dev  : devs) {
				dev.setFState(0);
			}
			apl.fStateFDevDao.saveOrUpdate(result.getDevs());
			
			
			// TODO : call state estimate;
			ReliabilityApl.callStateEstimate(result.getState(),
					new StateEstimateConfig());

			
			Iterable<FState> stateIter = apl.fStateDao.findAll();
			Iterator<FState> stateIt = stateIter.iterator();
			if (stateIt.hasNext()) {
				FState state = stateIt.next();
				state.setMemIndex(statIndex);
				result.setState(state);
			}
			
			Iterable<FStateFDev> devIter = apl.fStateFDevDao.findAll();
			Iterator<FStateFDev> devIt = devIter.iterator();
			result.getDevs().clear();
			while (devIt.hasNext()) {
				FStateFDev rec = devIt.next();
				rec.setMemIndex(statIndex);
				result.getDevs().add(rec);			
			}
			
			
			return result;
		}
	}
	
//	class MemIndexable {
//		Integer index;
//		
//		
//		void setMemIndex(Integer i)
//		{
//			index = i;
//		}
//	}
	
	interface MemIndexable {
		void setMemIndex(Integer i);
	}
	
	private <T extends MemIndexable> void load(List<T> records, MemTableRepository<T> dao, Integer statIndex) {
		Iterable<T> devIter = dao.findAll();
		Iterator<T> devIt = devIter.iterator();
		records.clear();
		while (devIt.hasNext()) {
			T rec = devIt.next();
			rec.setMemIndex(statIndex);
			records.add(rec);			
		}
	}

}