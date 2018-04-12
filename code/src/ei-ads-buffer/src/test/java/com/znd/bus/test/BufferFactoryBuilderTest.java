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
import com.znd.bus.test.mapper.UserMapper;
import com.znd.bus.test.model.User;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class BufferFactoryBuilderTest {

	@Test
	public void createBufferBuilder() throws InterruptedException {
		BufferFactoryBuilder builder  = new BufferFactoryBuilder();
		BufferFactory factory = builder.build("builder_test", "com.znd.bus.test.model", "com.znd.bus.test.mapper");
		Buffer buffer = factory.openSession();
		UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
		User user = new User();
		user.setId("1");
		user.setName("user1");
		mapper.insert(user);
		buffer.commit();
		buffer.close();
		factory.destory();
		
		//Thread.sleep(2000);
	}
}
