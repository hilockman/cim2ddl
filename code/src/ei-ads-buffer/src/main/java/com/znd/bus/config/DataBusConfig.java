package com.znd.bus.config;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.log.LogMapper;
import com.znd.bus.message.MessageProxy;
import com.znd.bus.message.defaults.DefaultMessageProxy;

@Configuration
@EnableAutoConfiguration
public class DataBusConfig {


	@Bean
	public BufferConfig bufferConfig(DabaBusProperties dabaBusProperties) {
		
		BufferConfig config = new BufferConfig();
			config.setId(dabaBusProperties.getId());
			config.setName(dabaBusProperties.getName());
			config.setAlias(dabaBusProperties.getAlias());
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(CreateFlag.valueOf(dabaBusProperties.getCreateFlag().toUpperCase()));
			config.setTableMetas(dabaBusProperties.getTables().toArray(new TableMeta[0]));
			return config;
	}
	
	
	@Bean 
	public BufferFactory bufferFactory(BufferConfig config) {
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		return b.build(config);
	}
	
	@Bean
	public MessageProxy messageProxy() {
		return new DefaultMessageProxy();
	}
	
	
	
	@Bean
	public LogMapper bufferLogMapper(BufferFactory bufferFactory, BufferConfig config) {
		
		Buffer buffer = bufferFactory.openSession();
		return config.getMapper(LogMapper.class, buffer);
		
	}
}
