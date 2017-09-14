package com.znd.ei.ads.apl;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.IOOperations;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.DataItem;

public abstract class AppTemplate {
	private ConnectionFactory connectionFactory;	
	private ApplicationInfo applicationInfo;
	private DataFieldStorage storage;

	public ApplicationInfo getApplicationInfo() {
		return applicationInfo;
	}


	public void setApplicationInfo(ApplicationInfo applicationInfo) {
		this.applicationInfo = applicationInfo;
	}

	@SuppressWarnings({ "unchecked", "rawtypes" })
	public void writeDataField(String cc, DataItem data, IOOperations io) throws ACPException {

		data.setAppName(applicationInfo.getName());
		data.setCode(applicationInfo.getOutputCC());
		
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
