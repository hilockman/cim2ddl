package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;

@Component
public class FStateMIslandDao extends AbstractTableOperations<FStateMIsland> {

	@Autowired
	public FStateMIslandDao(DbEntryOperations pROps) {
		super(FStateMIsland.class, pROps);
	}

}
