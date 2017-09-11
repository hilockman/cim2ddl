package com.znd.ei.adf.acp;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.adf.acp.impl.DFConnection;

@Configuration
@EnableAutoConfiguration
public class Config {

	@Bean
	Connection acpConnection() {
		Connection conn =  new DFConnection();
		//conn.registerApplication(name, app);
		return conn;
	}
}
