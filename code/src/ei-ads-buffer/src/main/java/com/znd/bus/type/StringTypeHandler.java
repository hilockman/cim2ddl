package com.znd.bus.type;

import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.StatementException;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class StringTypeHandler implements TypeHandler<String> {

	@Override
	public void setParameter(Statement ps, int i, String parameter) throws StatementException {
		ps.set(i, parameter);
	}

	@Override
	public void setParameter(Statement ps, String key, String parameter) throws StatementException {
		ps.set(key, parameter);
	}

	@Override
	public String getResult(ResultSet rs, String columnName) throws BindingException {
		String value = rs.get(columnName);
		return value == null  || value.equalsIgnoreCase("null") ? null : value;
	}

	@Override
	public String getResult(ResultSet rs, int columnIndex) throws BindingException {
		String value  = rs.get(columnIndex);
		
		return value == null  || value.equalsIgnoreCase("null") ? null : value;
	}

}
