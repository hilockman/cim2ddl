package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.dao.AbstractMemTableRepository;
import com.znd.ei.memdb.dao.MemTableOperations;
import com.znd.ei.memdb.reliabilty.domain.FState;

@Component
public class FStateRepository extends AbstractMemTableRepository<FState> {

	@Autowired
	public FStateRepository(MemTableOperations pROps) {
		super(FState.class, pROps);
	}

}
