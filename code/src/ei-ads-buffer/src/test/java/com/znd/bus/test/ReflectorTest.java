package com.znd.bus.test;

import java.util.Arrays;

import org.junit.Test;

import com.znd.ads.model.po.LogInfo;
import com.znd.ads.model.po.User;
import com.znd.ads.model.po.UserInfo;
import com.znd.bus.common.model.AdsNodeInfo;
import com.znd.bus.reflection.Reflector;

public class ReflectorTest {

	
	@Test
	public void testFildOrder() {
	
		Class<?>[] clazzes = {AdsNodeInfo.class,User.class, UserInfo.class, LogInfo.class};
		for (Class<?> clazz : clazzes) {
		 Reflector rf = new Reflector(clazz);
		 String[] names = rf.getGetablePropertyNames();
		 System.out.println("class : +"+clazz+", columns:["+Arrays.asList(names)+"]");
		}
	}
}
