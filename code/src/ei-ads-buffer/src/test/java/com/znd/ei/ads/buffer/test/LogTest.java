package com.znd.ei.ads.buffer.test;

import java.util.List;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.log.BufferLogger;
import com.znd.bus.log.Log;
import com.znd.bus.log.LogMapper;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class LogTest {

	@Autowired
	private BufferFactory factory;
	
	@Test
	public void insertLog() {
		 BufferLogger logger = factory.logger();
		 
		 for (int i = 0; i< 10; i++) {
			 logger.debug("hello %d", i);
		 }
		 
	}
	
	@Test
	public void queryLog() {
		 Buffer buffer = factory.openSession();
		 LogMapper mapper = factory.config().getMapper(LogMapper.class, buffer);
		 List<Log> logs = mapper.findAll();
		 for (int i = 0; i< logs.size(); i++) {
			 System.out.println(logs.get(i));
		 }
		 buffer.close();
	}
	
}
