package com.znd.server.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ei.memdb.Connection;
import com.znd.ei.memdb.DbEntry;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.MetaField;
import com.znd.ei.memdb.MetaTable;
import com.znd.server.MemoryServer;



@Service
public class MemoryServerImpl implements MemoryServer {

	public static class DbInfo {
		private String name;
		private String alias;
		private Integer tableSize;
		public String getName() {
			return name;
		}
		public void setName(String name) {
			this.name = name;
		}
		public String getAlias() {
			return alias;
		}
		public void setAlias(String alias) {
			this.alias = alias;
		}
		public Integer getTableSize() {
			return tableSize;
		}
		public void setTableSize(Integer tableSize) {
			this.tableSize = tableSize;
		}
		@Override
		public String toString() {
			return "DbInfo [name=" + name + ", alias=" + alias + ", tableSize="
					+ tableSize + "]";
		}

	}
	
	public static class TableInfo {
		private String name;
		private String alias;
		private Integer recordSize;
		public String getName() {
			return name;
		}
		public void setName(String name) {
			this.name = name;
		}
		public String getAlias() {
			return alias;
		}
		public void setAlias(String alias) {
			this.alias = alias;
		}
		public Integer getRecordSize() {
			return recordSize;
		}
		public void setRecordSize(Integer recordSize) {
			this.recordSize = recordSize;
		}
		@Override
		public String toString() {
			return "TableInfo [name=" + name + ", alias=" + alias
					+ ", recordSize=" + recordSize + "]";
		}
	}
	
	public static class ColumnInfo {
		private String name;
		private String alias;
		
		public String getName() {
			return name;
		}
		public void setName(String name) {
			this.name = name;
		}
		public String getAlias() {
			return alias;
		}
		public void setAlias(String alias) {
			this.alias = alias;
		}
		@Override
		public String toString() {
			return "ColumnInfo [name=" + name + ", alias=" + alias + "]";
		}
	}
	@Autowired
	private DbEntryOperations[] dbOps;
	
	@Autowired 
	private DbEntryCollection collection;
	
	@Override
	public List getConnections() {
		
		List<DbInfo> dbInfos = new ArrayList<>();
		Connection[] connections = new Connection[dbOps == null ? 0 : dbOps.length];
		if (connections.length == 0) {
			return dbInfos;
		}
		for (int i = 0; i < dbOps.length; i++) {
			Connection conn = dbOps[i].getConnection();
			
			DbInfo dbInfo = new DbInfo();
			dbInfo.setName(conn.getName());
			dbInfo.setAlias(conn.getDesc());
			dbInfo.setTableSize(dbOps[i].getTables().size());
			dbInfos.add(dbInfo);
		}
		
		return dbInfos;
	}

	@Override
	public List getTables(String dbName) {
		List<TableInfo> tables = new ArrayList<>();
		DbEntry dbEntry = collection.findDbEntry(dbName);
		if (dbEntry == null)
			return null;
		
		for (MetaTable m : dbEntry.getTables()) {
			TableInfo table = new TableInfo();
			table.setName(m.getName());
			table.setAlias(m.getDescription());
			table.setRecordSize((int) dbEntry.getRecordCount(m));
			tables.add(table);
		}
		
		return tables;
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

	@Override
	public List getTableColumnList(String dbName, String tableName) {
		List<ColumnInfo> columnInfos = new ArrayList<>();
		DbEntry dbEntry = collection.findDbEntry(dbName);
		if (dbEntry == null)
			return null;
		
		MetaTable table = dbEntry.findTableByName(tableName);
		if (table == null)
			return null;
		
		List<MetaField> fields = table.getFields();
		for (int i = 0; i < fields.size(); i++) {
			ColumnInfo columnInfo = new ColumnInfo();
			MetaField f = fields.get(i);
			columnInfo.setName(f.getName());
			columnInfo.setAlias(f.getDescription());
			columnInfos.add(columnInfo);
		}
		return columnInfos;
	}


}
