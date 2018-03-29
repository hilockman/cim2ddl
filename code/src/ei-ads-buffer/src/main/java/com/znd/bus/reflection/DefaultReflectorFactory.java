package com.znd.bus.reflection;

import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ConcurrentMap;

public class DefaultReflectorFactory implements ReflectorFactory {
	  private final ConcurrentMap<Class<?>, Reflector> reflectorMap = new ConcurrentHashMap<Class<?>, Reflector>();
	  public DefaultReflectorFactory() {
	  }
	  
	@Override
	public Reflector findForClass(Class<?> type) {	 
          // synchronized (type) removed see issue #461
	      Reflector cached = reflectorMap.get(type);
	      if (cached == null) {
	        cached = new Reflector(type);
	        reflectorMap.put(type, cached);
	      }
	      return cached;
  
	}

}
