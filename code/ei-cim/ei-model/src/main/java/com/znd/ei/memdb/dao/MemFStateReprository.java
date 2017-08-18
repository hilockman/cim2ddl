package com.znd.ei.memdb.dao;

import org.springframework.stereotype.Repository;

import com.znd.ei.computing.domain.FState;

@Repository
public class MemFStateReprository extends AbstractMemTableRepository<FState> {

	public MemFStateReprository() {
		super(FState.class);
		// TODO Auto-generated constructor stub
	}

}
