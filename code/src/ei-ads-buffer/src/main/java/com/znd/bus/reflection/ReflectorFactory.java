package com.znd.bus.reflection;


public interface ReflectorFactory {
	Reflector findForClass(Class<?> type);
}
