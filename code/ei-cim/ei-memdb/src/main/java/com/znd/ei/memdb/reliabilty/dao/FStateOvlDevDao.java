package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
@Component
public class FStateOvlDevDao extends AbstractTableOperations<FStateOvlDev> {

	@Autowired
	public FStateOvlDevDao(DbEntryOperations pROps) {
		super(FStateOvlDev.class, pROps);
	}

}