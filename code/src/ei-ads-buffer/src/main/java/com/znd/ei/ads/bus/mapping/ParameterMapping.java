package com.znd.ei.ads.bus.mapping;

import com.znd.ei.ads.bus.type.TypeHandler;

public class ParameterMapping {

	private final String property;
	private final String dbColumnType; 
	private final int dbColumnIndex;
	private final int columnIndex;
	private final boolean indexable;
	private final TypeHandler<?> typeHandler;
	
	public ParameterMapping(String property, String dbColumnType, int columnIndex, int dbColumnIndex, TypeHandler<?> typeHandler, boolean isIndex)
	{
		this.columnIndex = columnIndex;
		this.property = property;
		this.dbColumnType = dbColumnType;
		this.dbColumnIndex = dbColumnIndex;
		this.typeHandler = typeHandler;
		this.indexable = isIndex;
	}
	
	public String getProperty() {
		return property;
	}
	public String getDbColumnType() {
		return dbColumnType;
	}
	public int getDbColumnIndex() {
		return dbColumnIndex;
	}
	public TypeHandler<?> getTypeHandler() {
		return typeHandler;
	}

	public boolean isIndexable() {
		return indexable;
	}

	public int getColumnIndex() {
		return columnIndex;
	}
}
