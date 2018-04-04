package com.znd.bus.test;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.channel.Channel;
import com.znd.bus.channel.Message;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class SendMessageTest {

	@Autowired
	private Channel testChannel;
	
	@Test
	public void sendOneMessage() {
		System.out.println("------------------------start SendMessageTest.sendOneMessage()----------------------------");
		testChannel.send(new Message("test", "hello!"));
		System.out.println("------------------------end SendMessageTest.sendOneMessage()----------------------------"); 
	}
}
