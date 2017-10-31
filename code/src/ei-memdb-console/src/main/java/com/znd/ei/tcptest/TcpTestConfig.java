package com.znd.ei.tcptest;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
@EnableAutoConfiguration
public class TcpTestConfig {
	@Bean
	public ExecutorService threadPool(TcpTestProperties properties) {
		return Executors.newFixedThreadPool(properties.getServerWorkers());
	}
	
}
