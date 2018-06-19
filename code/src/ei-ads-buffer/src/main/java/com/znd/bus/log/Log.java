package com.znd.bus.log;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

import com.znd.bus.annotation.Index;

public class Log {

	@Index
	private String id;
	
	private Date date;
	private LogLevel logLevel;
	private String content;
	
	public static void main(String[] args) {
		System.out.println(LogLevel.DEBUG);
		System.out.println(LogLevel.ERROR);
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public LogLevel getLogLevel() {
		return logLevel;
	}

	public void setLogLevel(LogLevel logLevel) {
		this.logLevel = logLevel;
	}

	public String getContent() {
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}

	public Date getDate() {
		return date;
	}

	public void setDate(Date date) {
		this.date = date;
	}
	
	public static final DateFormat FORMAT = new SimpleDateFormat("yyyy-MM-dd hh:mm:ss.SSS");
	
	@Override
	public String toString() {
		return "Log [id=" + id + ", date=" + FORMAT.format(date) + ", logLevel="
				+ logLevel + ", content=" + content + "]";
	}
}
