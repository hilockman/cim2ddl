package com.znd.bus.binding;

import java.lang.invoke.MethodHandles;
import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.lang.reflect.TypeVariable;
import java.util.Map;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.MappingError;
import com.znd.bus.mapping.RawArrayBufferMapper;

public class MapperProxy<T> implements InvocationHandler{

	private final Buffer buffer;
	private final Class<T> mapperInterface;
	private final Map<Method, MapperMethod> methodCache;
	private String tableName;  
	
	public MapperProxy(Buffer buffer, Class<T> mapperInterface,Map<Method, MapperMethod> methodCache, String tableName)
	{
		this.buffer = buffer;
		this.mapperInterface = mapperInterface;
		this.methodCache = methodCache;
		this.tableName = tableName;
	}
	
	
	




	@Override
	public Object invoke(Object proxy, Method method, Object[] args)
			throws Throwable {
	    try {
	        if (Object.class.equals(method.getDeclaringClass())) {
	          return method.invoke(this, args);
	        } else if (isDefaultMethod(method)) {
	          return invokeDefaultMethod(proxy, method, args);
	        }
	      } catch (Throwable t) {
	        throw new BindingException(t.getMessage(), t);
	      }
	      final MapperMethod mapperMethod = cachedMapperMethod(method);
	      return mapperMethod.execute(buffer, args);
	}
	
	
	  private Object invokeDefaultMethod(Object proxy, Method method, Object[] args)
		      throws Throwable {
		    final Constructor<MethodHandles.Lookup> constructor = MethodHandles.Lookup.class
		        .getDeclaredConstructor(Class.class, int.class);
		    if (!constructor.isAccessible()) {
		      constructor.setAccessible(true);
		    }
		    final Class<?> declaringClass = method.getDeclaringClass();
		    return constructor
		        .newInstance(declaringClass,
		            MethodHandles.Lookup.PRIVATE | MethodHandles.Lookup.PROTECTED
		                | MethodHandles.Lookup.PACKAGE | MethodHandles.Lookup.PUBLIC)
		        .unreflectSpecial(method, declaringClass).bindTo(proxy).invokeWithArguments(args);
		  }
	  
	  /**
	   * Backport of java.lang.reflect.Method#isDefault()
	   */
	  private boolean isDefaultMethod(Method method) {
	    return (method.getModifiers()
	        & (Modifier.ABSTRACT | Modifier.PUBLIC | Modifier.STATIC)) == Modifier.PUBLIC
	        && method.getDeclaringClass().isInterface();
	  }  
	  
	  
	  private MapperMethod cachedMapperMethod(Method method) throws BindingException, MappingError {
		    MapperMethod mapperMethod = methodCache.get(method);
		    if (mapperMethod == null) {
		    	 synchronized(method) {
		    		 if (methodCache.containsKey(method)) {
		    			 return methodCache.get(method);
		    		 }
				      BufferConfig config = buffer.getConfig();				      
				      mapperMethod = new MapperMethod(mapperInterface, method, config.getTypeHandlerRegistry(), tableName);
				      config.initMappedStatement(mapperMethod.getMethodType(), mapperMethod.getName(), method, mapperMethod.getReturnTypeArgument(), mapperInterface, tableName);
				      methodCache.put(method, mapperMethod);
		    	 }
		    }
		    return mapperMethod;
		  }
}
