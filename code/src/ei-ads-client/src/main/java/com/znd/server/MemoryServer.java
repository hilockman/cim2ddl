package com.znd.server;

import java.util.List;

import com.znd.ei.memdb.Connection;

public interface MemoryServer {

	
	Connection[] getConnections();

	List getTables(String dbName);

	List getRecords(String tableName, String tableName2);

	int getRecordSize(String dbName, String tableName);
}
