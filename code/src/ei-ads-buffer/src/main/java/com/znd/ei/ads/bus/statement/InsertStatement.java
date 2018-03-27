package com.znd.ei.ads.bus.statement;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class InsertStatement implements Statement {

	private final Map<String, List<String>> indexRecords = new HashMap<>();
	private final List<String[]> records = new ArrayList<>();
	private final Map<String, Integer> dbColumnIndexMap = new HashMap<>();
	private final Map<String, Integer> columnIndexMap = new HashMap<>();
	private int index = -1;
	//private String[] values;
	public InsertStatement() {
		
	}
	
	@Override
	public void set(int i, String value) {
		records.get(index)[i] = value;
	}

	@Override
	public void set(String key, String value) {
		throw new StatementException("Not support set by key : "+key);
	}


	public void add(String[] record) {
		records.add(record);
		index++;
	}

	public Map<String, List<String>> getIndexRecords() {
		return indexRecords;
	}

	public List<String[]> getRecords() {
		return records;
	}

	public void put(String name, List<String> value) {
		indexRecords.put(name, value);
	}
	
	
	public void putDbColumnMap(Map<String, Integer> map) {
		dbColumnIndexMap.putAll(map);
	}

	public void setDbColumnIndex(String name, Integer index) {
		dbColumnIndexMap.put(name, index);
	}
	
	public void setColumnIndex(String property, int columnIndex) {
		columnIndexMap.put(property, columnIndex);
	}
	
	public int count() {
		return records.size();
	}

	public void update(int i, RowUpdateHandler h) {
		Map<Short, String> columns = new HashMap<>();
		Map<String, String> conditions = new HashMap<>();
		String[] record = records.get(i);
		for (Entry<String, Integer> e : dbColumnIndexMap.entrySet()) {
			String key = e.getKey();
			int dbIndex = e.getValue();
			Integer index = columnIndexMap.get(key);
			if (index == null || index > record.length) {
				throw new StatementException("fail to find db index : "+key);
			}
			columns.put((short)dbIndex, record[index]);
		}
		for (Entry<String, List<String>> e : indexRecords.entrySet()) {
			String key = e.getKey();
			List<String> value = e.getValue();
			conditions.put(key, value.get(i));
		}
		
		h.update(columns, conditions);
	
	}




}
