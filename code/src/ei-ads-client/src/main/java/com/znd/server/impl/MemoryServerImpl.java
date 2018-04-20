package com.znd.server.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ei.memdb.Connection;
import com.znd.ei.memdb.DbEntry;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.MetaTable;
import com.znd.server.MemoryServer;



@Service
public class MemoryServerImpl implements MemoryServer {

	@Autowired
	private DbEntryOperations[] dbOps;
	
	@Autowired 
	private DbEntryCollection collection;
	
	@Override
	public Connection[] getConnections() {
		Connection[] connections = new Connection[dbOps == null ? 0 : dbOps.length];
		if (connections.length == 0) {
			return connections;
		}
		for (int i = 0; i < dbOps.length; i++) {
			connections[i] = dbOps[i].getConnection();
		}
		
		return connections;
	}

	@Override
	public List getTables(String dbName) {
		DbEntry dbEntry = collection.findDbEntry(dbName);
		if (dbEntry == null)
			return null;
		
		return dbEntry.getTables();
	}

	@Override
	public List getRecords(String dbName, String tableName) {
		DbEntry dbEntry = collection.findDbEntry(dbName);
		if (dbEntry == null)
			return null;
		
		MetaTable table = dbEntry.findTableByName(tableName);
		if (table == null)
			return null;
		
		
		try {
			return dbEntry.findAllRecords(table);
		} catch (DbException e) {			
			e.printStackTrace();
			return null;
		}
	}

	@Override
	public int getRecordSize(String dbName, String tableName) {
		DbEntry dbEntry = collection.findDbEntry(dbName);
		if (dbEntry == null)
			return 0;
		
		MetaTable table = dbEntry.findTableByName(tableName);
		if (table == null)
			return 0;
		
		
		
		return (int) dbEntry.getRecordCount(table);
		
	}


}
