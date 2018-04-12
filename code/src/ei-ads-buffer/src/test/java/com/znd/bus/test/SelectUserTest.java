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
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.test.mapper.UserMapper;
import com.znd.bus.test.model.User;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class SelectUserTest {
	@Autowired
	private BufferFactory factory;
	
    @Test
    public void getAll() {
    	System.out.println("------------------------start SelectUserTest.getAll()----------------------------"); 
    	
    	Buffer buffer = factory.openSession(false);
    	UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
    	
    	List<User> users = mapper.findAll();
    	for (User user : users) {
    		System.out.println(user);
    	}
    	
    	System.out.println("User count = "+ users.size());

    	buffer.close();
    	System.out.println("------------------------end SelectUserTest.getAll()----------------------------");
    }
    
    
    @Test
    public void getOne() {
    	System.out.println("------------------------start SelectUserTest.getOne()----------------------------"); 
    	
    	Buffer buffer = factory.openSession(false);
    	UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
    	
    	User user = mapper.findById("1");
    	if (user != null) {
    		System.out.println("Find user :  "+ user);	
    	}
    	
    	
    	buffer.close();
    	System.out.println("------------------------end SelectUserTest.getOne()----------------------------");
    }
}
