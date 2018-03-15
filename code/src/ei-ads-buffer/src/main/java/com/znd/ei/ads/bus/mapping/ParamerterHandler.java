package com.znd.ei.ads.bus.mapping;

import com.znd.ei.ads.bus.config.TableMeta;

public interface ParamerterHandler {
	public final static ParamerterHandler DefaultParameterHandler = (tableMeta, o)-> { return (String[])o; };
	
	String[] toArray(TableMeta tableMeta, Object o);
	
}
