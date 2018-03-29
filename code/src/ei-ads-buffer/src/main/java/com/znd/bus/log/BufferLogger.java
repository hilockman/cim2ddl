package com.znd.bus.log;


public interface BufferLogger {
	void log(LogLevel level, String format, Object ... arguments);
	
	void info(String format, Object ... arguments);
	
	void debug(String format, Object ... arguments);
	
	void error(String format, Object ... arguments);
	
	void warn(String format, Object ... arguments);
	
}
