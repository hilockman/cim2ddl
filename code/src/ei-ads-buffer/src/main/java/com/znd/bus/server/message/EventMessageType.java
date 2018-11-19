package com.znd.bus.server.message;

public class EventMessageType extends MessageBase {


	public static class Builder extends  MessageBase.Builder {
		
		public Builder(HeaderType header) {
			super(header);
		}

		public EventMessageType build() {			
			return new EventMessageType(this);
		}
	}
	
	private EventMessageType(Builder b) {
		super(b);
	}
}
