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

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.test.mapper.UserInfoMapper;
import com.znd.bus.test.model.UserInfo;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class InsertUserInfoTest {
	@Autowired
	private BufferFactory factory;
	
    @Test
    public void insert100000Records() {
    	System.out.println("------------------------start UserInfoMapperTest.insert100000Records()----------------------------"); 
    	
    	Buffer buffer = factory.openSession(false);
    	UserInfoMapper mapper = factory.config().getMapper(UserInfoMapper.class, buffer);
    	
    	List<UserInfo> users = new ArrayList<>();
    	for (int i = 0; i < 10000; i++) {
    		UserInfo user = new UserInfo();
    		user.setId(""+i);;
    		user.setName("user"+i);
    		users.add(user);
    	}
    	mapper.insertList(users);
    	
    	buffer.commit();
    	buffer.close();
    	
    	try {
			Thread.sleep(3000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    	System.out.println("------------------------end UserInfoMapperTest.insert100000Records()----------------------------");
    }
}
