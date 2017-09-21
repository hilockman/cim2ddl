package com.znd.ei.memdb.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.memdb.connection.Connection;
import com.znd.ei.memdb.dao.MemDbRepository;
import com.znd.ei.memdb.dao.MemDbReprositoryImp;

@Configuration
@EnableAutoConfiguration
public class Config {

	@Bean
	public Connection pRDbConnection() {
		Connection conn = new Connection();
		conn.setEntryName(MDBDefine.g_strPRDBEntry);
		conn.setDesc(MDBDefine.g_strPGDBEntryDesp);
		return conn;
	}
	
	@Bean
	public Connection bPADbConnection() {
		Connection conn = new Connection();
		conn.setEntryName(MDBDefine.g_strBpaDBEntry);
		conn.setDesc(MDBDefine.g_strBpaDBEntryDesp);
		return conn;
	}
	
	@Bean
	public MemDbRepository pRDbRepository(Connection pRDbConnection) {
		MemDbRepository repository = new MemDbReprositoryImp(pRDbConnection);
		return repository;
	}
}
