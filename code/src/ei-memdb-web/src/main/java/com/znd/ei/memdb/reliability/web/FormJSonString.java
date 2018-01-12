package com.znd.ei.memdb.reliability.web;

import java.util.Iterator;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.Utils;
import com.znd.ei.memdb.MemIndexable;
import com.znd.ei.memdb.MemTableOperations;
import com.znd.ei.memdb.reliabilty.dao.FStateDao;
import com.znd.ei.memdb.reliabilty.dao.FStateFDevDao;
import com.znd.ei.memdb.reliabilty.dao.FStateMIslandDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlAdDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlDevDao;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
/**
 * test for form json string sample
 * @author ThinkPad
 *
 */
@Component
public class FormJSonString {
	public interface FStateGetter<T> {
		Integer getState(T o);
	}

	@Autowired
	FStateDao fStateDao;

	@Autowired
	FStateFDevDao fStateFDevDao;

	@Autowired
	FStateMIslandDao mIslandDao;

	@Autowired
	FStateOvlAdDao ovlAdDao;

	@Autowired
	FStateOvlDevDao ovlDevDao;

	private final static Integer state_indexes[] = {15, 5912, 6069 };

	public void test() {
		Integer state_index = state_indexes[0];

		Iterable<FState> fstatIter = fStateDao.findAll();
		Iterator<FState> fstateit = fstatIter.iterator();
		StateEstimateResult result = new StateEstimateResult();
		while (fstateit.hasNext()) {
			FState state = fstateit.next();

			if (state.getMemIndex().equals(state_index)) {

				result.setState(state);

			}

		}

		System.out.println("FState :\n" + Utils.toJSon(result.getState()));


		
		findByIndex(fStateFDevDao, result.getDevs(), state_index, (FStateFDev o)-> { return o.getFStateNo();});
		findByIndex(mIslandDao, result.getMislands(), state_index, (FStateMIsland o)-> { return o.getFStateNo();});
		findByIndex(ovlAdDao, result.getOvlAds(), state_index, (FStateOvlAd o)-> { return o.getFStateNo();});
		findByIndex(ovlDevDao, result.getOvlDevs(), state_index, (FStateOvlDev o)-> { return o.getFStateNo();});
		
		System.out.println("StateEstimateResult : \n" + Utils.toJSon(result));
	}

	<T extends MemIndexable> void findByIndex(MemTableOperations<T> dao, List<T> selected, Integer state_index, FStateGetter<T> g) {
		Iterable<T> islandIter = dao.findAll();
		Iterator<T> islandIt = islandIter.iterator();
		while (islandIt.hasNext()) {
			T island = islandIt.next();
			if (g.getState(island).equals(state_index)) {
				selected.add(island);
			}
		}
	}
}
