package com.znd.ei.memdb.dao;


public class MemField {

	private String name;
	private String description;
	private MemDbDataType type;
	private int len;
	private boolean isPrimeKey;
	int index;
	
	public MemField() {
		isPrimeKey = false;
	}
	public int getLen() {
		return len;
	}
	public void setLen(int len) {
		this.len = len;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
	public MemDbDataType getType() {
		return type;
	}
	public void setType(MemDbDataType type) {
		this.type = type;
	}
	public boolean isPrimeKey() {
		return isPrimeKey;
	}
	public void setPrimeKey(boolean isPrimeKey) {
		this.isPrimeKey = isPrimeKey;
	}
	public int getIndex() {
		return index;
	}
	public void setIndex(int index) {
		this.index = index;
	}
	
	
}
