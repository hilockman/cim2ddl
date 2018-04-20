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

import com.znd.bus.test.mapper.PersonMapper;
import com.znd.bus.test.model.Person;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest

public class PersonMapperTest {

	@Autowired
	private PersonMapper mapper;
	
	
	@Test
	public void insertOne() {
		System.out.println("------------------PersonMapperTest.insertOne---------------------start");
		Person p = new Person();
		p.setId("1");
		p.setName("PERSON1");
		p.setAddress("address1");
		mapper.insert(p);
		System.out.println("------------------PersonMapperTest.insertOne---------------------end");
	}
	
	@Test
	public void insertList() {
		System.out.println("------------------PersonMapperTest.insertOne---------------------start");
		List<Person> persons = new ArrayList<>(); 
		for (int i = 0; i < 10; i++){
			Person p = new Person();
			p.setId(""+i);
			p.setName("PERSON1");
			p.setAddress("address1");
			persons.add(p);
			
		}
		mapper.insertList(persons);
		System.out.println("------------------PersonMapperTest.insertOne---------------------end");
	}	
}
