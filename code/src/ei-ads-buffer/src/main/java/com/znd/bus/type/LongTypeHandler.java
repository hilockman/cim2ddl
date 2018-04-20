package com.znd.bus.type;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class LongTypeHandler implements TypeHandler<Long> {

	@Override
	public void setParameter(Statement ps, int i, Long parameter) {
		ps.set(i, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, Long parameter) {
		ps.set(key, parameter == null  ? null : String.valueOf(parameter));
	}

	@Override
	public Long getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null || value.equalsIgnoreCase("null") ? null : Long.valueOf(value);
	}

	@Override
	public Long getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null || value.equalsIgnoreCase("null")? null : Long.valueOf(value);
	}

}
