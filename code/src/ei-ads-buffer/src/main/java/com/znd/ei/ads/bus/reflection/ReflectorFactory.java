package com.znd.ei.ads.bus.reflection;


public interface ReflectorFactory {
	Reflector findForClass(Class<?> type);
}
