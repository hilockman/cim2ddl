package com.znd.ei.ads.apl.reliability;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class AppExecuteBuilder {
	String appPath;
	List<String> parameters = new ArrayList<String>();
	AppLogger appLogger; 
	
	Process process;
	ProcessBuilder builder;
	public AppExecuteBuilder(String appName) {
		this.appPath = appName;
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
	public void exec() {
		
		process = AppUtil.execute(appPath, appLogger, parameters.toArray(new String[0]));
	}
	
	public static void main(String [] args) {
		
	}
	public void start() {
		List<String> params = new ArrayList<String>();
		params.addAll(parameters);
		params.add(0, appPath);
		
		StringBuffer cmd = new StringBuffer();
		cmd.append(appPath);
		for (String param : params) {
			cmd.append(" "+param);
		}
		if (appLogger != null) {
			appLogger.print(cmd.toString());
		} else
			System.out.println(cmd);
		
		builder = new 	ProcessBuilder(params.toArray(new String[0]));
		try {
			process = builder.start();
			InputStream is = process.getInputStream();
			AppUtil.print(is, appLogger);
			
			InputStream eis = process.getErrorStream();
			AppUtil.print(eis, appLogger);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void terminate() {
		if (process != null)
			process.destroy();
	}
}
