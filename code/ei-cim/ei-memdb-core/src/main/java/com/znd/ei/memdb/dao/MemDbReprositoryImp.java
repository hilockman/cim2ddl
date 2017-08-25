package com.znd.ei.memdb.dao;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

import org.springframework.stereotype.Repository;

import com.ZhongND.memdb.JMemDBApi;
import com.ZhongND.memdb.MDBDefine;

@Repository
public class MemDbReprositoryImp implements MemDbRepository {
	private static List<MemTable> tables;
	private static HashMap<String, MemTable> tableMap;

	private static String dbname;
	static {
		dbname = MDBDefine.g_strPRDBEntry;
		JMemDBApi.initMemDB(dbname, 0, 1);
		int tableNum = JMemDBApi.getTableNum(dbname);
		System.out
				.println("dbname:" + dbname + ", table num:" + tableNum + ".");
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
	public void saveRecord(MemTable table, String[] values) throws MemDbError {
		int rt = JMemDBApi.insertRecord(dbname, table.getIndex(), values) ;
		if (rt < 0)
			throw new MemDbError(rt, "saveRecord");
		JMemDBApi.maint(dbname, 0);
	}

	@Override
	public void saveRecords(MemTable table, List<String[]> records) throws MemDbError {
		for (int i = 0; i < records.size(); i++) {
			int rt = JMemDBApi.appendRecord(dbname, 0, table.getIndex(), records.get(i));
			if (rt < 0)
				throw new MemDbError(rt, "saveRecord");
			
	}
	
	JMemDBApi.maint(dbname, 0);	
}

	@Override
	public List<String[]> findAllRecords(MemTable table) throws MemDbError {
		int count = JMemDBApi.getTableRecordNum(dbname, table.getIndex());
		List<String[]>  records = new ArrayList<String[]>();
		for (int i = 0; i < count; i++) {
			records.add(JMemDBApi.getRecordRowValueArray(dbname, table.getIndex(), i));
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

}
