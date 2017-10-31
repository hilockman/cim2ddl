package com.znd.ei.ads.web;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.RedisADF.ADFService.ADFService;
import com.ZhongND.RedisADF.ADFService.ADFServiceEntry;
import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.Service.RedisService;
import com.ZhongND.RedisDF.Service.ServiceFactory;
import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.ZhongND.RedisDF.exectueDF.ExectueDF;

@Configuration
@EnableAutoConfiguration
public class DFConfig {

	@Bean
	public RedisService redisService() throws DFException {

		try {
			return ServiceFactory.getService();
		} catch (RedissonDBException e) {
			throw new DFException(e);
		}

	}

	@Bean
	public ADFService adfService() {
		return ADFServiceEntry.getADFService();
	}

	@Bean
	public DFService dfService(RedisService redisService) throws DFException {
		try {
			return redisService.getDFService();
		} catch (RedissonDBException e) {
			throw new DFException(e);
		}
	}

	@Bean
	public ExectueDF executeDF(DFService dfService) throws DFException {
		try {
			return dfService.registry("acp");
		} catch (RedissonDBException e) {
			throw new DFException(e);
		}
	}
	
	
//	@ConfigurationProperties(prefix = "bar")
//	@Bean
//	public BarComponent barComponent() {
//		...
//	}

}
