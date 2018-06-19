package com.znd.ads.property;

import java.util.HashMap;
import java.util.Map;

import com.znd.ads.mapper.ForeignKeysMapper;

public class PropertyRegistory {

	private final Map<Class<?>, PropertyResolver> resolverMap = new HashMap<>();
	private final Map<String, PropertyResolver> resolverNameMap = new HashMap<>();
	
	private ForeignKeysMapper mapper;
	public PropertyRegistory(ForeignKeysMapper mapper) {
		this.mapper = mapper;
	}
	
	public void addType(Class<?> type) {
		PropertyResolver resolver = new PropertyResolver(type, mapper);
		resolverMap.put(type, resolver);
		
		if (resolverNameMap.containsKey(resolver.getName())) {
			throw new PropertyException("Type duplicate : name ="+resolver.getName()+", type = "+type+", exist type = "+resolverNameMap.get(resolver.getName()));
		}
		resolverNameMap.put(resolver.getName(), resolver);
		
	}
	
	
	public PropertyResolver getResolver(Class<?> type) {
		return resolverMap.get(type);
	}
	
	public PropertyResolver getResolver(String name) {
		PropertyResolver resolver = resolverNameMap.get(name);
		if (resolver == null) {
			throw new PropertyException("Unknow property type :"+name);
		}
		return resolver;
	}
}
