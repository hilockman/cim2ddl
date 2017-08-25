package com.znd.ei;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.context.properties.EnableConfigurationProperties;
import org.springframework.context.ApplicationContext;

import com.znd.ei.reliability.config.ReliabilityProperites;

@SpringBootApplication
@EnableConfigurationProperties(ReliabilityProperites.class)
public class Application {

	private static final Logger LOGGER = LoggerFactory.getLogger(Application.class);

//	@Bean
//	RedisMessageListenerContainer container(RedisConnectionFactory connectionFactory,
//			MessageListenerAdapter listenerAdapter) {
//
//		RedisMessageListenerContainer container = new RedisMessageListenerContainer();
//		container.setConnectionFactory(connectionFactory);
//		container.addMessageListener(listenerAdapter, new PatternTopic("chat"));
//
//		return container;
//	}
//
//	@Bean
//	MessageListenerAdapter listenerAdapter(Receiver receiver) {
//		return new MessageListenerAdapter(receiver, "receiveMessage");
//	}
//
//	@Bean
//	Receiver receiver(CountDownLatch latch) {
//		return new Receiver(latch);
//	}
//
//	@Bean
//	CountDownLatch latch() {
//		return new CountDownLatch(1);
//	}
//
//	@Bean
//	StringRedisTemplate template(RedisConnectionFactory connectionFactory) {
//		return new StringRedisTemplate(connectionFactory);
//	}
//	@Bean
//	RedisService redisService() {
//		return ServiceFactory.getService();
//	}
//	
//	@Bean
//	DFService dfService(RedisService redisService) {
//		return redisService.getDFService();
//	}
    public static void main(String[] args) throws InterruptedException {
    	ApplicationContext ctx = SpringApplication.run(Application.class, args);
//    	ReliabilitySerivce service = ctx.getBean(ReliabilitySerivce.class);
//    	service.sample();
    	
//		ApplicationContext ctx = SpringApplication.run(Application.class, args);
//
//		StringRedisTemplate template = ctx.getBean(StringRedisTemplate.class);
//		CountDownLatch latch = ctx.getBean(CountDownLatch.class);
//
//		LOGGER.info("Sending message...");
//		template.convertAndSend("chat", "Hello from Redis!");
//
//		latch.await();
//
//		System.exit(0);	
    }
    
//    @Bean
//    public CommandLineRunner init(ReliabilitySerivce service,ApplicationContext ctx) {
//        return (args) -> {
// //       	service.sample();
//    		StringRedisTemplate template = ctx.getBean(StringRedisTemplate.class);
//    		CountDownLatch latch = ctx.getBean(CountDownLatch.class);
//    
//    		LOGGER.info("Sending message...");
//    		template.convertAndSend("chat", "Hello from Redis!");
//    
//    		latch.await();        	
//        };
//    } 
}
