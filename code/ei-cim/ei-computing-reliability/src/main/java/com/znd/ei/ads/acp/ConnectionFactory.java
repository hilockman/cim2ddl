package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.DataFieldStorage;

public interface ConnectionFactory {
	DBOperations getDBOperations();
	
	ListOperations getListOperations();

	BusOperations getBusOperations();
	
	void register(DataFieldStorage manager);
}
