package com.znd.bus.config;

import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.BeansException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.config.BeanFactoryPostProcessor;
import org.springframework.beans.factory.config.ConfigurableListableBeanFactory;
import org.springframework.core.env.Environment;

import com.znd.bus.buffer.Buffer;

//@Configuration
//@Order(Ordered.HIGHEST_PRECEDENCE + 2)
public class MyPostProcessor implements BeanFactoryPostProcessor{

	private final Logger logger = LoggerFactory.getLogger(MyPostProcessor.class);
	
	@Autowired
	private BufferConfig bufferConfig;
	
	@Autowired
	private Buffer defaultBuffer;
	
	@Autowired
	private DabaBusProperties properties;
	
	
	@Autowired 
	private Environment env;

	
//	@Autowired
//	public MyPostProcessor(Buffer defaultBuffer) {
//		this.defaultBuffer = defaultBuffer;
//		
//	}
	public MyPostProcessor() {
	   
	}

	
//	@Override
//	public int getOrder() {
//		return Ordered.HIGHEST_PRECEDENCE + 10;
//	}
	private List<String> getCandidateNames(Class<?> mapper) {
		List<String> names = new ArrayList<>();
		String beanName = mapper.getSimpleName();
		names.add(beanName.substring(0,1).toLowerCase()+beanName.substring(1));
		names.add("buffer"+beanName);
		
		return names;
	}

	
	@Override
	public void postProcessBeanFactory(
			ConfigurableListableBeanFactory beanFactory) throws BeansException {
		//beanFactory.getBean(requiredType)
		
		//DabaBusProperties p = beanFactory.getBean(DabaBusProperties.class);
		Collection<Class<?>> mappers = bufferConfig.getMappers();
		//ConfigurableListableBeanFactory beanFactory = context.getBeanFactory();
		for (Class<?> mapper : mappers) {
			 List<String> names = getCandidateNames(mapper);
			 boolean registed = false;
			 for (String name : names) {
					if (!beanFactory.containsBean(name)) {						
						Object rbean = bufferConfig.getMapper(mapper,defaultBuffer);
						beanFactory.registerSingleton(name, rbean);
						logger.info("Succeed to regist bean : "+mapper +" as '"+name+"'.");
						registed = true;
						break;
					}	 
			 }
			
			 if (!registed)
				 throw new BufferConfigException("Cann't regist buffer mapper for  "+mapper +", candidate names : " + names);
		}
	}




}
