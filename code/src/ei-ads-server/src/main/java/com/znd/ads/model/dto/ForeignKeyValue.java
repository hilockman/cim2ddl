package com.znd.ads.model.dto;

public class ForeignKeyValue {

	private String key;
	private String value;

	@Override
	public String toString() {
		return "ForeignKey [key=" + key + ", value=" + value + "]";
	}

	public String getKey() {
		return key;
	}

	public void setKey(String key) {
		this.key = key;
	}

	public String getValue() {
		return value;
	}

	public void setValue(String value) {
		this.value = value;
	}
	
}
