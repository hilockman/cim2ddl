package com.znd.bus.test.adapter;

import com.znd.bus.server.AdapterService;
import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;

public class TestEventAdapter extends AdapterService
{

	static Integer ID = 0;
	private Integer id ;
	private int eventCount = 0;
	private int requestCount = 0;
	public TestEventAdapter() {
		id = ID++;
	}
	@Override
	public ResponseMessageType publish(EventMessageType message) {
		eventCount++;
		System.out.println(id+",  Receive event:"+ message.getPayload().getAny().get(0).toString()+", acm event = "+eventCount);
		return null;
	}

	@Override
	public ResponseMessageType request(RequestMessageType message) {
		requestCount++;
		System.out.println(id+",  Receive request:"+ message.getPayload().getAny().get(0).toString()+", acm request = "+requestCount);
		return null;
	}

	@Override
	public ResponseMessageType response(ResponseMessageType message) {
		// TODO Auto-generated method stub
		return null;
	}
	
}