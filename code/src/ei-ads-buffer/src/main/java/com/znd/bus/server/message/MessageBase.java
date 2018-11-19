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
	
	public static abstract class Builder {
		private HeaderType header;
		private PayloadType payload;
		
		public Builder(HeaderType header) {
			this.header = header;
		}
		
		public Builder payload(PayloadType payload) {
			this.payload = payload;
			return this;
		}
		
		public abstract MessageBase build();


	}
	
	protected MessageBase(Builder b) {
		this.payload = b.payload;
		this.header = b.header;
	}
	
}
