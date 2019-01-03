package com.znd.bus.channel;

public class ChannelMessage {


	private String code;
	private String content;
	
	public ChannelMessage() {
		
	}
	public ChannelMessage(MessageCodeEnum code, String content) {

		this.code = code.name();
		this.content = content;
	}
	public ChannelMessage(String code, String content) {
		this.code = code;
		this.content = content;
	}
	public String getCode() {
		return code;
	}
	public void setCode(MessageCodeEnum code) {
		this.code = code.name();
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
