package com.znd.ei.ads.bus.type;

import com.znd.ei.ads.bus.mapping.ResultSet;
import com.znd.ei.ads.bus.statement.Statement;


public interface TypeHandler<T> {

	  void setParameter(Statement ps, int i, T parameter);

	  void setParameter(Statement ps, String key, T parameter);
	  
	  T getResult(ResultSet rs, String columnName);

	  T getResult(ResultSet rs, int columnIndex);
}
