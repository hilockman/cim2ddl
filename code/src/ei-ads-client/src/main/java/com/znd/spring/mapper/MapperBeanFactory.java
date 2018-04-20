package com.znd.spring.mapper;

import org.springframework.beans.factory.FactoryBean;

import com.znd.bus.buffer.Buffer;

public class MapperBeanFactory<T> implements FactoryBean<T> {

     
    private Class<T> mapperInterface;  

    private Buffer buffer;
    
    
    public MapperBeanFactory(Class<T> mapperInterface) {
    	this.mapperInterface = mapperInterface;
    }
	@Override
	public T getObject() throws Exception {
        return buffer.getConfig().getMapper(mapperInterface, buffer);
	}

	@Override
	public Class<?> getObjectType() {
		return mapperInterface;
	}


	public Buffer getBuffer() {
		return buffer;
	}
	public void setBuffer(Buffer buffer) {
		this.buffer = buffer;
	}

}
