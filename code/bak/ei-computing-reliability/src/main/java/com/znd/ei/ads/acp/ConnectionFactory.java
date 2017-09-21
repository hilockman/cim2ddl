package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.DataFieldStorage;

public interface ConnectionFactory {
	MemDBDataOperations getMemDBDataOperations();
	
	ListDataOperations getListOperations();

	//BusOperations getBusOperations();
	
	StringDataOperations getStringDataOperations();
	
	StringRefDataOperations getStringRefOperations();
	
	void register(DataFieldStorage manager);
	
	MapDataOperations getMapDataOperations();
}
