
package com.znd.bus.type;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class CharArrayTypeHandler implements TypeHandler<char[]> {

	@Override
	public void setParameter(Statement ps, int i, char[] parameter) {

		ps.set(i, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, char[] parameter) {
		ps.set(key, parameter == null ? null : String.valueOf(parameter));
	}

	@Override
	public char[] getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null ? null : value.toCharArray();
	}

	@Override
	public char[] getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null ? null : value.toCharArray();
	}

}
