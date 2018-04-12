package com.znd.bus.test;

import java.util.Set;

import org.junit.Test;

import com.znd.bus.binding.ResolverUtil;

public class UtilsTest {

	@Test
	public void testSplit() {
		String[] strs = "a;b,c".split(";|,");
		for (String str : strs) {
			System.out.println(str);
		}
	}
	
	@Test
	public void testResolveClass() {
		 ResolverUtil<Class<?>> resolverUtil = new ResolverUtil<Class<?>>();
		
		    resolverUtil.find(new ResolverUtil.IsA(Object.class), "com.znd.bus.test");
		    Set<Class<? extends Class<?>>> mapperSet = resolverUtil.getClasses();
		    for (Class<?> mapperClass : mapperSet) {
		      System.out.println(mapperClass.getName());
		    }
	}
}
