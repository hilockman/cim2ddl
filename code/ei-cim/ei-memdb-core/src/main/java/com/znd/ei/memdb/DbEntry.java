package com.znd.ei.memdb;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;

import com.ZhongND.memdb.JMemDBApi;

public class DbEntry extends DbComponent implements DbEntryOperations  {
	
	public static String MEM_INDEX_COLUMN_NAME = "memIndex";
	
	private static List<MemTable> tables;
	private static HashMap<String, MemTable> tableMap;

	private Connection connection;
	private String dbname;


	public DbEntry(Connection connection) {
		this.setConnection(connection);

		dbname = connection.getName();
		JMemDBApi.initMemDB(dbname, 0, 1);
		int tableNum = JMemDBApi.getTableNum(dbname);
		System.out
				.println("Init memdb, dbname:" + dbname + ", table num:" + tableNum + ".");
		tables = new ArrayList<MemTable>();
		tableMap = new HashMap<String, MemTable>();
		for (int i = 0; i < tableNum; i++) {
			MemTable table = new MemTable();
			table.setName(JMemDBApi.getTableName(dbname, i));
			table.setDescription(JMemDBApi.getTableDesp(dbname, i));

			int fieldNum = JMemDBApi.getTableFieldNum(dbname, i);
			for (int j = 0; j < fieldNum; j++) {
				MemField field = new MemField();
				field.setName(JMemDBApi.getFieldName(dbname, i, j));
				field.setDescription(JMemDBApi.getFieldDesp(dbname, i, j));
				int type = JMemDBApi.getFieldType(dbname, i, j);
				field.setLen(JMemDBApi.getFieldLen(dbname, i, j));
				switch (type) {
				case 1:
				case 2:
				case 3:
				case 8:
					field.setType(MemDbDataType.INTEGER);
					break;
				case 4:
				case 5:
					field.setType(MemDbDataType.DOUBLE);
					break;
				case 6:
					field.setType(MemDbDataType.STRING);
					break;
				default:
					field.setType(MemDbDataType.UNKNOWN);
					break;
				}

				table.addField(field);
				field.setIndex(j);

			}
			table.setIndex(i);

			int rFieldNum = JMemDBApi.getTableRestrictNum(dbname, i);
			ArrayList<MemField> keyFields = new ArrayList<MemField>();
			for (int j = 0; j < rFieldNum; j++) {
				int fileIndex = JMemDBApi.getTableRestrictField(dbname, i, j);
				MemField field = table.getFiled(fileIndex);
				field.setPrimeKey(true);
				keyFields.add(field);
			}

			table.setKeyFields(keyFields);

			tables.add(table);
			tableMap.put(table.getName(), table);
		}
	}

	public List<MemTable> getTables() {
		return tables;
	}

	@Override
	public String[] getTableNames() {
		String[] names = new String[tables.size()];
		for (int i = 0; i < names.length; i++) {
			names[i] = tables.get(i).getName();
		}
		return names;
	}

	@Override
	public MemTable findTableByName(String name) {
		return tableMap.get(name);
	}

	@Override
	public Integer saveRecord(MemTable table, String[] values) throws DbException {
		List<String[]> records = new ArrayList<String[]>();
		records.add(values);
		List<Integer> rt = saveRecords(table, records);
		if (rt.isEmpty())
			throw new DbException("saveRecord");
		
		JMemDBApi.maint(dbname, 0);
		return rt.get(0);
	}

	@Override
	public List<Integer> saveRecords(MemTable table, List<String[]> records)
			throws DbException {
		if (records.size() == 0)
			return new ArrayList<Integer>();
		
		List<Integer> rows = new ArrayList<Integer>();
		int count = JMemDBApi.getTableRecordNum(dbname, table.getIndex());
		for (int i = 0; i < records.size(); i++) {
			int rt = JMemDBApi.appendRecord(dbname, 0, table.getIndex(),
					records.get(i));
			if (rt < 0)
				throw new DbException(rt, "saveRecords");

			rows.add(count++);
		}

		JMemDBApi.maint(dbname, 0);
		
		return rows;
	}
	
	@Override
	public void updateRecords(MemTable table, List<String[]> records)
			throws DbException {
		if (records.size() == 0)
			return;
		for (int i = 0; i < records.size(); i++) {
			int rt = JMemDBApi.updateRecord(dbname, table.getIndex(), records.get(i));

			if (rt < 0)
				throw new DbException(rt, "updateRecord");

		}

		JMemDBApi.maint(dbname, 0);	
	}  

	public void deleteRecords(MemTable table, List<String[]> records) throws DbException {
		if (records.size() == 0)
			return;
		
		for (String[] record: records) {
			int recordIndex = JMemDBApi.findRecordbyRow(dbname, table.getIndex(),record);	
			JMemDBApi.removeRecord(dbname, table.getIndex(), recordIndex);
		}
		
		JMemDBApi.maint(dbname, 0);
	}
	
	public void deleteRecord(MemTable table, String[] record) throws DbException {
		
		List<String[]> records = new ArrayList<String[]>();
		records.add(record);
		deleteRecords(table, records);
	}	


	public void clearTable(MemTable table) {
		JMemDBApi.clearTable(dbname, table.getIndex());
		JMemDBApi.maint(dbname, 0);
	}
	@Override
	public List<String[]> findAllRecords(MemTable table) throws DbException {
		int count = JMemDBApi.getTableRecordNum(dbname, table.getIndex());
		List<String[]> records = new ArrayList<String[]>();
		for (int i = 0; i < count; i++) {
			records.add(JMemDBApi.getRecordRowValueArray(dbname,
					table.getIndex(), i));
		}

		return records;
	}
	
	
	

	@Override
	public long getRecordCount(MemTable table) {
		return JMemDBApi.getTableRecordNum(dbname, table.getIndex());
	}

	@Override
	public void clearDb() {
		for (int i = 0; i < tables.size(); i++) {
			JMemDBApi.clearTable(dbname, i);
		}

	}

	public Connection getConnection() {
		return connection;
	}

	public void setConnection(Connection connection) {
		this.connection = connection;
	}

    public String getName()  {  
        return connection.getName();
    }  
      
    public String getDescription()  {  
       return connection.getDesc();
    }

	@Override
	public void print() {
		System.out.println("DbEntry:"+getName());
	}

	@Override
	public Iterator<?> createIterator() {
		return new NullIterator();
	}


}

@SuppressWarnings("rawtypes")
class NullIterator implements Iterator {

	@Override
	public boolean hasNext() {
		return false;
	}

	@Override
	public Object next() {
		return null;
	}
	
}
