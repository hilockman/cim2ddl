package com.znd.bus.test;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.test.mapper.UserInfoMapper;
import com.znd.bus.test.mapper.UserMapper;
import com.znd.bus.test.model.User;
import com.znd.bus.test.model.UserInfo;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class ReliabilityBufferBuilderTest {
	@Test
	public void createBufferBuilder() throws InterruptedException {
		BufferFactoryBuilder builder  = new BufferFactoryBuilder();
		BufferFactory factory = builder.build("ReliabilityBuffer_test",
				"com.znd.ei.memdb.reliabilty.domain;com.znd.bus.test.model", "com.znd.bus.test.mapper", null);
		Buffer buffer = factory.openSession();
//		UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
//		User user = new User();
//		user.setId("1");
//		user.setName("user1");
//		mapper.insert(user);
		
		UserInfoMapper mapper1 = factory.config().getMapper(UserInfoMapper.class, buffer);
		UserInfo userInfo = new UserInfo();
		userInfo.setId("1");
		userInfo.setName("user1");
		
		mapper1.insert(userInfo);
		
		//buffer.commit();
		buffer.close();
		factory.destory();
		
		//Thread.sleep(2000);
	}
}
