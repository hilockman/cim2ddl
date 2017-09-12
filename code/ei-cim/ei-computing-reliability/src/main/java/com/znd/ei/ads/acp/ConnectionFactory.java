package com.znd.ei.ads.acp;

import com.znd.ei.ads.apl.AppTemplate;
import com.znd.ei.ads.apl.DBOperations;

public interface ConnectionFactory {

	
	void registerApplication(String name, AppTemplate app);

	DBOperations getDBOperations();
	ListOperations getListOperations();
}
