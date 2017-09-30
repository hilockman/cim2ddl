package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.CopTable;

@Component
public class CopTableDao  extends AbstractTableOperations<CopTable> {

	@Autowired
	public CopTableDao(DbEntryOperations pROps) {
		super(CopTable.class, pROps);
	}
}
