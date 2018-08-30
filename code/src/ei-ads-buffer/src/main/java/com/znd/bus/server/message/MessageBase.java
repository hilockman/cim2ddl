package com.znd.bus.server.message;

public class MessageBase {
	private HeaderType header;
	private PayloadType payload;
	
	public HeaderType getHeader() {
		return header;
	}
	public void setHeader(HeaderType header) {
		this.header = header;
	}
	public PayloadType getPayload() {
		return payload;
	}
	public void setPayload(PayloadType payload) {
		this.payload = payload;
	}
}
