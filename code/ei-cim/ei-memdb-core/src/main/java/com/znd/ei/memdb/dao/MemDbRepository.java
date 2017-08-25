package com.znd.ei.memdb.dao;

import java.util.List;

public interface MemDbRepository {
	public List<MemTable> getTables();
	public String[] getTableNames();
	public MemTable findTableByName(String name);
	
	public void saveRecord(MemTable table, String [] values) throws MemDbError;
	public void saveRecords(MemTable table, List<String []> records) throws MemDbError;
	public List<String []> findAllRecords(MemTable table) throws MemDbError;
	public long getRecordCount(MemTable table);
	
	/**
	 * 清除数据库
	 */
	public void clearDb();
}
