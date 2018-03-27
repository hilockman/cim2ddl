package com.znd.ei.ads.bus.config;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
/**
 * 表定义
 * @author wangheng
 *
 */
public class TableMeta {

	private String name;

	private List<ColumnMeta> columns;
	
	private List<ColumnMeta> indexColumns = new ArrayList<>();
 
	private Map<String, ColumnMeta> columnMap = new HashMap<>();

	public TableMeta() {

	}

	public TableMeta(String name, ColumnMeta[] columns) {
		this.name = name;
		setColumns(Arrays.asList(columns));
	}
	
	public ColumnMeta findColumn(String name) {
		return columnMap.get(name);
	}

	public void formIndexColumn() {
		indexColumns.clear();
		int i = 0;
		for (ColumnMeta c : columns) {
			c.setIndex(i++);
			if (c.isIndexable())
				indexColumns.add(c);
			
			columnMap.put(c.getName(), c);
		}
	}
	public String getName() {
		return name;
	}

	public Map<String, Integer> getColumnIndexMap() {
		Map<String, Integer> m = new HashMap<>();
		for (ColumnMeta c : columns) {
			m.put(c.getName(), c.getIndex());
		}
		return m;
	}
	public TableMeta setName(String name) {
		this.name = name;
		return this;
	}

	public List<ColumnMeta> getColumns() {
		return columns;
	}

	public TableMeta setColumns(List<ColumnMeta> columns) {
		this.columns = columns;
		return this;
	}



	public int getColumnSize() {
		return columns.size();
	}



	public List<ColumnMeta> getIndexColumns() {
		return indexColumns;
	}


	@Override
	public int hashCode() {
		final int prime = 31;
		int result = 1;
		result = prime * result + ((columns == null) ? 0 : columns.hashCode());
		result = prime * result + ((name == null) ? 0 : name.hashCode());
		return result;
	}


	@Override
	public boolean equals(Object obj) {
		if (this == obj)
			return true;
		if (obj == null)
			return false;
		if (getClass() != obj.getClass())
			return false;
		TableMeta other = (TableMeta) obj;
		if (columns == null) {
			if (other.columns != null)
				return false;
		} else if (!columns.equals(other.columns))
			return false;
		if (name == null) {
			if (other.name != null)
				return false;
		} else if (!name.equals(other.name))
			return false;
		return true;
	}


	public String getKey() {		
		return String.format("%s", this.name);
	}



}
