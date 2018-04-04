package com.znd.bus.test;

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
	private BufferLogger bufferLogger;
	
	@Autowired
	private LogMapper logMapper;
	
	@Test
	public void insertLog() {
		 
		 for (int i = 0; i< 10; i++) {
			 bufferLogger.debug("hello %d", i);
		 }
		 
	}
	
	@Test
	public void queryLog() {
		 List<Log> logs = logMapper.findAll();
		 for (int i = 0; i< logs.size(); i++) {
			 System.out.println(logs.get(i));
		 }
	}
	
}
