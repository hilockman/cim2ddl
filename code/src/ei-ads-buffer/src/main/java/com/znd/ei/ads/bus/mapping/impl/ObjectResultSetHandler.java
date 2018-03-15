package com.znd.ei.ads.bus.mapping.impl;

import java.util.List;

import com.znd.ei.ads.bus.mapping.ResultSet;
import com.znd.ei.ads.bus.mapping.ResultSetHandler;

public class ObjectResultSetHandler<Object> implements ResultSetHandler<Object> {
	private Class<?> type;
	
	public ObjectResultSetHandler(Class<?> type) {
		this.type = type;
	}
	@Override
	public List<Object> handle(ResultSet resultSet) {
		// TODO Auto-generated method stub
		return null;
	}

}
