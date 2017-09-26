package com.znd.ei.codegen.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.memdb.connection.Connection;
import com.znd.ei.memdb.dao.MemTableOperations;
import com.znd.ei.memdb.dao.MemTableOperationsImp;

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
	public MemTableOperations pROps() {
		Connection conn = new Connection();
		conn.setEntryName(MDBDefine.g_strPRDBEntry);
		conn.setDesc(MDBDefine.g_strPRDBEntryDesp);
		String packageName = "com.znd.ei.memdb.reliability";
		conn.setTargetPackage(packageName);
		MemTableOperations ops = new MemTableOperationsImp(conn);
			
		return ops;
	}
}
