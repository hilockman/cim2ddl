package com.znd.bus.test;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;

import org.junit.Test;

import com.znd.bus.test.mapper.UserMapper;


public class SimpleTest {

	@Test
	public void test() throws NoSuchMethodException, SecurityException {
		System.out.println(UserMapper.class.getName());
		Class<?> type = UserMapper.class;
		Method method = type.getMethod("findAll");
		Type returnType = method.getGenericReturnType();
		if (returnType instanceof ParameterizedType) {
			ParameterizedType gtype = (ParameterizedType)returnType;
			Type[] typeArgs = gtype.getActualTypeArguments();
			System.out.println("returnType="+gtype);
			System.out.println("actualType="+typeArgs[0]);
			
			Type rawType = gtype.getRawType();
			System.out.println("rawType="+rawType);
		}
		
		
		
		
		
	}
}
