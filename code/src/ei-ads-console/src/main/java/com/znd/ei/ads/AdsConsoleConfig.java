package com.znd.ei.ads;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.acp.ConnectionFactory;

@Configuration
@EnableAutoConfiguration
public class AdsConsoleConfig {
	
	@Bean
	public 	AdsServer adsServer(ConnectionFactory connectionFactory) {
		AdsServer server =  new AdsServerImp();
		connectionFactory.registerService(AdsServer.class, server);
		return server;
	}
}
