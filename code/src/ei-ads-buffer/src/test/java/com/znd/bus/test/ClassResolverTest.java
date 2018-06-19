package com.znd.bus.test;

import java.util.Set;

import org.junit.Test;

import com.znd.bus.binding.ResolverUtil;

public class ClassResolverTest {

	
	private void printClass(String packageName) {
		 ResolverUtil<Class<?>> resolverUtil = new ResolverUtil<Class<?>>();
		    resolverUtil.find(new ResolverUtil.IsA(Object.class), packageName);
		    Set<Class<? extends Class<?>>> mapperSet = resolverUtil.getClasses();
		    for (Class<?> mapperClass : mapperSet) {
		     System.out.println(mapperClass+"<-"+packageName);
		    }	
	}
	@Test
	public void testLoadTypes() {
	
		printClass("com.znd.ads.model.po");
		printClass("com.znd.bus.common.model");

		    
	}
}
