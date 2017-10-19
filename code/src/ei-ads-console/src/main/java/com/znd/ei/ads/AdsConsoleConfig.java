package com.znd.ei.ads;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.acp.AbstractConnectionFactory;
import com.znd.ei.ads.acp.ConnectionFactory;

@Configuration
@EnableAutoConfiguration
public class AdsConsoleConfig {
	
	@Bean
	public 	AdsServer adsServer(ConnectionFactory connectionFactory) {
		AbstractConnectionFactory acf = (AbstractConnectionFactory)connectionFactory;
		
		AdsServer server =  new AdsServerImp();
		acf.setAdsServer(server);
		return server;
	}
}
