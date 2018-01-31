package com.znd.ei.buffer;

public interface RecordParser {
	public final static RecordParser DefaultRecordParser = (tableMeta, o)-> { return (String[])o; };
	
	String[] toArray(TableMeta tableMeta, Object o);
	
}
