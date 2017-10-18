package com.znd.ei.ads.acp;

public class ACPResult {

	public static String SUCCESS_CODE = "OK";
	public static String FAIL_CODE = "FAIL";
	
	private String code;
	private Object value;
	private String log;
	
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
	
	public ACPResult(String code, Object value) {
		this.code = code;
		this.value = value;
	}
	
	@Override
	public String toString() {
		return "ComputingResult [code=" + code + ", value=" + value + "]";
	}
	public String getLog() {
		return log;
	}
	public void setLog(String log) {
		this.log = log;
	}
}
