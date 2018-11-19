package com.znd.bus.server.message;

/**
 * 请求是从一个客户端（或源端）发送到服务端（或目标端）的，并且能得到响应的消息。
 * 该请求可以是一个查询（数据从目标端返回）或一个事务（数据在目标端被修改）。
 * @author wangheng
 * @date 2018年8月28日
 * @time 上午11:04:27
 * @type_name Request
 */
public class RequestMessageType  extends MessageBase {

	private RequestType request;

	public RequestType getRequest() {
		return request;
	}

	public void setRequest(RequestType request) {
		this.request = request;
	}
	
	public static class Builder extends  MessageBase.Builder {
		private RequestType request;
		
		public Builder(HeaderType header) {
			super(header);
		}
		
		public Builder request(RequestType request) {
			this.request = request;
			return this;
		}

		public RequestMessageType build() {			
			return new RequestMessageType(this);
		}
	}
	
	private RequestMessageType(Builder b) {
		super(b);
		this.request = b.request;
	}
}
