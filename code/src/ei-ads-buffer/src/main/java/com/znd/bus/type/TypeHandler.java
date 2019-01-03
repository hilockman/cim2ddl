package com.znd.bus.type;

import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.StatementException;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.Statement;


public interface TypeHandler<T> {

	  void setParameter(Statement ps, int i, T parameter) throws StatementException;

	  void setParameter(Statement ps, String key, T parameter) throws StatementException;
	  
	  T getResult(ResultSet rs, String columnName) throws BindingException;

	  T getResult(ResultSet rs, int columnIndex) throws BindingException;
}
