package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;

@Component
public class FStateFDevDao extends AbstractTableOperations<FStateFDev> {

	@Autowired
	public FStateFDevDao(DbEntryOperations pROps) {
		super(FStateFDev.class, pROps);
	}

}
