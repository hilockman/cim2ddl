package com.znd.ei.ads.bus.mapping;

public class ParameterMapping {

	private String property;
	private String dbColumnType; 
	private Integer dbColumnIndex;
	private TypeHandler<?> typeHandler;
	public String getProperty() {
		return property;
	}
	public String getDbColumnType() {
		return dbColumnType;
	}
	public Integer getDbColumnIndex() {
		return dbColumnIndex;
	}
	public TypeHandler<?> getTypeHandler() {
		return typeHandler;
	}
}
