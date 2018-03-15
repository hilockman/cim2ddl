package com.znd.ei.ads.buffer.test.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.ei.ads.bus.buffer.BufferFactory;
import com.znd.ei.ads.bus.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.TableMeta;

@Configuration
@EnableAutoConfiguration
public class DataBusConfig {


	@Bean
	public BufferConfig bufferConfig(DabaBusProperties property) {
		
		BufferConfig config = new BufferConfig();
			config.setId(property.getId());
			config.setName(property.getName());
			config.setAlias(property.getAlias());
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(BufferConfig.UPDATE);
			config.setTableMetas(property.getTables().toArray(new TableMeta[0]));
			config.setTypePackage(property.getTypePackage());
			config.setMapperPackage(property.getMapperPackage());
			return config;
	}
	
	
	@Bean 
	public BufferFactory bufferFactory(BufferConfig config) {
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		return b.build(config);
	}
}
