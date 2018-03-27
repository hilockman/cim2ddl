package com.znd.ei.ads.bus.buffer.defaults;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.buffer.BufferFactory;
import com.znd.ei.ads.bus.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.bus.config.BufferConfig;

public class DefaultBufferFactory implements BufferFactory {
	private BufferConfig config;

	private final Logger logger = LoggerFactory.getLogger(BufferFactoryBuilder.class);
	
	public DefaultBufferFactory(BufferConfig config)
	{
		this.config = config;

	}
	
	
	public Buffer openSession()   {
		return openSession(true);
	}
	
	public Buffer openSession(boolean autoCommit)   {		
		Buffer b = new DefaultBuffer(config, config.getBufferContext(), autoCommit);
		logger.info("Buffer opened : " + config.getKey());
		return b;
	}
	

	public void destory() {
		config.getBufferContext().close();
		logger.info("Service disconnected: {}.{} .", config.getAppName(), config.getName());
	}





	public BufferConfig getConfig() {
		return config;
	}

	public void setConfig(BufferConfig config) {
		this.config = config;
	}




	@Override
	public BufferConfig config() {
		return config;
	}
}