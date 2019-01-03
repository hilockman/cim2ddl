package com.znd.bus.type;

import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.StatementException;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class BooleanTypeHandler implements TypeHandler<Boolean> {

	@Override
	public void setParameter(Statement ps, int i, Boolean parameter) throws StatementException {
		ps.set(i, parameter == null ? null : String.valueOf(parameter ? "true" : "false"));
	}
	
	@Override
	public void setParameter(Statement ps, String key, Boolean parameter) throws StatementException {
		ps.set(key, parameter == null ? null : String.valueOf(parameter ? "true" : "false"));
	}
	
	
	@Override
	public Boolean getResult(ResultSet rs, String columnName) throws BindingException {
		String value = rs.get(columnName);
		return  value == null  || value.equalsIgnoreCase("null")? null : Boolean.valueOf(value);
	}

	@Override
	public Boolean getResult(ResultSet rs, int columnIndex) throws BindingException {
		String value = rs.get(columnIndex);
		return  value == null  || value.equalsIgnoreCase("null")? null : Boolean.valueOf(value);
	}



}
