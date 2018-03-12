package com.znd.ei.ads;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.http.converter.HttpMessageConverter;
import org.thymeleaf.spring5.SpringTemplateEngine;
import org.thymeleaf.spring5.templateresolver.SpringResourceTemplateResolver;
import org.thymeleaf.spring5.view.ThymeleafViewResolver;
import org.thymeleaf.templatemode.TemplateMode;

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
	
	@Bean
	public HttpMessageConverter jacksonMessageConverter() {
		return new org.springframework.http.converter.json.MappingJackson2HttpMessageConverter();
	}
//	
//    @Bean
//    public SpringResourceTemplateResolver templateResolver(ApplicationContext applicationContext){
//        SpringResourceTemplateResolver templateResolver = new SpringResourceTemplateResolver();
//        templateResolver.setApplicationContext(applicationContext);
//        //templateResolver.setPrefix("/WEB-INF/templates/");
//        templateResolver.setSuffix(".html");
//        templateResolver.setTemplateMode(TemplateMode.HTML);
//        // Template cache is true by default. Set to false if you want
//        // templates to be automatically updated when modified.
//        templateResolver.setCacheable(true);
//        return templateResolver;
//    }
//
//    @Bean
//    public SpringTemplateEngine templateEngine(SpringResourceTemplateResolver templateResolver){
//        SpringTemplateEngine templateEngine = new SpringTemplateEngine();
//        templateEngine.setEnableSpringELCompiler(true); // Compiled SpringEL should speed up executions
//        templateEngine.setTemplateResolver(templateResolver);
//        return templateEngine;
//    }
//
//    @Bean
//    public ThymeleafViewResolver thymeleafViewResolver(SpringTemplateEngine templateEngine){
//        ThymeleafViewResolver viewResolver = new ThymeleafViewResolver();
//        viewResolver.setContentType("text/html;encoding=utf-8");
//        viewResolver.setTemplateEngine(templateEngine);
//        viewResolver.setViewNames(new String[] {"index","*th"});
//        viewResolver.setOrder(Integer.valueOf(1));
//        return viewResolver;
//    }


}
