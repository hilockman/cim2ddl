package com.znd.bus.buffer.defaults;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.log.BufferLogger;
import com.znd.bus.log.BufferLoggerFactory;
import com.znd.bus.log.LogBuffer;
import com.znd.bus.log.defaults.DefaultLogger;
import com.znd.bus.task.CalcTaskList;
import com.znd.bus.task.DefaultCalcTaskList;

public class DefaultBufferFactory implements BufferFactory {
	private BufferConfig config;

	private final Logger logger = LoggerFactory.getLogger(BufferFactoryBuilder.class);

	
		
	public DefaultBufferFactory(BufferConfig config)
	{	
		config.buildAll();
				
		this.config = config;
		
		Buffer buffer = openSession(true);
		LogBuffer mapper = config.getMapper(LogBuffer.class, buffer);
		BufferLoggerFactory.logBuffer.setLogBuffer(mapper);
	}
	
	public Buffer openSession()   {
		return openSession(true);
	}
	
	public Buffer openSession(boolean autoCommit)   {		
		Buffer b = new DefaultBuffer(config, config.getBufferContext(), autoCommit);
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


	@Override
	public <E> CalcTaskList<E> taskList(String taskName) {
		return new DefaultCalcTaskList<E>(taskName, config.getBufferContext());
	}
	
	
//	@Override
//	public BufferLogger logger() {	
//		return defaultLogger;
//	}
//	
}
