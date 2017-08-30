package com.znd.ei.reliability.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.Service.RedisService;
import com.ZhongND.RedisDF.Service.ServiceFactory;
import com.ZhongND.RedisDF.db.DBAccess.Exception.JedisDBException;

@Configuration
@EnableAutoConfiguration
public class DFConfig {

	@Bean
	public RedisService redisService() {
		return ServiceFactory.getService();
	}
	
	@Bean
	public DFService dfService(RedisService redisService) throws JedisDBException {
		return redisService.getDFService();
	}
	
	@Bean
	public RedisControl redisControl(DFService dfService, ReliabilityProperites properties) throws JedisDBException {
		return dfService.registry(properties.getAppName());
	}
}
