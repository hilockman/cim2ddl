package com.znd.ei;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.redisson.api.RKeys;
import org.redisson.api.RedissonClient;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class ClearRedissonTest {
	@Autowired
	RedissonClient client;
	
	@Test
	public void flushDB() {
		RKeys key = client.getKeys();
		
		key.flushdb();
		System.out.println("Succed to flushdb!");
		
	}
}
