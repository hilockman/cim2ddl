package com.znd.ei.ads.acp.impl;

import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.ListOperations;
import com.znd.ei.ads.apl.AppTemplate;
import com.znd.ei.ads.apl.DBOperations;

public class DFConnection implements ConnectionFactory {

	@Override
	public void registerApplication(String name, AppTemplate app) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public DBOperations getDBOperations() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public ListOperations getListOperations() {
		// TODO Auto-generated method stub
		return null;
	}

}
