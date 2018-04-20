package com.znd.bus.type;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;

public class EnumTypeHandler<E extends Enum<E>> implements TypeHandler<E> {

	private final Class<E> type;
	
	 public EnumTypeHandler(Class<E> type) {
		    if (type == null) {
		      throw new IllegalArgumentException("Type argument cannot be null");
		    }
		    this.type = type;
     }
	 
	@Override
	public void setParameter(Statement ps, int i, E parameter) {
		ps.set(i, parameter == null ? null : parameter.name());
	}

	@Override
	public void setParameter(Statement ps, String key, E parameter) {
		ps.set(key, parameter == null ? null : parameter.name());
	}

	@Override
	public E getResult(ResultSet rs, String columnName) {
		String value = rs.get(columnName);
		return  value == null  || value.equalsIgnoreCase("null") ? null : Enum.valueOf(type, value);	

	}

	@Override
	public E getResult(ResultSet rs, int columnIndex) {
		String value = rs.get(columnIndex);
		return  value == null  || value.equalsIgnoreCase("null") ? null : Enum.valueOf(type, value);	
	}


}
