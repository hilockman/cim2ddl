package com.ei.ads.server;

import java.util.Set;

import org.junit.Test;

import com.znd.ei.Utils;

public class ClassFindTest {

	@Test
	public void test() {
	   
	   Utils.getClasses("com.znd.bus.common.buffer", null);
	    Set<Class<?>> mapperSet = Utils.getClasses("com.znd.bus.common.buffer", null);
	    for (Class<?> mapperClass : mapperSet) {
	      System.out.println(mapperClass.getName());
	    }
	}
}
