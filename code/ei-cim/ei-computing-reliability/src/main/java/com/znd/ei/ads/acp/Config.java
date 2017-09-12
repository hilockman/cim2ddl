package com.znd.ei.ads.acp;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.acp.impl.DFConnection;

@Configuration
@EnableAutoConfiguration
public class Config {

	@Bean
	public ConnectionFactory acpConnection() {
		ConnectionFactory conn =  new DFConnection();
		//conn.registerApplication(name, app);
		return conn;
	}
}
