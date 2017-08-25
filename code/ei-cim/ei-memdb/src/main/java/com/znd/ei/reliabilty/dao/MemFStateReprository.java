package com.znd.ei.reliabilty.dao;

import org.springframework.stereotype.Repository;

import com.znd.ei.reliabilty.base.AbstractMemTableRepository;
import com.znd.ei.reliabilty.domain.FState;

@Repository
public class MemFStateReprository extends AbstractMemTableRepository<FState> {

	public MemFStateReprository() {
		super(FState.class);
		// TODO Auto-generated constructor stub
	}

}
