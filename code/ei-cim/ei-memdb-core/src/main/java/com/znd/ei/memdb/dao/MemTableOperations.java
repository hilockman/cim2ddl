package com.znd.ei.memdb.dao;

import java.util.List;

import com.znd.ei.memdb.connection.Connection;

public interface MemTableOperations {
	List<MemTable> getTables();
	String[] getTableNames();
	MemTable findTableByName(String name);
	
	void saveRecord(MemTable table, String [] values) throws MemDbError;
	void saveRecords(MemTable table, List<String []> records) throws MemDbError;
	List<String []> findAllRecords(MemTable table) throws MemDbError;
	long getRecordCount(MemTable table);
	void deleteRecords(MemTable table, List<String[]> records) throws MemDbError;
	void deleteRecord(MemTable table, String[] record) throws MemDbError;
	void clearTable(MemTable table);
		
	/**
	 * 清除数据库
	 */
	void clearDb();
	
	Connection getConnection();
}
