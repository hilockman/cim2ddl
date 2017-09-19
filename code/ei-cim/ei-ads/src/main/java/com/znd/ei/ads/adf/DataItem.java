package com.znd.ei.ads.adf;

import com.znd.ei.ads.acp.IOOperations;

public class DataItem {
	protected IOOperations operations;
//	private String contentCode;
	private String key;
//	private String appName;

	public String getKey() {
		return key;
	}

	public void setKey(String name) {
		this.key = name;
	}

//	public String getAppName() {
//		return appName;
//	}
//
//	public void setAppName(String appName) {
//		this.appName = appName;
//	}
//
//	public String getContentCode() {
//		return contentCode;
//	}
//
//	public void setContentCode(String code) {
//		this.contentCode = code;
//	}

	public IOOperations getOperations() {
		return operations;
	}

	public void setOperations(IOOperations operations) {
		this.operations = operations;
	}


}
