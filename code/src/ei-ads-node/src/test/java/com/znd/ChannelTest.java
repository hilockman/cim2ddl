package com.znd;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelMessage;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class ChannelTest {

	@Autowired
	private Channel commonChannel;
	
	@Test
	public void sendMessage() {
		commonChannel.send(new ChannelMessage("add-test", "messaget"));
	}
}
