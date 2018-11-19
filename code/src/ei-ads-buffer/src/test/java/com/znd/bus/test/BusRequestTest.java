package com.znd.bus.test;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.server.AdapterService;
import com.znd.bus.server.BusService;
import com.znd.bus.server.Topic;
import com.znd.bus.server.VerbEnum;
import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.HeaderType;
import com.znd.bus.server.message.PayloadType;
import com.znd.bus.server.message.ReplyType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;
@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class BusRequestTest {
	@Autowired
	private BusService busSerice;
	
	static Integer ID = 0;
	private AdapterService adapter1;
	public class TestRequestAdapter extends AdapterService
	{		
		private int eventCount = 0;

		private int requestCount = 0;
		private int reponseCount = 0;
		
		
		public TestRequestAdapter() {
			ID++;
		}
		@Override
		public ResponseMessageType publish(EventMessageType message) {
			eventCount++;
			System.out.println(getName()+",  Receive event:"+ message.getPayload().getAny().get(0).toString()+", acm event = "+eventCount);
			return null;
		}

		@Override
		public ResponseMessageType request(RequestMessageType message) {
			return null;
			
			
		}

		@Override
		public ResponseMessageType response(ResponseMessageType message) {
			reponseCount++;
			System.out.println(getName()+",  Receive response:"+ message.getPayload().getAny().get(0).toString()+", acm response = "+reponseCount);

			
			return null;
		
		
	    }
	}
	
	public class TestResponseAdapter extends AdapterService
	{

		
		private int eventCount = 0;
		private int requestCount = 0;
		public TestResponseAdapter() {
			ID++;
		}
		@Override
		public ResponseMessageType publish(EventMessageType message) {
			eventCount++;
			System.out.println(getName()+",  Receive event:"+ message.getPayload().getAny().get(0).toString()+", acm event = "+eventCount);
			return null;
		}

		@Override
		public ResponseMessageType request(RequestMessageType message) {
			requestCount++;
			System.out.println(getName()+",  Receive request:"+ message.getPayload().getAny().get(0).toString()+", acm request = "+requestCount);
			
			
			
			HeaderType header = message.getHeader();
			
			ResponseMessageType r = (ResponseMessageType) new ResponseMessageType.Builder(
					new HeaderType.Builder(VerbEnum.reply, header.getNoun())
					.correlationID(header.getCorrelationID())
					.messageID(header.getMessageID())
					.build())
					.reply(new ReplyType.Builder().build())
					.payload(new PayloadType.Builder().content("OK").build())
					
					.build();
			try {
				if (!header.isSync()) {
					return busSerice.response(r);				
				} else {
					return r;
				}
			} finally {
				System.out.println(getName()+", send response : "+"OK");
			}
			
			
		}

		@Override
		public ResponseMessageType response(ResponseMessageType message) {
			// TODO Auto-generated method stub
			return null;
		}
		
	}
		
	public BusRequestTest( ) {


	}
	
	public static final String TETS_REQUEST =  "EMS";
	@Test
	public void requestTest() {
		
		adapter1 = busSerice.registAdapter(new TestRequestAdapter(), "request-adapter", Topic.in(VerbEnum.create, TETS_REQUEST));
		busSerice.registAdapter(new TestResponseAdapter(), "response-adapter", Topic.out(VerbEnum.create, TETS_REQUEST));
		
//		EventMessageType message = new EventMessageType();
//		HeaderType header = new HeaderType();
//		header.setVerb(VerbEnum.created);
//		header.setNoun("Hello");
//		message.setHeader(header);
//		busSerice.publish(message);
		for (int i = 0; i < 1; i++) {
			String message = "Hello"+i;
			System.out.println(adapter1.getName()+", send message : "+message);
			adapter1.sendRequest((RequestMessageType)new RequestMessageType.Builder(new HeaderType.Builder(VerbEnum.create, TETS_REQUEST).build())
					.payload(new PayloadType.Builder().any(message).build()).build());
		}

		try {
			Thread.sleep(1000*2);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
