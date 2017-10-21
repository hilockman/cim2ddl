package com.znd.ei.ads.apl.reliability;

import com.ZhongND.memdb.JMemDBApi;
import com.ZhongND.memdb.MDBDefine;

public class TestMemory {

	public static void main(String[] args) {
		String dbEntry = MDBDefine.g_strPRDBEntry;
		JMemDBApi.initMemDB(dbEntry, 0, 1);

		String tableName = "FState";
		int nTable = JMemDBApi.getTableIndex(dbEntry, tableName);
		int nRecordNum = JMemDBApi.getTableRecordNum(dbEntry, nTable);
		System.out.println("tableName:" + tableName);
		for (int i = 0; i < nRecordNum; i++) {

			String[] rt = JMemDBApi.getRecordRowValueArray(dbEntry, nTable, i);
			System.out.println("recordIndex:" + i + ", rt = "
					+ String.join(",", rt));
		}

		// int nTable = JMemDBApi.getTableIndex(dbEntry, "ACBus");
		int nField = JMemDBApi.getFieldIndex(dbEntry, nTable, "name");
		System.out.println("nTable:" + nTable + ",nField:" + nField);

		int n = JMemDBApi.getTableRestrictNum(dbEntry, nTable);
		for (int i = 0; i < n; i++) {
			int rt = JMemDBApi.getTableRestrictField(dbEntry, nTable, i);
			System.out.println("key field = "+JMemDBApi.getFieldName(dbEntry, nTable, rt));
		}

		int nReocrd = JMemDBApi.findRecordbyKey(dbEntry, nTable,
				new String[] { "BUS_1" });
		System.out.println(nReocrd);
	}
}
