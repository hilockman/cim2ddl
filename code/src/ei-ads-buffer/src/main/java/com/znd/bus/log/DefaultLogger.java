package com.znd.bus.log;

import java.util.Date;
import java.util.UUID;

public class DefaultLogger implements BufferLogger {

	private final LogBuffer mapper;
	public DefaultLogger(LogBuffer mapper)
	{
		this.mapper = mapper;
		
	}
	@Override
	public void log(LogLevel level, String content, Object ... arguments) {
		Log info = new Log();
		info.setId(UUID.randomUUID().toString());
		info.setDate(new Date());
		info.setLogLevel(level);
		info.setContent(String.format(content, arguments));
		mapper.save(info);
	}

	public void info(String content, Object ... arguments) {
		log(LogLevel.INFO, content, arguments);
	}
	
	public void debug(String content, Object ... arguments) {
		log(LogLevel.DEBUG, content, arguments);
	}
	
	public void error(String content, Object ... arguments) {
		log(LogLevel.ERROR, content, arguments);
	}
	
	public void warn(String content, Object ... arguments) {
		log(LogLevel.WARN, content, arguments);
	}

}
