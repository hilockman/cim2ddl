package com.znd.bus.binding;

import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import com.znd.bus.binding.MapperProxyFactory.Parser;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.exception.BindingException;
import com.znd.bus.mapping.RawArrayBufferMapper;

public class MapperRegistry {

	  private final Map<Class<?>, MapperProxyFactory<?>> knownMappers = new HashMap<>();
	  private final Map<String, MapperProxyFactory<RawArrayBufferMapper>> defaultMappers = new HashMap<>();
	  public MapperRegistry() {
	  }

	  @SuppressWarnings("unchecked")
	  public <T> T getMapper(Class<T> type, Buffer buffer) {
	    final MapperProxyFactory<T> mapperProxyFactory = (MapperProxyFactory<T>) knownMappers.get(type);
	    if (mapperProxyFactory == null) {
	      throw new BindingException("Type " + type + " is not known to the MapperRegistry.");
	    }
	    try {
	      return mapperProxyFactory.newInstance(buffer);
	    } catch (Exception e) {
	      throw new BindingException("Error getting mapper instance. Cause: " + e, e);
	    }
	  }
	  
	  public RawArrayBufferMapper getMapper(String tableName, Buffer buffer) {
		    final MapperProxyFactory<RawArrayBufferMapper> mapperProxyFactory = defaultMappers.get(tableName);
		    if (mapperProxyFactory == null) {
		      throw new BindingException("Table " + tableName + " is not known to the MapperRegistry.");
		    }
		    try {
		      return mapperProxyFactory.newInstance(buffer);
		    } catch (Exception e) {
		      throw new BindingException("Error getting mapper instance. Cause: " + e, e);
		    }
	  }
		
	  public <T> boolean hasMapper(Class<T> type) {
	    return knownMappers.containsKey(type);
	  }

	  public  boolean hasMapper(String  tableName) {
		    return defaultMappers.containsKey(tableName);
	  }
	  
	  
	  public <T> void addMapper(Class<T> type) {
	    if (type.isInterface()) {
	      if (hasMapper(type)) {
	        throw new BindingException("Type " + type + " is already known to the MapperRegistry.");
	      }
	      boolean loadCompleted = false;
	      try {
	        knownMappers.put(type, new MapperProxyFactory<T>(type));
	        // It's important that the type is added before the parser is run
	        // otherwise the binding may automatically be attempted by the
	        // mapper parser. If the type is already known, it won't try.
//	        MapperAnnotationBuilder parser = new MapperAnnotationBuilder(config, type);
//	        parser.parse();
	        Parser builder = new MapperProxyFactory.Parser(type);
	        builder.parse();
	        loadCompleted = true;
	      } finally {
	        if (!loadCompleted) {
	          knownMappers.remove(type);
	        }
	      }
	    }
	  }
	  
	  public void addRawMapper(String tableName) {	  		  
	      if (hasMapper(tableName)) {
	        return;
	      }
	      
	      defaultMappers.put(tableName, new MapperProxyFactory<RawArrayBufferMapper>(RawArrayBufferMapper.class, tableName));	    
	}

	  /**
	   * @since 3.2.2
	   */
	  public Collection<Class<?>> getMappers() {
	    return Collections.unmodifiableCollection(knownMappers.keySet());
	  }

	  /**
	   * @since 3.2.2
	   */
	  public void addMappers(String packageName, Class<?> superType) {
	    ResolverUtil<Class<?>> resolverUtil = new ResolverUtil<Class<?>>();
	    resolverUtil.find(new ResolverUtil.IsA(superType), packageName);
	    Set<Class<? extends Class<?>>> mapperSet = resolverUtil.getClasses();
	    for (Class<?> mapperClass : mapperSet) {
	      addMapper(mapperClass);
	    }
	  }

	  /**
	   * @since 3.2.2
	   */
	  public void addMappers(String packageName) {
	    addMappers(packageName, Object.class);
	  }


}
