package com.znd.ei.ads;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.apl.AplContainer;

@Configuration
@EnableAutoConfiguration
public class ADSCofnig {

//	@Bean
//	public AplContainer aplManager() {
//		AplContainer manager = new AplContainer();
//		return manager;
//	}
//	
//	@Bean
//	public DataFieldStorage dataFieldStorage(ServerProperties serverProperties, ConnectionFactory acpConnection, AplContainer aplManager) {
//		DataFieldStorage dataFieldStorage = new DataFieldStorage(serverProperties, acpConnection, aplManager);
//		return dataFieldStorage;
//	}
}
