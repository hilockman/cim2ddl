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
		return rs.get(columnName);
	}

	@Override
	public String getResult(ResultSet rs, int columnIndex) {
		return rs.get(columnIndex);
	}

}
