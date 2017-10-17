package com.znd.ei.memdb.bpa.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.bpa.domain.BpaDat_ACLine;

@Component
public class ACLineRepository extends AbstractTableOperations<BpaDat_ACLine> {

	@Autowired
	public ACLineRepository(DbEntryOperations bPAOps) {
		super(BpaDat_ACLine.class, bPAOps);
	}

}