package com.znd.bus.type;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class FloatTypeHandler implements TypeHandler<Float> {

	@Override
	public void setParameter(Statement ps, int i, Float parameter) {
		ps.set(i, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, Float parameter) {
		ps.set(key, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public Float getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null  || value.equalsIgnoreCase("null") ? null : Float.valueOf(value);
	}

	@Override
	public Float getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null  || value.equalsIgnoreCase("null") ? null : Float.valueOf(value);	

	}

}
