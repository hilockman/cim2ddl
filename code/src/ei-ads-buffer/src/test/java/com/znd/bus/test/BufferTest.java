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


@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class BufferTest {

	@Autowired
	private Buffer defaultBuffer;
	
	@Test
	public void getRecords() {
		
		List<String []> records = defaultBuffer.selectList("User");
		
		for (String [] record : records) {
			System.out.println(String.join(",", record));
		}
	}
}
