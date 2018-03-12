package com.znd.ei.ads.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;


@Configuration
@EnableAutoConfiguration
public class MemoryConfig {

	
	@Bean
	public DbEntryOperations[] dbOps(DbEntryCollection c) throws DbException {
		String[] entryNames = MDBDefine.g_strDBEntryArray;
		DbEntryOperations[] opss = new DbEntryOperations[entryNames.length];
		int index = 0;

		for (String entryName : entryNames) {
			DbEntryOperations ops = c.findOrCreateDbEntry(entryName);
			opss[index++] = ops;
		}

		return opss;
	}
}