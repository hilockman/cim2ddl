package com.znd.ei.ads.acp.dfredisson;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.acp.ConnectionFactory;

@Configuration
@EnableAutoConfiguration
public class ConnectionConfig {

	@Bean
	public ConnectionFactory acpConnection() {
		ConnectionFactory conn =  new DFRedissonConnection();
		return conn;
	}
	


}
