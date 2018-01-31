package com.znd.ei.buffer.imp;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.znd.ei.buffer.BufferConfig;
import com.znd.ei.buffer.BufferFactory;
import com.znd.ei.buffer.BufferFactoryBuilder;
import com.znd.ei.buffer.Buffer;

public class BufferFactoryImp implements BufferFactory {
	private BufferConfig config;
	private DFService service;
	private RMemDBApi memDBApi; 
	private RMemDBBuilder memDBBuilder;
	private final Logger logger = LoggerFactory.getLogger(BufferFactoryBuilder.class);
	
	public BufferFactoryImp(BufferConfig config, DFService service, RMemDBApi memDBApi, RMemDBBuilder memDBBuilder)
	{
		this.config = config;
		this.service = service;
		this.memDBApi = memDBApi;
		this.memDBBuilder = memDBBuilder;
	}
	
	
	public Buffer openSession()   {
		return new BufferImp(this);
	}
	
	public Buffer openSession(boolean autoCommit)   {
		return new BufferImp(this, autoCommit);
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

	public RMemDBApi getMemDBApi() {
		return memDBApi;
	}

	public void setMemDBApi(RMemDBApi memDBApi) {
		this.memDBApi = memDBApi;
	}

	public RMemDBBuilder getMemDBBuilder() {
		return memDBBuilder;
	}

	public void setMemDBBuilder(RMemDBBuilder memDBBuilder) {
		this.memDBBuilder = memDBBuilder;
	}

	public BufferConfig getConfig() {
		return config;
	}

	public void setConfig(BufferConfig config) {
		this.config = config;
	}
}
