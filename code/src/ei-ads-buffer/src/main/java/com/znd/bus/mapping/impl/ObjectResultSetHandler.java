package com.znd.bus.mapping.impl;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import com.znd.bus.mapping.ParameterMapping;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.mapping.ResultSetHandler;
import com.znd.bus.reflection.MetaObject;
import com.znd.bus.reflection.Reflector;
import com.znd.bus.reflection.ReflectorFactory;
import com.znd.bus.type.TypeHandler;
import com.znd.bus.type.TypeHandlerRegistry;

public class ObjectResultSetHandler<Object> implements ResultSetHandler<Object> {
	private final Class<?> type;
	private final Reflector reflector;
	private final ReflectorFactory reflectorFactory;
	private TypeHandlerRegistry typeHandlerRegistry;
	private final Map<String, Integer> propertyIndexMap;
	
	public ObjectResultSetHandler(Class<?> type, ReflectorFactory reflectorFactory, TypeHandlerRegistry typeHandlerRegistry, Map<String, Integer> propertyIndexMap) {
		this.type = type;
		this.reflectorFactory = reflectorFactory;
		reflector = reflectorFactory.findForClass(type);
		this.typeHandlerRegistry = typeHandlerRegistry;
		this.propertyIndexMap = propertyIndexMap;
		
	}
	@Override
	public List<Object> handle(ResultSet rs) {
		
		
		
		List<Object> rt = new ArrayList<>();
		Constructor<?> constructor = reflector.getDefaultConstructor();
		//System.out.println(">>>>>>>>>>>>>>>>>>ObjectResultSetHandler.handle, type="+constructor.getDeclaringClass());
		
		String[] properties = reflector.getSetablePropertyNames();
		
		TypeHandler[] typeHandlers = new TypeHandler[properties.length];
		int i = 0;
		for (String property : properties) {
			TypeHandler typeHandler = typeHandlerRegistry.getTypeHandler(reflector.getGetterType(property));
			typeHandlers[i] = typeHandler;
			i++;
		}
		
		while (rs.next()) {
			
			try {
				Object object = (Object) constructor.newInstance();
				MetaObject metaObject = MetaObject.forObject(object, reflectorFactory);
				 i = 0;
				for (String property : properties) {
					TypeHandler typeHandler = typeHandlers[i];
					Integer index = propertyIndexMap.get(property);
					if (typeHandler != null && index != null && index >= 0) {
						
						Object value = (Object)typeHandler.getResult(rs, index);
						if (value != null)
						   metaObject.setValue(property, value);
					}
					
					i++;
				}
				rt.add(object);
			} catch (InstantiationException | IllegalAccessException
					| IllegalArgumentException | InvocationTargetException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return rt;
	}

}
