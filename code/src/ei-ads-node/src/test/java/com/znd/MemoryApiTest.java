package com.znd;

import org.junit.Test;

import com.ZhongND.memdb.JMemDBApi;
import com.ZhongND.memdb.MDBDefine;

public class MemoryApiTest {

	String toString(String [] strs) {
		StringBuilder b = new StringBuilder();
		b.append('[');
		for (int i = 0; i < strs.length; i++) {
			if (i > 0)
				b.append(',');
			b.append(strs[i]);
		}
		b.append(']');
		return b.toString();
	}
	@Test
	public void testStartMemoryStart() {
		
		//System.out.println(System.getenv("java.library.path"));
		String entry = MDBDefine.g_strPRDBEntry;
		JMemDBApi.initMemDB(entry, 0, 1);
		int nTableIndex = JMemDBApi.getTableIndex(entry, "FState");
		int num = JMemDBApi.getTableFieldNum(entry, nTableIndex);
		System.out.println("tableIndex:" + nTableIndex);
		System.out.println("num:" + num);
		for (int i = 0; i < num; i++)
		{
			String sFieldName = JMemDBApi.getFieldName(entry, nTableIndex, i);
			
			System.out.println(i + ":" + sFieldName);

		}
		
		
		int size = JMemDBApi.getTableRecordNum(entry, nTableIndex);
		for (int i = 0; i < size; i++) {
			System.out.println(toString(JMemDBApi.getRecordRowValueArray(entry, nTableIndex, i)));
		}
		
	}
	
	
}
