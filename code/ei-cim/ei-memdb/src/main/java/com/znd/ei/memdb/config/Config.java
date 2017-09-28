package com.znd.ei.memdb.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.memdb.AbstractTableOperations;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.reliabilty.domain.FState;

@Configuration
@EnableAutoConfiguration
public class Config {

//	@Bean
//	public Connection pRDbConnection() {
//		Connection conn = new Connection();
//		conn.setEntryName(MDBDefine.g_strPRDBEntry);
//		conn.setDesc(MDBDefine.g_strPGDBEntryDesp);
//		return conn;
//	}
//
//	@Bean
//	public Connection bPADbConnection() {
//		Connection conn = new Connection();
//		conn.setEntryName(MDBDefine.g_strBpaDBEntry);
//		conn.setDesc(MDBDefine.g_strBpaDBEntryDesp);
//		return conn;
//	}
//
//	@Bean
//	public MemTableOperations pRDbRepository(Connection pRDbConnection) {
//		MemTableOperations repository = new MemTableOperationsImp(
//				pRDbConnection);
//		return repository;
//	}

	@Bean
	public DbEntryOperations pROps(DbEntryCollection c) throws DbException {
		return c.findOrCreateDbEntry(MDBDefine.g_strPRDBEntry);
	}
	
	@Bean
	public DbEntryOperations bPAOps(DbEntryCollection c) throws DbException {
		return c.findOrCreateDbEntry(MDBDefine.g_strBpaDBEntry);
	}

}
