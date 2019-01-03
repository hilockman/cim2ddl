package com.znd.bus.type;

import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.StatementException;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class ByteObjectArrayTypeHandler implements TypeHandler<Byte[]> {

	byte[] to(Byte[] parameter) {
	
		byte[] bytes = new byte[parameter.length];
		int i = 0;
		for (Byte b : parameter) {
			bytes[i++] = b;
		}
		return bytes;
	}
	
	Byte[] to(byte[] parameter) {
		
		Byte[] bytes = new Byte[parameter.length];
		int i = 0;
		for (byte b : parameter) {
			bytes[i++] = b;
		}
		return bytes;
	}
	
	@Override
	public void setParameter(Statement ps, int i, Byte[] parameter) throws StatementException {
		ps.set(i, parameter == null ? null : new String(to(parameter)));
	}

	@Override
	public void setParameter(Statement ps, String key, Byte[] parameter) throws StatementException {
		ps.set(key, parameter == null ? null : new String(to(parameter)));
	}

	@Override
	public Byte[] getResult(ResultSet rs, String columnName) throws BindingException {
		String value = rs.get(columnName);
		return  value == null || value.equalsIgnoreCase("null") ? null : to(value.getBytes());
	}

	@Override
	public Byte[] getResult(ResultSet rs, int columnIndex) throws BindingException {
		String value = rs.get(columnIndex);
		return  value == null || value.equalsIgnoreCase("null") ? null : to(value.getBytes());
	}

}
