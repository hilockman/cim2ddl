package com.znd.bus.channel;

public class Message {

	public Message(String code, String content) {
		super();
		this.code = code;
		this.content = content;
	}
	private String code;
	private String content;
	
	public String getCode() {
		return code;
	}
	public void setCode(String code) {
		this.code = code;
	}
	public String getContent() {
		return content;
	}
	public void setContent(String content) {
		this.content = content;
	}
	@Override
	public String toString() {
		return "Message [code=" + code + ", content=" + content + "]";
	}
}
