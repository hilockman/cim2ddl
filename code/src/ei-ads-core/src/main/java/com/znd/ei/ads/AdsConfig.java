package com.znd.ei.ads;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
@EnableAutoConfiguration
public class AdsConfig {

	@Bean
	public ExecutorService adsThreadPool() {
		return  Executors.newCachedThreadPool();
	}
}
