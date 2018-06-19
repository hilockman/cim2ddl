package com.znd.bus.test;

import java.util.ArrayList;
import java.util.List;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.ei.Utils;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class CalcJobBufferTest {

	@Autowired
	private CalcJobBuffer buffer;
	
	@Test
	public void testInsertList() {
		
		List<CalcJob> jobs = new ArrayList<>();
		for (int i = 0; i < 10; i++) {
			CalcJob job = new CalcJob();
			job.setId(Utils.randomKey());
			jobs.add(job);
		}
		
		buffer.insertList(jobs);
	}
}
