package com.znd.ei.ads.bus.mapping;

import java.lang.reflect.Field;

public class ObjectReflector {

	private Class<?> type;
	public ObjectReflector(Class<?> type) {
		Field[] fields = type.getFields();
	}
}
