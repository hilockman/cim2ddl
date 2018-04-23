package com.znd.bus.config;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import org.redisson.config.ConfigSupport;
import org.redisson.config.RedissonNodeConfig;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.config.ConfigurableListableBeanFactory;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.ConfigurableApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.Ordered;
import org.springframework.core.annotation.Order;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelRegistry;
import com.znd.bus.log.BufferLogger;

@Configuration
@EnableAutoConfiguration
public class DataBusConfig {

	private final Logger logger = LoggerFactory.getLogger(DataBusConfig.class);
	
	//private static String FILE_NAME = "redissonnode.yaml";
	private static String FILE_NAME = "ClusterServersConfig.cfg";
	
	private RedissonNodeConfig redissonNodeConfig() {

		FileInputStream fis = null;
		try {
			URL url = org.springframework.util.ResourceUtils.getURL("classpath:"+FILE_NAME);
			ConfigSupport support = new ConfigSupport();
			//RedissonNodeConfig config =  support.fromYAML(url, RedissonNodeConfig.class);
			RedissonNodeConfig config =  support.fromJSON(url, RedissonNodeConfig.class);
			
			return config;
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			if (fis != null) {
				try {
					fis.close();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}

		return null;
	}	
	
	@Bean
	public BufferConfig defaultBufferConfig(DabaBusProperties properties) {
		
		BufferConfig config = new BufferConfig();
			config.setId(properties.getId());
			config.setName(properties.getName());
			config.setAlias(properties.getAlias());
			config.setMapperPackage(properties.getMapperPackage());
			config.setTypePackage(properties.getTypePackage());
			config.setAppName(BufferFactoryBuilder.DEFAULT_APPNAME);
			config.setCreateFlag(properties.getCreateFlag() == null ? CreateFlag.UPDATE : CreateFlag.valueOf(properties.getCreateFlag().toUpperCase()));
			config.setTableMetas(properties.getTables() != null ? properties.getTables().toArray(new TableMeta[0]) : null);
			config.setChannels(properties.getChannels());
		
		RedissonNodeConfig redissonConfig = redissonNodeConfig();
		if (redissonConfig != null) {
			config.setRedissonConfig(redissonConfig);
		}
		return config;
	}
	
	
	@Bean 
	public BufferFactory defaultBufferFactory(BufferConfig defaultBufferConfig) {
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		return b.build(defaultBufferConfig);
	}

	private List<String> getCandidateNames(Class<?> mapper) {
		List<String> names = new ArrayList<>();
		String beanName = mapper.getSimpleName();
		names.add(beanName.substring(0,1).toLowerCase()+beanName.substring(1));
		names.add("buffer"+beanName);
		
		return names;
	}


	  
	@Bean 
	@Order(Ordered.HIGHEST_PRECEDENCE)
	public Buffer defaultBuffer(ConfigurableApplicationContext context, BufferConfig defaultBufferConfig, BufferFactory defaultBufferFactory) {
				
		Buffer buffer =  defaultBufferFactory.openSession();
		Collection<Class<?>> mappers = defaultBufferConfig.getMappers();
		ConfigurableListableBeanFactory beanFactory = context.getBeanFactory();
		for (Class<?> mapper : mappers) {
			 List<String> names = getCandidateNames(mapper);
			 boolean registed = false;
			 for (String name : names) {
					if (!beanFactory.containsBean(name)) {						
						Object rbean = defaultBufferConfig.getMapper(mapper, buffer);
						beanFactory.registerSingleton(name, rbean);
						logger.info("Succeed to regist bean : "+mapper +" as '"+name+"'.");
						registed = true;
						break;
					}	 
			 }
			
			 if (!registed)
				 throw new BufferConfigException("Cann't regist buffer mapper for  "+mapper +", candidate names : " + names);
		}
//		
		return buffer;
	}
	
	@Bean
	public BufferLogger bufferLogger(BufferFactory bufferFactory) {
		return bufferFactory.logger();
	}
	
	@Bean
	public ChannelRegistry channelFactory(ConfigurableApplicationContext context, BufferConfig defaultBufferConfig) {
		ChannelRegistry channelFactory =  defaultBufferConfig.getChannelRegistry();
		Collection<String> channels = channelFactory.getChannels();
		ConfigurableListableBeanFactory beanFactory = context.getBeanFactory();
		for (String  name : channels) {
			Channel c = channelFactory.getChannel(name);
			beanFactory.registerSingleton(name, c);
			logger.info("Succeed to regist channel : {}, type : {}", name, c.getType().name());
		}
		return channelFactory;
	}
		

}
