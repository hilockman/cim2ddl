package com.znd.bus.binding;

import java.lang.reflect.Method;
import java.lang.reflect.Proxy;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import com.znd.bus.buffer.Buffer;

public class MapperProxyFactory<T> {
	  private final Class<T> mapperInterface;
	  private final String tableName;
	  private final Map<Method, MapperMethod> methodCache = new ConcurrentHashMap<Method, MapperMethod>();

	  public MapperProxyFactory(Class<T> mapperInterface) {
	    this(mapperInterface, null);
	  }
	  
	  public MapperProxyFactory(Class<T> mapperInterface, String tableName) {
		    this.mapperInterface = mapperInterface;
		    this.tableName = tableName;
	  }

	  public Class<T> getMapperInterface() {
	    return mapperInterface;
	  }


	  @SuppressWarnings("unchecked")
	  protected T newInstance(MapperProxy<T> mapperProxy) {
	    return (T) Proxy.newProxyInstance(mapperInterface.getClassLoader(), new Class[] { mapperInterface }, mapperProxy);
	  }

	  public T newInstance(Buffer sqlSession) {
	    final MapperProxy<T> mapperProxy = new MapperProxy<T>(sqlSession, mapperInterface, methodCache, tableName);
	    return newInstance(mapperProxy);
	  }
	  
	  public static class Parser {
		  //private Class<?> type;
		  public Parser(Class<?> type) {
			 //this.type = type;
		  }
		public void parse() {			
//			Method[] methods = type.getMethods();
//			for (Method method : methods) {
//				Parameter[] parameters = method.getParameters();
//				List<String> argNames = new ArrayList<>();
//				for (Parameter parameter : parameters) {
//					argNames.add(parameter.getName());
//				}
//			}
 		}
	  }
}
