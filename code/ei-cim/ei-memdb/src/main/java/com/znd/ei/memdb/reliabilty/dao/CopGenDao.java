package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.CopGen;
@Component
public class CopGenDao  extends AbstractTableOperations<CopGen> {

	@Autowired
	public CopGenDao(DbEntryOperations pROps) {
		super(CopGen.class, pROps);
	}
}