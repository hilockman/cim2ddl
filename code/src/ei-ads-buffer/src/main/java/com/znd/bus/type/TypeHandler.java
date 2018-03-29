package com.znd.bus.type;

import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;


public interface TypeHandler<T> {

	  void setParameter(Statement ps, int i, T parameter);

	  void setParameter(Statement ps, String key, T parameter);
	  
	  T getResult(ResultSet rs, String columnName);

	  T getResult(ResultSet rs, int columnIndex);
}
