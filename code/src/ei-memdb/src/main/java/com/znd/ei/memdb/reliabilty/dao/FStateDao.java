package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.FState;

@Component
public class FStateDao extends AbstractTableOperations<FState> {

	@Autowired
	public FStateDao(DbEntryOperations pROps) {
		super(FState.class, pROps);
	}

}
