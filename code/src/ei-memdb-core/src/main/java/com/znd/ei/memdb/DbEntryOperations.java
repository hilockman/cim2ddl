package com.znd.ei.memdb;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

public interface DbEntryOperations {
	List<MemTable> getTables();
	String[] getTableNames();
	MemTable findTableByName(String name);
	
	Integer saveRecord(MemTable table, String [] values) throws DbException;
	List<Integer> saveRecords(MemTable table, List<String []> records) throws DbException;
	void updateRecords(MemTable table, List<String []> records) throws DbException;
	List<String []> findAllRecords(MemTable table) throws DbException;
	long getRecordCount(MemTable table);
	void deleteRecords(MemTable table, List<String[]> records) throws DbException;
	void deleteRecord(MemTable table, String[] record) throws DbException;
	void clearTable(MemTable table);
		
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
