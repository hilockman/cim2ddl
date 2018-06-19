package com.znd.bus.channel;

public class Message {

	public Message(MessageCodeEnum code, String content) {
		super();
		this.code = code;
		this.content = content;
	}
	private MessageCodeEnum code;
	private String content;
	
	public MessageCodeEnum getCode() {
		return code;
	}
	public void setCode(MessageCodeEnum code) {
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
