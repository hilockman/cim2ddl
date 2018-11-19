package com.znd.bus.test;

import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.TimeUnit;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.test.mapper.AdsNodeInfoBuffer;
import com.znd.bus.test.model.NodeInfo;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest 
public class UpdateAdsNodeTest {

	@Autowired
	private BufferFactory factory;
	static int index = 0;
	static Timer timer = new Timer(true);
	@Test
	public void test() {
   	System.out.println("------------------------start UpdateNodeTest----------------------------"); 
    	
    	Buffer buffer = factory.openSession();
    	AdsNodeInfoBuffer mapper = factory.config().getMapper(AdsNodeInfoBuffer.class, buffer);
    	
    	NodeInfo user = new NodeInfo();

    	
		user.setId("1");
		user.setName("user0");
		user.setAccMsgCount(0);
		user.setCpuRate(0.0);
		user.setCurMsgCount(0);
		user.setJobCount(0);
		user.setLastUpdate(new Date());
		user.setMemoryRate(0.0);
		user.setStatus(0);	
		user.setTaskCount(0);
		user.setUrl("localhost");
		
		if (mapper.findById("1") == null)
		   mapper.insert(user);
		else 
			mapper.update(user);
    	
    	TimerTask task = new TimerTask() {
			
			@Override
			public void run() {
				NodeInfo user1 = mapper.findById("1");
	        	
	        	
	        	user1.setName("User_"+Math.round(Math.floor(Math.random() * 1000)));
	        	try {
	        	  mapper.update(user1);
	        	} catch (Throwable e) {
	        		e.printStackTrace();
	        		System.exit(0);
	        	}
	        	System.out.println("i = "+index+++"**************************");
			}
		};
		
		
//		task.run();
    	timer.scheduleAtFixedRate(task, 0, 50);

    	long m = TimeUnit.SECONDS.toMillis(60 * 5);
    	System.out.println(String.format("等待%d ms", m));
    	
    	try {
			Thread.sleep(m);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	timer.cancel();
    	user = mapper.findById("1");
    	if (user != null) {
    		System.out.println("Find node :  "+ user);	
    	} else {
    		System.err.println("Find no node: id = 1");
    	}
    	
    	

    	buffer.close();
    	System.out.println("------------------------end UpdateNodeTest----------------------------");
	}
}
