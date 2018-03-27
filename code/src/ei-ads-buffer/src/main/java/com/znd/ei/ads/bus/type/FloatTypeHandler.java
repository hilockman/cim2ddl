package com.znd.ei.ads.bus.type;

import com.znd.ei.ads.bus.mapping.ResultSet;
import com.znd.ei.ads.bus.statement.Statement;

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
		return  value == null ? null : Float.valueOf(value);
	}

	@Override
	public Float getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null ? null : Float.valueOf(value);	

	}

}
