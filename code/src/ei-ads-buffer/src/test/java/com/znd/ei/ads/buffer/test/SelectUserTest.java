package com.znd.ei.ads.buffer.test;

import java.util.ArrayList;
import java.util.List;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.ei.ads.buffer.test.mapper.UserMapper;
import com.znd.ei.ads.buffer.test.model.User;
import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.buffer.BufferFactory;
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
    	
    	User user = mapper.findUserById("1");
    	if (user != null) {
    		System.out.println("Find user :  "+ user);	
    	}
    	
    	
    	buffer.close();
    	System.out.println("------------------------end SelectUserTest.getOne()----------------------------");
    }
}
