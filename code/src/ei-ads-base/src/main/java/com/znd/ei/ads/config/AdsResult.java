package com.znd.ei.ads.config;

import com.znd.ei.Utils;

public class AdsResult {

	public static String SUCCESS_CODE = "OK";
	public static String FAIL_CODE = "FAIL";
	
	private String code;
	private Object value;
	private String detail;
	
	public AdsResult() {
		this(SUCCESS_CODE, null);
	}
	public AdsResult(String code, Object value) {
		this(code, value, null);
	}
	public AdsResult(String code, Object value, String detail) {
		this.code = code;
		this.value = value;
		this.detail = detail;
	}
	
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
	

	
	@Override
	public String toString() {
		return Utils.toJSon(this);
	}
	public String getDetail() {
		return detail;
	}
	public void setDetail(String detail) {
		this.detail = detail;
	}

	
	public static AdsResult ok(Object value) {
		return new AdsResult(SUCCESS_CODE, value);
	}
	
	
	public static AdsResult fail(String detail) {
		return new AdsResult(FAIL_CODE, null, detail);
	}
	
}
