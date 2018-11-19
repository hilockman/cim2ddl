package com.znd;

import java.util.List;

import org.junit.Assert;

import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MetaTable;

public class TestUtils {
	public static void print(DbEntryOperations ops) {
		List<MetaTable> tables = ops.getTables();
		int sum = 0;
		for (MetaTable table : tables) {
			 long count = ops.getRecordCount(table);
			if (count == 0)
				continue;
			
			sum += count;
			System.out.println(String.format("%s(%d)", table.getName(), count));
		}
		String log = String.format("%s db load , record sum = %d > 0.", ops.getName(), sum);
		System.out.println(log);
		Assert.assertTrue(log, sum > 0);
	}
}
