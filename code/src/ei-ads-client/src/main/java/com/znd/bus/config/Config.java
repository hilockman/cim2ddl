package com.znd.bus.config;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

import com.znd.bus.buffer.BufferFactory;

@Configuration
@EnableAutoConfiguration
public class Config {



	
	@Bean 
	public ClientConfig clientConfig(AdsClientProperties property, BufferFactory bufferFactory) {
		ClientConfig config = new ClientConfig();
		config.setHeartbeat(property.getHeartbeat());
		ExecutorService pool;
		if (property.getThread() < 0) {
			pool =  Executors.newCachedThreadPool();
		} else {
			pool =  Executors.newFixedThreadPool(property.getThread());
		}
		
		config.setThreadPool(pool);
		config.setPort(property.getPort());
		if (property.getIp() != null)
		config.setIp(property.getIp());
		else {
	        InetAddress ip;
	        String hostname;
	        try {
	            ip = InetAddress.getLocalHost();//TODO : how to deal with a host with more than one IP address.
	            hostname = ip.getHostName();
	            config.setHostName(hostname);
	            config.setIp(ip.getHostAddress());
	        } catch (UnknownHostException e) {
	 
	            e.printStackTrace();
	        }
		}
			
		
//		Buffer buffer = bufferFactory.openSession();
////		buffer.selectList(statement, parameter);
//		buffer.close();
		return config;
	}
}
