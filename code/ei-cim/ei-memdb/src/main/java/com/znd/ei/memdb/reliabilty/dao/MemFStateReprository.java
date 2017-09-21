package com.znd.ei.memdb.reliabilty.dao;

import org.springframework.stereotype.Repository;

import com.znd.ei.memdb.dao.AbstractMemTableRepository;
import com.znd.ei.memdb.reliabilty.domain.FState;

@Repository
public class MemFStateReprository extends AbstractMemTableRepository<FState> {

	public MemFStateReprository() {
		super(FState.class);
		// TODO Auto-generated constructor stub
	}

}
