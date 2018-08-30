package com.znd.reliability.utils;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;

public class AppExecuteBuilder {
	String appPath;
	List<String> parameters = new ArrayList<String>();
	AppLogger appLogger; 
	
	Process process;
	ProcessBuilder builder;
	Boolean appendAppPath = true;
	public AppExecuteBuilder(String appName) {
		this.appPath = appName;
	}
	public AppExecuteBuilder(String appName, boolean appendAppPath) {
		this.appPath = appName;
		this.appendAppPath = appendAppPath;
	}
	
//	public AppExecuteBuilder addParam(String param) {
//		parameters.add(param);
//		return this;
//	}
	
	public <T> AppExecuteBuilder addParam(T param) {
		parameters.add(param.toString());
		return this;
	}
	
	public AppExecuteBuilder logger(AppLogger appLogger)
	{
		this.appLogger = appLogger;
		return this;
	}
	public AppExecuteBuilder exec() {
		
		process = AppUtil.executeWithLogger(appPath, appLogger, parameters.toArray(new String[0]));
		return this;
	}
	
	public static void main(String [] args) {
		
	}
	
	
	public AppExecuteBuilder start() {
		List<String> params = new ArrayList<String>();
		params.addAll(parameters);
		params.add(0, appPath);
		
		StringBuffer cmd = new StringBuffer();
		if (appendAppPath)
			cmd.append(appPath+" ");
		for (String param : params) {
			cmd.append(param+" ");
		}
		if (appLogger != null) {
			appLogger.print(cmd.toString());
		} else
			System.out.println(cmd);
		
		builder = new 	ProcessBuilder(params.toArray(new String[0]));
		try {
			process = builder.start();
			if (appLogger != null) {
			InputStream is = process.getInputStream();
			AppUtil.print(is, appLogger);
			
			InputStream eis = process.getErrorStream();
			AppUtil.print(eis, appLogger);
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return this;
	}
	
	public void destroy() {
		if (process != null) {
			System.out.println("Destory "+appPath);
			process.destroy();
		}
	}
}
