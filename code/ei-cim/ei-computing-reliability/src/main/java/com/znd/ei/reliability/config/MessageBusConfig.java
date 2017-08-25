package com.znd.ei.reliability.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.Service.RedisService;
import com.ZhongND.RedisDF.Service.ServiceFactory;

@Configuration
@EnableAutoConfiguration
public class MessageBusConfig {

	@Bean
	public RedisService redisService() {
		return ServiceFactory.getService();
	}
	
	@Bean
	public DFService dfService(RedisService redisService) {
		return redisService.getDFService();
	}
	
	@Bean
	public RedisControl redisControl(DFService dfService) {
		return dfService.registry("ComputeReliability");
	}
}
