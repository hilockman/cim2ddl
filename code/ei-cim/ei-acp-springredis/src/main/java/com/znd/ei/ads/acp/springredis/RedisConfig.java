package com.znd.ei.ads.acp.springredis;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.redis.connection.RedisClusterConfiguration;
import org.springframework.data.redis.connection.RedisConnectionFactory;
import org.springframework.data.redis.connection.jedis.JedisConnectionFactory;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.data.redis.listener.PatternTopic;
import org.springframework.data.redis.listener.RedisMessageListenerContainer;
import org.springframework.data.redis.listener.adapter.MessageListenerAdapter;

import com.znd.ei.ads.acp.ConnectionFactory;

@Configuration
@EnableAutoConfiguration
public class RedisConfig {
//	/**
//	 * lettuce
//	 * 192.168.1.50:7000,192.168.1.50:7001,192.168.1.50:7002,192.168.1.50:7003,192.168.1.50:7004,192.168.1.50:7005
//	 */
//	@Bean
//	public RedisConnectionFactory lettuceConnectionFactory() {
//	  RedisSentinelConfiguration sentinelConfig = new RedisSentinelConfiguration().master("192.168.1.10:7001,192.168.1.10:7002")
//			  .sentinel("192.168.1.10", 7001).sentinel("192.168.1.10", 7002);
//	  return new LettuceConnectionFactory(sentinelConfig);
//	}
	
//	@Value("${spring.redis.cluster.nodes}")
//	private List<String> clusterNodes;
    /**
     * Type safe representation of application.properties
     */
    @Autowired RedisProperties redisProperties;
	@Bean
	public ConnectionFactory acpConnection() {
		ConnectionFactory conn =  new SpringRedisConnection();
		return conn;
	}
	
	
	@Bean
	RedisMessageListenerContainer container(RedisConnectionFactory connectionFactory,
			MessageListenerAdapter listenerAdapter) {

		RedisMessageListenerContainer container = new RedisMessageListenerContainer();
		container.setConnectionFactory(connectionFactory);
		container.addMessageListener(listenerAdapter, new PatternTopic("chat"));

		return container;
	}
	
	@Bean
	MessageListenerAdapter listenerAdapter(Receiver receiver) {
		return new MessageListenerAdapter(receiver, "receiveMessage");
	}
	
	@Bean
	Receiver receiver() {
		return new Receiver();
	}
	
	@Bean
	public RedisConnectionFactory redisConnectionFactory() {
		List<String> clusterNodes = redisProperties.getNodes();
		for (String node: clusterNodes) {
			System.out.println("node : " +node);
		}
		JedisConnectionFactory connectionFactory = new JedisConnectionFactory(new RedisClusterConfiguration(clusterNodes));
		return connectionFactory;
	}
	
	@Bean
	public StringRedisTemplate stringRedisTemplate(RedisConnectionFactory redisConnectionFactory) {
		StringRedisTemplate template = new StringRedisTemplate();
		template.setConnectionFactory(redisConnectionFactory);
		return template;
	}
}
