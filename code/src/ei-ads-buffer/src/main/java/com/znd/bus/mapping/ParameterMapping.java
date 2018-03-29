package com.znd.bus.mapping;

import com.znd.bus.type.TypeHandler;

public class ParameterMapping {

	private final String property;
	private final int dbColumnIndex;
	private final int columnIndex;
	private final boolean indexable;
	private final TypeHandler<?> typeHandler;
	
	public ParameterMapping(String property, int columnIndex, int dbColumnIndex, TypeHandler<?> typeHandler, boolean isIndex)
	{
		this.columnIndex = columnIndex;
		this.property = property;
		this.dbColumnIndex = dbColumnIndex;
		this.typeHandler = typeHandler;
		this.indexable = isIndex;
	}
	
	public String getProperty() {
		return property;
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
