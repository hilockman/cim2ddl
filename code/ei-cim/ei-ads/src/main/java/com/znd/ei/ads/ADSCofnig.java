package com.znd.ei.ads;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.apl.AplManager;

@Configuration
@EnableAutoConfiguration
public class ADSCofnig {

	@Bean
	public AplManager aplManager(ConnectionFactory acpConnection) {
		AplManager manager = new AplManager(acpConnection);
		return manager;
	}
	
	@Bean
	public DataFieldStorage dataFieldStorage(ServerProperties serverProperties, ConnectionFactory acpConnection, AplManager aplManager) {
		DataFieldStorage dataFieldStorage = new DataFieldStorage(serverProperties, acpConnection, aplManager);
		return dataFieldStorage;
	}
}
