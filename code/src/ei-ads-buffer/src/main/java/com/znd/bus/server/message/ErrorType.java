package com.znd.bus.server.message;

public class ErrorType {

	private String code;
    private ErrorLevelEnum level;
    private String reason;
    private String details;
	public String getCode() {
		return code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public ErrorLevelEnum getLevel() {
		return level;
	}
	public void setLevel(ErrorLevelEnum level) {
		this.level = level;
	}
	public String getReason() {
		return reason;
	}
	public void setReason(String reason) {
		this.reason = reason;
	}
	public String getDetails() {
		return details;
	}
	public void setDetails(String details) {
		this.details = details;
	}
}
