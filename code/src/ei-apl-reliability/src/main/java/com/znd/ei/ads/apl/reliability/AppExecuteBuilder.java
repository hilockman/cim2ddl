package com.znd.ei.ads.apl.reliability;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.ads.apl.reliability.AppUtil;

public class AppExecuteBuilder {
	String appPath;
	List<String> parameters = new ArrayList<String>();
	AppLogger appLogger;
	
	public AppExecuteBuilder(String appName) {
		this.appPath = appName;
	}
	
	public AppExecuteBuilder addParam(String param) {
		parameters.add(param);
		return this;
	}
	
	public AppExecuteBuilder logger(AppLogger appLogger)
	{
		this.appLogger = appLogger;
		return this;
	}
	public void exec() {
		AppUtil.execute(appPath, appLogger, parameters.toArray(new String[0]));
	}
	
}
