package com.znd.ei.ads.bus.reflection;

public class ArrayWrapper implements ObjectWrapper {

	private final String[] values;
	public ArrayWrapper(MetaObject metaObject, String[] values) {
		this.values = values;
	}

	@Override
	public Object get(String prop) {
		return values[Integer.valueOf(prop.substring(5))];
	}

	@Override
	public void set(String prop, Object value) {
		values[Integer.valueOf(prop.substring(5))] = (String)value;
	}

}
