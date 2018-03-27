package com.znd.ei.ads.bus.statement;


public interface Statement  {

	
	public default void set(int i, String value) {
		throw new StatementException("not support operation : set(int i, string value).");
	}
	
	public default void set(String key, String value) {
		throw new StatementException("not support operation : set(int i, string value).");
	}

}
