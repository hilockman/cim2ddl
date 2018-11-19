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
	
	
	public static class Builder {
		private ReplyCodeEnum result = ReplyCodeEnum.OK;
		
		private List<ErrorType> errors = new ArrayList<>();

		private List<Object> any = new ArrayList<>();
		
		public Builder() {
			
		}
		
		public Builder result(ReplyCodeEnum result) {
			this.result = result;
			return this;
		}
		
		
		public Builder errors(ErrorType ... erros) {
			for (ErrorType  error : errors) {
				errors.add(error);
			}
			return this;
		}
		
		public Builder errors(List<ErrorType> errors) {
			this.errors = errors;
			return this;
		}
		
		
		public Builder any(Object...objects) {
			for (Object object : objects) {
				any.add(object);
			}
			return this;
		}
		
		public Builder content(String content) {
			this.any.add(content);
			return this;
		}
		
		public ReplyType build() {
			return new ReplyType(this);
		}
		
	}
	
	
	private ReplyType(Builder b) {
		this.result = b.result;
		this.errors = b.errors;
		this.any = b.any;
	}
	
}
