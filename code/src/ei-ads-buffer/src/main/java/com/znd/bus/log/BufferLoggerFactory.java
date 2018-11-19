package com.znd.bus.log;

import java.util.List;

import com.znd.bus.log.defaults.DefaultLogger;

public class BufferLoggerFactory {
	
	
	
	public static class LogBufferWrapper implements LogBuffer {
		private LogBuffer logBuffer;
		
		@Override
		public void save(Log info) {
			if (logBuffer == null)
				return;
			logBuffer.save(info);				
		}

		@Override
		public void delete(Log info) {
			// TODO Auto-generated method stub			
		}

		@Override
		public List<Log> findAll() {
			// TODO Auto-generated method stub
			return null;
		}

		public LogBuffer getLogBuffer() {
			return logBuffer;
		}

		public void setLogBuffer(LogBuffer logBuffer) {
			this.logBuffer = logBuffer;
		}
		
	}
	
	
	public static LogBufferWrapper logBuffer = new LogBufferWrapper();
	
	public static BufferLogger getLogger(Class<?> clazz)
	{
		return new DefaultLogger(clazz, logBuffer);
	}
}
