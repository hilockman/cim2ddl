package com.znd.ei.ads.buffer;

import com.znd.ei.ads.buffer.config.TableMeta;

public interface ParamerterHandler {
	public final static ParamerterHandler DefaultParameterHandler = (tableMeta, o)-> { return (String[])o; };
	
	String[] toArray(TableMeta tableMeta, Object o);
	
}
