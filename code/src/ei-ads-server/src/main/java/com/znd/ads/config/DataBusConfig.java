package com.znd.ads.config;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import org.redisson.config.ConfigSupport;
import org.redisson.config.RedissonNodeConfig;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.config.ConfigurableListableBeanFactory;
import org.springframework.boot.autoconfigure.AutoConfigureOrder;
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
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.BufferConfigException;
import com.znd.bus.config.CreateFlag;
import com.znd.bus.config.TableMeta;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.exception.MessageException;
import com.znd.bus.server.BusService;

@Configuration
@EnableAutoConfiguration
//@Order(Ordered.HIGHEST_PRECEDENCE)
@AutoConfigureOrder(Ordered.LOWEST_PRECEDENCE)
public class DataBusConfig {

	private final Logger logger = LoggerFactory.getLogger(DataBusConfig.class);
	
	private BufferFactory defaultBufferFactory;
	
	private Buffer defaultBuffer;
	
	
	private File getFile(String fileName) {
		List<File> candidates = new ArrayList<>();
		candidates.add(new File("../../JavaWorkspace/"+fileName));
		candidates.add(new File("../JavaWorkspace/"+fileName));
		candidates.add(new File("./JavaWorkspace/"+fileName));
		for (File file : candidates) {
			if (file.exists())
				return file;
		}
		
		return null;
	}
	private RedissonNodeConfig redissonNodeConfig(String fileName) {

		
//		FileInputStream fis = null;
		try {
//			URL url = org.springframework.util.ResourceUtils.getURL("classpath:"+fileName);
			File file = getFile(fileName);
			if (file == null) {
				System.err.println("Find no config file :"+fileName);
				System.exit(0);
			}
			logger.info("reddisson config file : "+ file.getAbsolutePath());
			ConfigSupport support = new ConfigSupport();
			RedissonNodeConfig config =  support.fromJSON(file, RedissonNodeConfig.class);
			
			
			return config;
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
//			if (fis != null) {
//				try {
//					fis.close();
//				} catch (IOException e) {
//					// TODO Auto-generated catch block
//					e.printStackTrace();
//				}
//			}
		}

		return null;
	}	
	
	@Bean
	@Order(Ordered.HIGHEST_PRECEDENCE)
	public BufferConfig defaultBufferConfig(ConfigurableApplicationContext context, DataBusProperties properties) {
		
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
		
		RedissonNodeConfig redissonConfig = redissonNodeConfig(properties.getRedisConfig());
		if (redissonConfig != null) {
			config.setRedissonConfig(redissonConfig);
		}
		
		redissonConfig = redissonNodeConfig(properties.getLocalConfig());
		if (redissonConfig != null) {
			config.setLocalConfig(redissonConfig);
		}
		
		try {
			this.defaultBufferFactory = createDefaultBufferFactory(config);
		} catch (BindingException | BufferException | MessageException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
			throw new RuntimeException(e1);
		}
		
		this.defaultBuffer = defaultBufferFactory.openSession();
		
		try {
			registBeans(context.getBeanFactory(), config);
		} catch (BindingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			throw new RuntimeException(e);
		}
		
		return config;
	}
	
	
	private BufferFactory createDefaultBufferFactory(BufferConfig defaultBufferConfig) throws BindingException, BufferException, MessageException {
		BufferFactoryBuilder b = new BufferFactoryBuilder();
		return b.build(defaultBufferConfig);
	}
	
	@Bean 
	public BufferFactory defaultBufferFactory(BufferConfig defaultBufferConfig) {
		return this.defaultBufferFactory;
	}

	private List<String> getCandidateNames(Class<?> mapper) {
		List<String> names = new ArrayList<>();
		String beanName = mapper.getSimpleName();
		names.add(beanName.substring(0,1).toLowerCase()+beanName.substring(1));
		names.add("buffer"+beanName);
		names.add(mapper.getClass().getCanonicalName());
		return names;
	}


	private void registBeans(ConfigurableListableBeanFactory beanFactory, BufferConfig defaultBufferConfig) throws BindingException {
		Collection<Class<?>> mappers = defaultBufferConfig.getMappers();
		//ConfigurableListableBeanFactory beanFactory = context.getBeanFactory();
		for (Class<?> mapper : mappers) {
			 List<String> names = getCandidateNames(mapper);
			 boolean registed = false;
			 for (String name : names) {
					if (!beanFactory.containsBean(name)) {						
						Object rbean = defaultBufferConfig.getMapper(mapper, defaultBuffer);
						beanFactory.registerSingleton(name, rbean);
						logger.info("Succeed to regist bean : "+mapper +" as '"+name+"'.");
						registed = true;
						break;
					}	 
			 }
			
			 if (!registed)
				 throw new BufferConfigException("Cann't regist buffer mapper for  "+mapper +", candidate names : " + names);
		}
		
		// Regist channel
		ChannelRegistry channelFactory =  defaultBufferConfig.getChannelRegistry();
		Collection<String> channels = channelFactory.getChannels();
		for (String  name : channels) {
			Channel c = channelFactory.getChannel(name);
			beanFactory.registerSingleton(name, c);
			logger.info("Succeed to regist channel : {}, type : {}", name, c.getType().name());
		}
	}
	@Bean 
	@Order(Ordered.HIGHEST_PRECEDENCE)
	public Buffer defaultBuffer(ConfigurableApplicationContext context, BufferConfig defaultBufferConfig, BufferFactory defaultBufferFactory) {
		return defaultBuffer;
	}
	
	@Bean
	public BusService busService(BufferConfig defaultBufferConfig) {
		return defaultBufferConfig.getBuservice();
	}
	
//	@Override
//	public void postProcessBeanFactory(ConfigurableListableBeanFactory beanFactory) throws BeansException {
//		try {
//			registBeans(beanFactory, (BufferConfig)beanFactory.getBean("defautlBufferConfig"));
//		} catch (BindingException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//			throw new RuntimeException(e);
//		}
//	}
//	@Override
//	public void postProcessBeanDefinitionRegistry(BeanDefinitionRegistry registry) throws BeansException {
//		// TODO Auto-generated method stub
//		
//	}
//	
//    @Override
//    public int getOrder() {
//        return Ordered.HIGHEST_PRECEDENCE + 2;
//    }
	
//	@Bean
//	public BufferLogger bufferLogger(BufferFactory bufferFactory) {
//		return bufferFactory.logger();
//	}
//	
	
	
//	@Bean
//	public ChannelRegistry channelFactory(ConfigurableApplicationContext context, BufferConfig defaultBufferConfig) {
//		ChannelRegistry channelFactory =  defaultBufferConfig.getChannelRegistry();
//		Collection<String> channels = channelFactory.getChannels();
//		ConfigurableListableBeanFactory beanFactory = context.getBeanFactory();
//		for (String  name : channels) {
//			Channel c = channelFactory.getChannel(name);
//			beanFactory.registerSingleton(name, c);
//			logger.info("Succeed to regist channel : {}, type : {}", name, c.getType().name());
//		}
//		return channelFactory;
//	}
//		
	
//	@Bean
//	public DataBusBeanFactory beanFactory(BufferConfig bufferConfig, Buffer defaultBuffer) {
//		DataBusBeanFactory factory = new DataBusBeanFactory();
//		factory.setBufferConfig(bufferConfig);
//		factory.setDefaultBuffer(defaultBuffer);
//		return factory;
//	}

}
