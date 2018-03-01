package com.znd.ei.ads.buffer;

public interface ParamerterHandler {
	public final static ParamerterHandler DefaultParameterHandler = (tableMeta, o)-> { return (String[])o; };
	
	String[] toArray(TableMeta tableMeta, Object o);
	
}
