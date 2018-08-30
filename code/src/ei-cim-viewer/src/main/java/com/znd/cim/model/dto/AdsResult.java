package com.znd.cim.model.dto;


public class AdsResult {


	private AdsResultCode code;
	private Object value;
	private String detail;
	

	public AdsResult(AdsResultCode code, Object value) {
		this(code, value, null);
	}
	public AdsResult(AdsResultCode code, Object value, String detail) {
		this.code = code;
		this.value = value;
		this.detail = detail;
	}
	
	public AdsResultCode getCode() {
		return code;
	}
	public void setCode(AdsResultCode code) {
		this.code = code;
	}
	public Object getValue() {
		return value;
	}
	public void setValue(Object value) {
		this.value = value;
	}
	

	
	public String getDetail() {
		return detail;
	}
	public void setDetail(String detail) {
		this.detail = detail;
	}

	
	public static AdsResult ok(Object value) {
		return new AdsResult(AdsResultCode.OK, value);
	}
	
	public static AdsResult ok() {
		return new AdsResult(AdsResultCode.OK, null);
	}
	
	public static AdsResult fail(String detail) {
		return new AdsResult(AdsResultCode.FAIL, null, detail);
	}
	
	public static AdsResult fail(Throwable e) {
		return new AdsResult(AdsResultCode.FAIL, null, e.getMessage());
	}
	
}
