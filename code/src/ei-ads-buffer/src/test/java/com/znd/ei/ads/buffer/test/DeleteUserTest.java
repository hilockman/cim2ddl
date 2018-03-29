package com.znd.ei.ads.buffer.test;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.ei.ads.buffer.test.mapper.UserMapper;
import com.znd.ei.ads.buffer.test.model.User;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class DeleteUserTest {
	@Autowired
	private BufferFactory factory;
	
    @Test
    public void delete() {
    	System.out.println("------------------------start DeleteUserTest.delete()----------------------------"); 
    	
    	Buffer buffer = factory.openSession(false);
    	UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
    	
    	User user = new User();
    	user.setId("1");
    	mapper.deleteUser(user);
    	
    	

    	buffer.close();
    	System.out.println("------------------------end DeleteUserTest.delete()----------------------------");
    }
}
