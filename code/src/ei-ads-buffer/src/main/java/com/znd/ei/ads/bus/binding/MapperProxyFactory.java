package com.znd.ei.ads.bus.binding;

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.lang.reflect.Proxy;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.config.BufferConfig;

public class MapperProxyFactory<T> {
	  private final Class<T> mapperInterface;
	  private final Map<Method, MapperMethod> methodCache = new ConcurrentHashMap<Method, MapperMethod>();

	  public MapperProxyFactory(Class<T> mapperInterface) {
	    this.mapperInterface = mapperInterface;
	  }

	  public Class<T> getMapperInterface() {
	    return mapperInterface;
	  }


	  @SuppressWarnings("unchecked")
	  protected T newInstance(MapperProxy<T> mapperProxy) {
	    return (T) Proxy.newProxyInstance(mapperInterface.getClassLoader(), new Class[] { mapperInterface }, mapperProxy);
	  }

	  public T newInstance(Buffer sqlSession) {
	    final MapperProxy<T> mapperProxy = new MapperProxy<T>(sqlSession, mapperInterface, methodCache);
	    return newInstance(mapperProxy);
	  }
	  
	  public static class Parser {
		  private BufferConfig config;
		  private Class<?> type;
		  public Parser(BufferConfig config, Class<?> type) {
			 this.config = config;
			 this.type = type;
		  }
		public void parse() {			
			Method[] methods = type.getMethods();
			for (Method method : methods) {
				Parameter[] parameters = method.getParameters();
				List<String> argNames = new ArrayList<>();
				for (Parameter parameter : parameters) {
					argNames.add(parameter.getName());
				}
			}
 		}
	  }
}
