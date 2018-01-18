package com.znd.ei.memdb;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public interface DbEntryOperations {
	String getName();
	 String getDescription();
	List<MetaTable> getTables();
	String[] getTableNames();
	MetaTable findTableByName(String name);
	
	Integer saveRecord(MetaTable table, String [] values) throws DbException;
	List<Integer> saveRecords(MetaTable table, List<String []> records) throws DbException;
	void updateRecords(MetaTable table, List<String []> records) throws DbException;
	List<String []> findAllRecords(MetaTable table) throws DbException;
	long getRecordCount(MetaTable table);
	void deleteRecords(MetaTable table, List<String[]> records) throws DbException;
	void deleteRecord(MetaTable table, String[] record) throws DbException;
	void clearTable(MetaTable table);
		
	/**
	 * 清除数据库
	 */
	void clearDb();
	
	Connection getConnection();
	
	public static final Map<String, DbEntryOperations> ALL_DB_OPS = new HashMap<String, DbEntryOperations>();
	public static DbEntryOperations find(String entryName) {
		return ALL_DB_OPS.get(entryName);
	}
}
