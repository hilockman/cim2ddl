package com.znd.ei.ads;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.dfredisson.DFRedissonConnection;

@Configuration
@EnableAutoConfiguration
public class Config {

	@Bean
	public ConnectionFactory acpConnection() {
		ConnectionFactory conn =  new DFRedissonConnection();
		//conn.registerApplication(name, app);
		return conn;
	}
}
