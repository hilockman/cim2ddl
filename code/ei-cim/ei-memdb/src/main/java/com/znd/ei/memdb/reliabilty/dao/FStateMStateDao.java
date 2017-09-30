package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.FStateMState;

@Component
public class FStateMStateDao extends AbstractTableOperations<FStateMState> {

	@Autowired
	public FStateMStateDao(DbEntryOperations pROps) {
		super(FStateMState.class, pROps);
	}


}
