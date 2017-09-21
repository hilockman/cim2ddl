package com.znd.ei.ads.apl;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.IOOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.DataItem;

public abstract class AppTemplate {
	private ConnectionFactory connectionFactory;	
	private AppInfo appInfo;
	private DataFieldStorage storage;

	public AppInfo getAppInfo() {
		return appInfo;
	}


	public void setAppInfo(AppInfo applicationInfo) {
		this.appInfo = applicationInfo;
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	public void writeDataField(String cc, DataItem data, IOOperations io) throws ACPException, UnsupportedOperation {

		data.setAppName(appInfo.getName());
		data.setContentCode(cc);
		
		io.write(data);
	}


	public ConnectionFactory getConnectionFactory() {
		return connectionFactory;
	}


	public void setConnectionFactory(ConnectionFactory connectionFactory) {
		this.connectionFactory = connectionFactory;
	}


	public DataFieldStorage getStorage() {
		return storage;
	}


	public void setStorage(DataFieldStorage storage) {
		this.storage = storage;
	}

}
