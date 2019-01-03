package com.znd.bus.type;

import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.StatementException;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class ByteArrayTypeHandler implements TypeHandler<byte[]> {

	@Override
	public void setParameter(Statement ps, int i, byte[] parameter) throws StatementException {
		ps.set(i, parameter == null ? null : new String(parameter));
	}

	@Override
	public void setParameter(Statement ps, String key, byte[] parameter) throws StatementException {
		ps.set(key, parameter == null ? null : new String(parameter));
	}

	@Override
	public byte[] getResult(ResultSet rs, String columnName) throws BindingException {
		String value = rs.get(columnName);
		return  value == null  || value.equalsIgnoreCase("null")? null : value.getBytes();
	}

	@Override
	public byte[] getResult(ResultSet rs, int columnIndex) throws BindingException {
		String value = rs.get(columnIndex);
		return  value == null  || value.equalsIgnoreCase("null")? null : value.getBytes();
	}

}
