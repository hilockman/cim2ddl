package com.znd.bus.test;

import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
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
import com.znd.bus.test.mapper.UserMapper;
import com.znd.bus.test.model.User;
@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest 
public class UpdateUserTest {
	@Autowired
	private BufferFactory factory;
	
	static int index = 0;
	static ExecutorService pool = Executors.newCachedThreadPool();
	static Timer timer = new Timer(true);
    @Test
   // @Repeat(10000)
    public void update() {
    	System.out.println("------------------------start UpdateUserTest----------------------------"); 
    	
    	Buffer buffer = factory.openSession();
    	UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
    	
    	User user = mapper.findById("1");
    	if (user != null) {
    		System.out.println("Find user :  "+ user);	
    	} else {
    		user = new User();
    		user.setId("1");
    		user.setName("user0");
    		mapper.insert(user);
    	}
    	
    	TimerTask task = new TimerTask() {
			
			@Override
			public void run() {
	        	User user1 = mapper.findById("1");
	        	
	        	
	        	user1.setName("User_"+Math.round(Math.floor(Math.random() * 1000)));
	        	try {
	        	mapper.update(user1);
	        	} catch (Throwable e) {
	        		e.printStackTrace();
	        	}
	        	System.out.println("i = "+index++);
			}
		};
    	timer.scheduleAtFixedRate(task, 0, 50);
//    	for (int i = 0; i  < 1000; i++) {
//    		pool.execute(()-> {
//	        	User user1 = mapper.findById("1");
//	        	
//	        	
//	        	user1.setName("User_"+Math.round(Math.floor(Math.random() * 1000)));
//	        	try {
//	        	mapper.update(user1);
//	        	} catch (Throwable e) {
//	        		e.printStackTrace();
//	        	}
//	        	
//	//        	try {
//	//				Thread.sleep(1000);
//	//			} catch (InterruptedException e) {
//	//				// TODO Auto-generated catch block
//	//				e.printStackTrace();
//	//			}
//	        	System.out.println("i = "+index++);
//    		});
//    		
//    	}

//    	System.out.println("shutdown pool.");
//    	pool.shutdown();
//    	try {
//			pool.awaitTermination(1, TimeUnit.DAYS);
//		} catch (InterruptedException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
    	
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
    		System.out.println("Find user :  "+ user);	
    	} else {
    		System.err.println("Find no user: id = 1");
    	}
    	
    	

    	buffer.close();
    	System.out.println("------------------------end UpdateUserTest----------------------------");
    }
}
