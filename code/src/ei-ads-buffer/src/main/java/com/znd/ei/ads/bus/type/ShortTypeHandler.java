package com.znd.ei.ads.bus.type;

import com.znd.ei.ads.bus.mapping.ResultSet;
import com.znd.ei.ads.bus.statement.Statement;

public class ShortTypeHandler implements TypeHandler<Short> {

	@Override
	public void setParameter(Statement ps, int i, Short parameter) {
		ps.set(i, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, Short parameter) {
		ps.set(key, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public Short getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null ? null : Short.valueOf(value);
	}

	@Override
	public Short getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null ? null : Short.valueOf(value);
	}

}
