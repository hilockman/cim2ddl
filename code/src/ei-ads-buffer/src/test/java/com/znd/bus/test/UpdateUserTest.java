package com.znd.bus.test;

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
public class UpdateUserTest {
	@Autowired
	private BufferFactory factory;
	
    @Test
    public void update() {
    	System.out.println("------------------------start SelectUserTest.getOne()----------------------------"); 
    	
    	Buffer buffer = factory.openSession(false);
    	UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
    	
    	User user = mapper.findUserById("1");
    	if (user != null) {
    		System.out.println("Find user :  "+ user);	
    	}
    	
    	user.setName(user.getName()+"_test");
    	mapper.updateUser(user);
    	
    	user = mapper.findUserById("1");
    	if (user != null) {
    		System.out.println("Find user :  "+ user);	
    	}
    	
    	

    	buffer.close();
    	System.out.println("------------------------end SelectUserTest.getOne()----------------------------");
    }
}
