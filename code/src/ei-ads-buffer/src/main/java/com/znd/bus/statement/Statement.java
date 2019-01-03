package com.znd.bus.statement;

import com.znd.bus.exception.StatementException;

public interface Statement  {

	
	public default void set(int i, String value) throws StatementException {
		throw new StatementException("not support operation : set(int i, string value).");
	}
	
	public default void set(String key, String value) throws StatementException {
		throw new StatementException("not support operation : set(int i, string value).");
	}

}
