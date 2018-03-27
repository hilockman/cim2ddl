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
public class InsertUserTest {
	
	@Autowired
	private BufferFactory factory;
	
    @Test
    public void insert100000Records() {
    	System.out.println("------------------------start UserMapperTest.insert100000Records()----------------------------"); 
    	
    	Buffer buffer = factory.openSession(false);
    	UserMapper mapper = factory.config().getMapper(UserMapper.class, buffer);
    	
    	List<User> users = new ArrayList<>();
    	for (int i = 0; i < 10000; i++) {
    		User user = new User();
    		user.setId(""+i);;
    		user.setName("user"+i);
    		users.add(user);
    	}
    	mapper.insertUsers(users);
    	
    	buffer.commit();
    	buffer.close();
    	
    	try {
			Thread.sleep(3000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	System.out.println("------------------------end UserMapperTest.insert100000Records()----------------------------");
    }
}
