package com.znd.bus.test;

import org.junit.Test;

import com.znd.bus.config.BufferConfig;
import com.znd.bus.test.mapper.UserMapper;

public class ResolveNameTest {

	@Test
	public void resolveName() {
		System.out.println("table name = "+BufferConfig.resolveTableName(UserMapper.class)+", class = "+UserMapper.class);
		//System.out.println("table name = "+BufferConfig.resolveTableName(UserMapper.class.getSuperclass())+", class = "+UserMapper.class.getSuperclass());
	}
}
