package com.znd.bus.reflection;

import java.util.Map;

public class MapWrapper implements ObjectWrapper {
	private final Map<String, Object> map;
	 protected final MetaObject metaObject;
	  
	public MapWrapper(MetaObject metaObject, Map map) {
		this.metaObject = metaObject;
		this.map = map;
	}

	@Override
	public Object get(String prop) {
		return map.get(prop);
	}

	@Override
	public void set(String prop, Object value) {
		map.put(prop, value);
	}

}
