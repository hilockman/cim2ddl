package com.znd.bus.server;

import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;

/**
 * 适配器接口
 * @author wangheng
 * @date 2018年8月27日
 * @time 上午11:07:23
 * @type_name ServiceInterface
 */
public interface ServiceInterface {

	/**
	 * 接收并处理发布消息
	 * @param message
	 * @return TODO
	 * @return
	 */
	ResponseMessageType publish(EventMessageType message);
	
	/**
	 * 接收并处理请求消息
	 * @param message
	 * @return
	 */
	ResponseMessageType request(RequestMessageType message);
	
	/**
	 * 接收并处理响应消息
	 * @param message
	 * @return
	 */
	ResponseMessageType response(ResponseMessageType message);
}
