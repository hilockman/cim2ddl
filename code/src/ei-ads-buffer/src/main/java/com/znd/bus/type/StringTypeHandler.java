package com.znd.bus.type;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class StringTypeHandler implements TypeHandler<String> {

	@Override
	public void setParameter(Statement ps, int i, String parameter) {
		ps.set(i, parameter);
	}

	@Override
	public void setParameter(Statement ps, String key, String parameter) {
		ps.set(key, parameter);
	}

	@Override
	public String getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return value == null  || value.equalsIgnoreCase("null") ? null : value;
	}

	@Override
	public String getResult(ResultSet rs, int columnIndex) {
		String value  = rs.get(columnIndex);
		
		return value == null  || value.equalsIgnoreCase("null") ? null : value;
	}

}
