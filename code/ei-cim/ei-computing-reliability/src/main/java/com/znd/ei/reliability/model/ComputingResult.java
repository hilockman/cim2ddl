package com.znd.ei.reliability.model;

public class ComputingResult {

	private String code;
	private Object value;
	public String getCode() {
		return code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public Object getValue() {
		return value;
	}
	public void setValue(Object value) {
		this.value = value;
	}
	
	public ComputingResult(String code, Object value) {
		this.code = code;
		this.value = value;
	}
}
