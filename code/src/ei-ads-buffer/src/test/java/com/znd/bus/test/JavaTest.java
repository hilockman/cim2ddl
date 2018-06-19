package com.znd.bus.test;

import org.junit.Test;


public class JavaTest {

	@Test
	public void testEnum() {
		if (MyEnum.class.isEnum()) {
			System.out.println("is enum : "+MyEnum.class);
		}
		
		if (MyEnum.class.isAssignableFrom(Object.class)) {
			System.out.println("is object : "+MyEnum.class);
		}
	}
}
