package com.znd.ei.reliability.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.Service.RedisService;
import com.ZhongND.RedisDF.Service.ServiceFactory;
import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.ZhongND.RedisDF.exectueDF.ExectueDF;

@Configuration
@EnableAutoConfiguration
public class DFConfig {

	@Bean
	public RedisService redisService() throws RedissonDBException {
		return ServiceFactory.getService();
	}
	
	@Bean
	public DFService dfService(RedisService redisService) throws RedissonDBException {
		return redisService.getDFService();
	}
	
	@Bean
	public ExectueDF redisControl(DFService dfService, ReliabilityProperites properties) throws RedissonDBException {
		return dfService.registry(properties.getAppName());
	}
}
