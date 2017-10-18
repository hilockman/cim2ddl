package com.znd.ei.memdb;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;

@Configuration
@EnableAutoConfiguration
public class MemConfig {

	@Bean
	public DbEntryOperations pROps(DbEntryCollection c) throws DbException {
		return c.findOrCreateDbEntry(MDBDefine.g_strPRDBEntry);
	}
	
	@Bean
	public DbEntryOperations bPAOps(DbEntryCollection c) throws DbException {
		return c.findOrCreateDbEntry(MDBDefine.g_strBpaDBEntry);
	}
}
