package com.znd.bus.server.message;
/**
 * 响应是作为一个请求的结果而发送的消息，典型的情况就是从请求的目标端发送到请求的源端。
 * @author wangheng
 * @date 2018年8月28日
 * @time 上午11:05:14
 * @type_name Response
 */
public class ResponseMessageType  extends MessageBase {
	private ReplyType reply;

	public ReplyType getReply() {
		return reply;
	}

	public void setReply(ReplyType reply) {
		this.reply = reply;
	}
}
