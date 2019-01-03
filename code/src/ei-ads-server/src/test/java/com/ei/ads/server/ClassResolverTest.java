package com.ei.ads.server;

import java.util.Set;

import org.junit.Test;

import com.znd.bus.binding.ResolverUtil;

public class ClassResolverTest {

	
	@Test public void test() {
	    ResolverUtil<Class<?>> resolverUtil = new ResolverUtil<Class<?>>();
	    resolverUtil.find(new ResolverUtil.IsA(Object.class), "com.znd.bus.common.buffer");
	    Set<Class<? extends Class<?>>> mapperSet = resolverUtil.getClasses();
	    for (Class<?> mapperClass : mapperSet) {
	      System.out.println(mapperClass.getName());
	    }
	}
}
