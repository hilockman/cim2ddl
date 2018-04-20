package com.znd.memory;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

import com.znd.reliability.utils.AppUtil;

@Component
public class ShareMemHolder {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(ShareMemHolder.class);
	
	@PostConstruct
	public void init() {

		new Thread(() -> {
			if (AppUtil.isRunning("MemStarter")) {
				LOGGER.info("MemStarter is running.");
				
			} else {
				LOGGER.info("Will to start MemStarter...");
				AppUtil.execBuilder("MemStarter").addParam("-s").exec();
				LOGGER.info("MemStarter started.");
			}
		}).start();	
	}
	
	
	@PreDestroy
	public void destory() {
		new Thread(() -> {
			LOGGER.info("Will to kill MemStarter.");
			AppUtil.execBuilder("MemStarter").addParam("-k").exec();
			LOGGER.info("MemStarter is killed.");
			
		}).start();	
	}
	
}
