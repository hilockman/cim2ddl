package com.znd.ei.ads.apl;

import com.znd.ei.ads.acp.DataFactory;

public abstract class AppTemplate<T> {
	private DataFactory dataFactory;
	private ApplicationInfo applicationInfo;


	//上传数据结果
	public void flushData(T o) {
		dataFactory.upload(o);
	}


	public ApplicationInfo getApplicationInfo() {
		return applicationInfo;
	}


	public void setApplicationInfo(ApplicationInfo applicationInfo) {
		this.applicationInfo = applicationInfo;
	}


	public DataFactory getDataFactory() {
		return dataFactory;
	}


	public void setDataFactory(DataFactory dataFactory) {
		this.dataFactory = dataFactory;
	}
	

}
