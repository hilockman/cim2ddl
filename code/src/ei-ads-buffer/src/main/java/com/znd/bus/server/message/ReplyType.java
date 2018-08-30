package com.znd.bus.server.message;

import java.util.ArrayList;
import java.util.List;

public class ReplyType {

	private ReplyCodeEnum result;
	
	private List<ErrorType> errors = new ArrayList<>();

	private List<Object> any = new ArrayList<>();
	
	public ReplyCodeEnum getResult() {
		return result;
	}

	public void setResult(ReplyCodeEnum result) {
		this.result = result;
	}

	public List<ErrorType> getErrors() {
		return errors;
	}

	public void setErrors(List<ErrorType> errors) {
		this.errors = errors;
	}

	public List<Object> getAny() {
		return any;
	}

	public void setAny(List<Object> any) {
		this.any = any;
	}
	
	
}
