package com.znd.bus.type;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class IntegerTypeHandler implements TypeHandler<Integer> {

	@Override
	public void setParameter(Statement ps, int i, Integer parameter) {
		ps.set(i, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, Integer parameter) {
		ps.set(key, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public Integer getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null  || value.equalsIgnoreCase("null") ? null : Integer.valueOf(value);
	}

	@Override
	public Integer getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null || value.equalsIgnoreCase("null") ? null : Integer.valueOf(value);
	}

}
