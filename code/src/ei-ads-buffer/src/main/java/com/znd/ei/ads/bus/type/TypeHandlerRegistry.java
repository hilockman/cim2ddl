package com.znd.ei.ads.bus.type;

import java.lang.reflect.Type;
import java.sql.Time;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public final class TypeHandlerRegistry {

	
	private final Map<Class<?>, TypeHandler<?>> ALL_TYPE_HANDLERS_MAP = new HashMap<Class<?>, TypeHandler<?>>();
	public TypeHandlerRegistry() {
		register(Boolean.class, new BooleanTypeHandler());
		register(boolean.class, new BooleanTypeHandler());
		register(Integer.class, new IntegerTypeHandler());
		register(int.class, new IntegerTypeHandler());
		register(Short.class, new ShortTypeHandler());
		register(short.class, new ShortTypeHandler());
		register(String.class, new StringTypeHandler());
		register(char[].class, new CharArrayTypeHandler());
		register(Float.class, new FloatTypeHandler());
		register(float.class, new FloatTypeHandler());
		register(Double.class, new DoubleTypeHandler());
		register(double.class, new DoubleTypeHandler());
		register(Long.class, new LongTypeHandler());
		register(long.class, new LongTypeHandler());
		register(Date.class, new DateTypeHandler());
		register(Byte[].class, new ByteObjectArrayTypeHandler());
		register(byte[].class, new ByteArrayTypeHandler());
		
	}
	  private void register(Class<?> javaType, TypeHandler<?> handler) {
	
		    ALL_TYPE_HANDLERS_MAP.put(javaType, handler);
	  }
	  
	  public TypeHandler<?> getTypeHandler(Class<?> type) {
		    return ALL_TYPE_HANDLERS_MAP.get(type);
	 }
	public boolean hasTypeHandler(Class<?> type) {
		return ALL_TYPE_HANDLERS_MAP.containsKey(type);
	}	  
}
