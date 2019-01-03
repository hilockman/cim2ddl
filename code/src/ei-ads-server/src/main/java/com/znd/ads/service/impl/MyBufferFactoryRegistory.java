package com.znd.ads.service.impl;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

import org.springframework.stereotype.Component;

import com.znd.ads.exception.FactoryException;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.exception.MessageException;

@Component
public class MyBufferFactoryRegistory {
	private final  Map<String, MyBufferFactory> bufferFactoryMap = new ConcurrentHashMap<>();
	
	public MyBufferFactory getFactory(String dbid) throws FactoryException {
		if (bufferFactoryMap.containsKey(dbid)) {
			return bufferFactoryMap.get(dbid);
		}
		
		MyBufferFactory factory;
		try {
			factory = new MyBufferFactory(dbid);
		} catch (BindingException | BufferException | MessageException e) {
			throw new FactoryException(e);
		}
		bufferFactoryMap.put(dbid, factory);
		return factory;
	}

	public void put(String name, MyBufferFactory myBufferFactory) {
		bufferFactoryMap.put(name, myBufferFactory);
	}
	
}
