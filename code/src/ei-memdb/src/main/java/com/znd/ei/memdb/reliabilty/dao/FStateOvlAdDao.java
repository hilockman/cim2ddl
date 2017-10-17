package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;

@Component
public class FStateOvlAdDao extends AbstractTableOperations<FStateOvlAd> {

	@Autowired
	public FStateOvlAdDao(DbEntryOperations pROps) {
		super(FStateOvlAd.class, pROps);
	}

}
