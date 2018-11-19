package com.znd.bus.server;

import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.HeaderType;
import com.znd.bus.server.message.MessageBase;
import com.znd.bus.server.message.PayloadType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;

public abstract class AdapterService implements ServiceInterface {
/*
 * adpater id; 
 */
	private String token;
	private String name;
	
	private BusService busService;
	
	

	public ResponseMessageType sendPublish(VerbEnum verb, NounEnum noun, String content) {
		return sendPublish((EventMessageType) new EventMessageType.Builder(new HeaderType.Builder(verb, noun).build())
				.payload(new PayloadType.Builder().content(content).build()).build());
	}
	
	/**
	 * 接收并处理发布消息
	 * @param message
	 * @return TODO
	 * @return
	 */
	public ResponseMessageType sendPublish(EventMessageType message)
	{	
		return busService.publish(message);	
	}
	
	/**
	 * 接收并处理请求消息
	 * @param message
	 * @return
	 */
	public ResponseMessageType sendRequest(RequestMessageType message)
	{
		if (!message.getHeader().isSync()) {
			message.getHeader().setReplyAddress(token);
		}
		
		return busService.request(message);
	}
	
	
	public ResponseMessageType sendRequest(VerbEnum verb, NounEnum noun, String content) {
		return sendRequest((RequestMessageType) new RequestMessageType.Builder(new HeaderType.Builder(verb, noun).build())
				.payload(new PayloadType.Builder().content(content).build()).build());
	}
	/**
	 * 接收并处理响应消息
	 * @param message
	 * @return
	 */
	public ResponseMessageType sendResponse(ResponseMessageType message)
	{
		return busService.response(message);
	}

	
	public ResponseMessageType sendResponse(VerbEnum verb, NounEnum noun, String content) {
		return sendResponse((ResponseMessageType) new ResponseMessageType.Builder(new HeaderType.Builder(verb, noun).build())
				.payload(new PayloadType.Builder().content(content).build()).build());
	}
	
	public String getToken() {
		return token;
	}

	public void setToken(String token) {
		this.token = token;
	}

	public BusService getBusService() {
		return busService;
	}

	public void setBusService(BusService busService) {
		this.busService = busService;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
}
