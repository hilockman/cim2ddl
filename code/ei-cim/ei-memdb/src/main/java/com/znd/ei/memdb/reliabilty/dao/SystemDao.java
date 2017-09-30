package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.System;
@Component
public class SystemDao  extends AbstractTableOperations<System> {

	@Autowired
	public SystemDao(DbEntryOperations pROps) {
		super(System.class, pROps);
	}
}