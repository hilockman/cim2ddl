package com.znd.bus.mapping.impl;

import java.util.List;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.mapping.ResultSetHandler;

public class RawArrayResultHandler<Object> implements ResultSetHandler<Object> {

	@Override
	public List<Object> handle(ResultSet rs) {
		//System.out.println(">>>>>>>>>>>>>>>>>>RawArrayResultHandler.handle");
		return (List<Object>) rs.getResults();
	}


}
