package com.znd.ei.ads.buffer.factory.defaults;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.znd.ei.ads.buffer.Buffer;
import com.znd.ei.ads.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.buffer.config.BufferConfig;
import com.znd.ei.ads.buffer.factory.BufferFactory;

public class DefaultBufferFactory implements BufferFactory {
	private BufferConfig config;
	private DFService service;
	//private RMemDBApi memDBApi; 
	RMemDBBuilder memDBBuilder;
	private final Logger logger = LoggerFactory.getLogger(BufferFactoryBuilder.class);
	
	public DefaultBufferFactory(BufferConfig config, DFService service, RMemDBBuilder memDBBuilder)
	{
		this.config = config;
		this.service = service;
		//this.memDBApi = memDBApi;
		this.memDBBuilder = memDBBuilder;
	}
	
	
	public Buffer openSession()   {
		return openSession(true);
	}
	
	public Buffer openSession(boolean autoCommit)   {		
		Buffer b = new DefaultBuffer(config, memDBBuilder, autoCommit);
		logger.info("Buffer opened : " + config.getKey());
		return b;
	}
	

	public void destory() {
		service.disConnect();
		logger.info("Service disconnected: {}.{} .", config.getAppName(), config.getName());
	}


	public DFService getService() {
		return service;
	}

	public void setService(DFService service) {
		this.service = service;
	}



	public BufferConfig getConfig() {
		return config;
	}

	public void setConfig(BufferConfig config) {
		this.config = config;
	}


	public RMemDBBuilder getMemDBBuilder() {
		return memDBBuilder;
	}
}
