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
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class BusEventTest {

	@Autowired
	private BusService busSerice;
	
	static class TestEventAdapter extends AdapterService
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
	
	
	public BusEventTest() {

	}
	
	
	@Test
	public void sendEvent() {
		
		busSerice.registAdapter(new TestEventAdapter(), "adapter1", Topic.out(VerbEnum.created, "PublishEvent"));
		busSerice.registAdapter(new TestEventAdapter(), "adapter2", Topic.out(VerbEnum.created, "PublishEvent"));

		

		for (int i = 0; i < 2; i++) {
//			busSerice.publish(VerbEnum.created, "TestEvent", "Hello"+Math.floor(Math.random()* 100));
			busSerice.publish(VerbEnum.created, "PublishEvent", "Hello"+i);
		}
		try {
			Thread.sleep(1000*2);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
