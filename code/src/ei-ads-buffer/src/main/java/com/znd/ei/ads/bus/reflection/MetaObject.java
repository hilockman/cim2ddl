package com.znd.ei.ads.bus.reflection;

import java.util.Map;

public class MetaObject {

	private final Object object;
		
	private final ObjectWrapper objectWrapper;
	
	private MetaObject(Object object, ReflectorFactory reflectorFactory) {
		this.object = object;
		
	    if (object instanceof ObjectWrapper) {
	        this.objectWrapper = (ObjectWrapper) object;
	      } else if (object instanceof Map) {
	        this.objectWrapper = new MapWrapper(this, (Map) object);
	      } else if (object.getClass().isArray()) {
	    	 this.objectWrapper = new ArrayWrapper(this, (String [])object);
	      } else {
	        this.objectWrapper = new BeanWrapper(this, object, reflectorFactory);
	      }
	    
		
	}
	
	public static MetaObject forObject(Object object, ReflectorFactory reflectorFactory) {
		return new MetaObject(object, reflectorFactory);
	}

	public Object getValue(String property) {
		
		return objectWrapper.get(property);		
	}
	
	public void setValue(String property, Object value) {
		objectWrapper.set(property, value);
	}

	public Object getObject() {
		return object;
	}

}
