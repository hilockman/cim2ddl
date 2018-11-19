package com.znd.bus.log.defaults;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Date;
import java.util.UUID;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.bus.log.BufferLogger;
import com.znd.bus.log.Log;
import com.znd.bus.log.LogBuffer;
import com.znd.bus.log.LogLevel;

public class DefaultLogger implements BufferLogger {
	private Logger logger;

	private LogBuffer mapper;
	
	private String clazz;
	public static String HOST_NAME;
	{
        InetAddress ip;
		try {
			ip = InetAddress.getLocalHost();
			HOST_NAME = ip.getHostName();
				
		} catch (UnknownHostException e) {
		}
	}
	public DefaultLogger(Class<?> clazz, LogBuffer mapper)
	{
		this.clazz = clazz.getName();
		this.logger = LoggerFactory.getLogger(clazz);	
		this.mapper = mapper;
	}
	
	private  String format(String message, Object...args) {
		 if (message == null)
			 return null;
		 
		 String pattern = "(\\{\\s*\\})";
		 
	      // 创建 Pattern 对象
	      Pattern r = Pattern.compile(pattern);
	 
	      
		 Matcher m = r.matcher(message);

		 StringBuilder builder = new StringBuilder();
		 int pos = 0;
		 int index = 0;
		 while (m.find()) {		
			Object object = ((index < args.length ) ? args[index] : null);
			builder.append(message.substring(pos, m.start()));
			builder.append(object != null ? object.toString() : "");
			pos = m.end();
			index++;
		 }
		 
		 if (pos < message.length()) {
			 builder.append(message.substring(pos));
		 }
		 
		 return builder.toString();
	}
	
	@Override
	public void log(LogLevel level, String content, Object ... arguments) {
		Log info = new Log();
		info.setId(UUID.randomUUID().toString());
		info.setDate(new Date());
		info.setLogLevel(level);
		info.setContent(format(content, arguments));
		info.setHostName(HOST_NAME);
		info.setClazz(clazz);
       
		switch(level) {
		case ERROR:
			logger.error(info.getContent());
		case WARN:
			logger.warn(info.getContent());
			break;
		case DEBUG:
			logger.debug(info.getContent());
		case INFO:
			logger.info(info.getContent());
			break;
		}
		if (mapper != null)
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
	public LogBuffer getMapper() {
		return mapper;
	}
	public void setMapper(LogBuffer mapper) {
		this.mapper = mapper;
	}

}
