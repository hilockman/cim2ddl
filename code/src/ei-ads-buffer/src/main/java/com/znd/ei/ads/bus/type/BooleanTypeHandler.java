package com.znd.ei.ads.bus.type;

import com.znd.ei.ads.bus.mapping.ResultSet;
import com.znd.ei.ads.bus.statement.Statement;

public class BooleanTypeHandler implements TypeHandler<Boolean> {

	@Override
	public void setParameter(Statement ps, int i, Boolean parameter) {
		ps.set(i, parameter == null ? null : String.valueOf(parameter ? "true" : "false"));
	}
	
	@Override
	public void setParameter(Statement ps, String key, Boolean parameter) {
		ps.set(key, parameter == null ? null : String.valueOf(parameter ? "true" : "false"));
	}
	
	
	@Override
	public Boolean getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null ? null : Boolean.valueOf(value);
	}

	@Override
	public Boolean getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null ? null : Boolean.valueOf(value);
	}



}
