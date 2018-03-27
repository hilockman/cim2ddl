package com.znd.ei.ads.bus.type;

import com.znd.ei.ads.bus.mapping.ResultSet;
import com.znd.ei.ads.bus.statement.Statement;

public class DoubleTypeHandler implements TypeHandler<Double> {

	@Override
	public void setParameter(Statement ps, int i, Double parameter) {
		ps.set(i, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, Double parameter) {
		ps.set(key, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public Double getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null ? null : Double.valueOf(value);	
	}

	@Override
	public Double getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null ? null : Double.valueOf(value);	
	}

}
