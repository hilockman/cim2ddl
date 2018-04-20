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

import com.znd.bus.test.mapper.FStateMapper;
import com.znd.bus.test.model.FState;
import com.znd.bus.test.model.Person;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest

public class FStateMapperTest {

	@Autowired
	private FStateMapper mapper;
	

	@Test
	public void insertOneWithNullKey() {
		System.out.println("------------------FStateMapperTest.insertOneWithNullKey---------------------start");
		FState p = new FState();
		//p.setId(0);
		p.setFStateID(1);
		p.setDurition(.1);
		mapper.insert(p);
		System.out.println("------------------FStateMapperTest.insertOneWithNullKey---------------------end");
	}
	
//	@Test
//	public void insertList() {
//		System.out.println("------------------FStateMapperTest.insertOne---------------------start");
//		List<FState> persons = new ArrayList<>(); 
//		for (int i = 0; i < 10; i++){
//			FState p = new FState();
//			p.setId(i);
//			p.setFStateID(i);
//			p.setDurition(.1*i);
//			persons.add(p);
//			
//		}
//		mapper.insertList(persons);
//		System.out.println("------------------FStateMapperTest.insertOne---------------------end");
//	}	
}
