package com.znd.bus.mapping;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import com.znd.bus.exception.BindingException;

public class ResultSet {

	private Integer index = -1;
	private final List<String[]> results;
	private Map<String, Integer> columIndexMap; 
	

	public boolean next() {
		index++;
		return index < results.size();
	}
	
	public ResultSet(Map<String, Integer> columIndexMap, List<String[]> results) {
		this.columIndexMap = columIndexMap;
		this.results = results;
	}
	
//	public ResultSet(Map<String, Integer> columIndexMap) {
//		this.columIndexMap = columIndexMap;
//		this.results = new ArrayList<String[]>();
//	}
	
	public List<String[]> getResults() {
		return results;
	}

	public String get(String column) {
		if (!columIndexMap.containsKey(column)) {
			throw new  BindingException("Find no column in resultset : "+column);
		}
		
		return get(columIndexMap.get(column));
	}
	
	public String get(Integer column) {
		if (index < 0 || index >= results.size())
			throw new  BindingException("Out of row limit :" + index);
		
		if (column < 0 || column >= columIndexMap.size()) {
			throw new  BindingException("Out of column limit :" + column);
		}
		String[] rowValues = results.get(index);
		
		return rowValues[column];
		
		
	}
}
