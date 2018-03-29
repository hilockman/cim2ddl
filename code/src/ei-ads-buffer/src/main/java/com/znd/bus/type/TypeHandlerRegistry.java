package com.znd.bus.type;

import java.lang.reflect.Constructor;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

public final class TypeHandlerRegistry {

	 private Class<? extends TypeHandler> defaultEnumTypeHandler = EnumTypeHandler.class;
	 
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
	  private TypeHandler<?> register(Class<?> javaType, TypeHandler<?> handler) {
	
		    ALL_TYPE_HANDLERS_MAP.put(javaType, handler);
		    return handler;
	  }
	  
	  @SuppressWarnings("unchecked")
	  public <T> TypeHandler<T> getInstance(Class<?> javaTypeClass, Class<?> typeHandlerClass) {
	    if (javaTypeClass != null) {
	      try {
	        Constructor<?> c = typeHandlerClass.getConstructor(Class.class);
	        return (TypeHandler<T>) c.newInstance(javaTypeClass);
	      } catch (NoSuchMethodException ignored) {
	        // ignored
	      } catch (Exception e) {
	        throw new TypeException("Failed invoking constructor for handler " + typeHandlerClass, e);
	      }
	    }
	    try {
	      Constructor<?> c = typeHandlerClass.getConstructor();
	      return (TypeHandler<T>) c.newInstance();
	    } catch (Exception e) {
	      throw new TypeException("Unable to find a usable constructor for " + typeHandlerClass, e);
	    }
	  }
	  
	  public TypeHandler<?> getTypeHandler(Class<?> type) {
		  if (hasTypeHandler(type))
			  return ALL_TYPE_HANDLERS_MAP.get(type);
		  else if (type.isEnum()) {
			  return register(type, getInstance(type, defaultEnumTypeHandler));
		  } else {
			  throw new TypeException("Unable to find a type handler for " + type);
		  }
				   
	 }
	public boolean hasTypeHandler(Class<?> type) {
		return ALL_TYPE_HANDLERS_MAP.containsKey(type);
	}	  
}
