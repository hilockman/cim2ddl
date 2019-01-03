package com.znd.ei.buffer;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.CreateFlag;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.exception.MessageException;


@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class BufferTests {
	@Test
	public void createOneBuffer() throws RedissonDBException, BindingException, BufferException, MessageException {
		System.out.println("------------------------start TestBus.createOneBuffer()----------------------------");
		BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(CreateFlag.CREATE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		BufferFactory f = b.build(config);
		f.destory();
		System.out.println("------------------------end TestBus.createOneBuffer()----------------------------");
	}
	
	@Test
	public void destoryOneBuffer() throws RedissonDBException, BindingException, BufferException, MessageException {
		System.out.println("------------------------start TestBus.destoryOneBuffer()----------------------------");
		BufferConfig config = new BufferConfig();
		config.setName("myBuffer");
		config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
		config.setCreateFlag(CreateFlag.FALSE);
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		b.build(config);
		
		config.getBufferContext().removeBuffer();
		System.out.println("------------------------end TestBus.destoryOneBuffer()----------------------------");
	}
	
	@Test
	public void create10Buffers() throws RedissonDBException, BindingException, BufferException, MessageException {
		System.out.println("------------------------start TestBus.create10Buffers()----------------------------");
		int count = 10;
		
		
		for (int i = 0; i < count; i++) {
			BufferConfig config = new BufferConfig();
			config.setName("myBuffer"+i);
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(CreateFlag.CREATE);
			
			BufferFactoryBuilder b = new BufferFactoryBuilder();
			b.build(config);
		}
		
		System.out.println("------------------------end TestBus.create10Buffers()----------------------------");

	}
	
	@Test
	public void destory10Buffer() throws RedissonDBException, BindingException, BufferException, MessageException {
		System.out.println("------------------------start TestBus.destory10Buffer()----------------------------");
		int count = 10;
		
		for (int i = 0; i < count; i++) {
			BufferConfig config = new BufferConfig();
			config.setName("myBuffer"+i);
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(CreateFlag.FALSE);
			BufferFactoryBuilder b = new BufferFactoryBuilder();
			BufferFactory factory = b.build(config);
			config.getBufferContext().removeBuffer();
		}
		System.out.println("------------------------destory TestBus.destory10Buffer()----------------------------");
	}
}
