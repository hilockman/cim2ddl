package com.znd.reliability.server.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.reliabilty.dao.FStateDao;
import com.znd.ei.memdb.reliabilty.dao.FStateFDevDao;
import com.znd.ei.memdb.reliabilty.dao.FStateMIslandDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlAdDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlDevDao;
import com.znd.ei.memdb.reliabilty.dao.SystemDao;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.reliability.server.PrMemoryServer;

@Component
public class PrMemoryServerImpl implements PrMemoryServer {

	@Autowired
	private FStateDao fStateDao;

	@Autowired
	private FStateFDevDao fStateFDevDao;

	@Autowired
	private FStateMIslandDao mIslandDao;

	@Autowired
	private FStateOvlAdDao ovlAdDao;

	@Autowired
	private FStateOvlDevDao ovlDevDao;

	@Autowired
	private SystemDao systemDao;

	@Override
	public List<FState> findAllFStates() {
		return fStateDao.findAll();
	}

	@Override
	public List<FStateFDev> findAllFStateFDevs() {
		return fStateFDevDao.findAll();
	}

	@Override
	public void clear() {
		 ovlAdDao.deleteAll();
		 ovlDevDao.deleteAll();
		 fStateDao.deleteAll();
		 mIslandDao.deleteAll();
	}

	@Override
	public void saveOvlDevs(List<FStateOvlDev> ovlDevs) {
		ovlDevDao.saveOrUpdate(ovlDevs);
	}

	@Override
	public void saveOvlAds(List<FStateOvlAd> ovlAds) {
		ovlAdDao.saveOrUpdate(ovlAds);
	}

	@Override
	public void saveFStates(List<FState> fstates) {
		fStateDao.saveOrUpdate(fstates);
	}

	@Override
	public void saveIslands(List<FStateMIsland> islands) {
		mIslandDao.saveOrUpdate(islands);
	}

	@Override
	public void clearFState() {
		fStateDao.deleteAll();
	}

	@Override
	public void clearFStateFDev() {
		fStateFDevDao.deleteAll();
	}
}
