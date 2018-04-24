package com.znd.memory;

import java.io.File;
import java.nio.file.Paths;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Component;

import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.utils.AppUtil;

@Component
public class ShareMemHolder {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(ShareMemHolder.class);
	
	//private ReliabilityProperties properties;
	
	private String appDir;
	public ShareMemHolder(ReliabilityProperties properties) {
		
		//this.properties = properties;
		appDir = properties.getAppDir();
		if (!new File(appDir).exists()) {
			appDir = System.getenv("ZND_HOME")+"\\bin_x64";
			if (!new File(appDir).exists()) {
				throw new RuntimeException("no find "+properties.getAppDir()+", or "+"$ZND_HOME");
			}
		}

		appDir = Paths.get(appDir).toAbsolutePath().toString();
		//logger.info("reliability appdir : "+appDir);
	} 
	
	@PostConstruct
	public void init() {

		new Thread(() -> {
			if (AppUtil.isRunning("MemStarter")) {
				LOGGER.info("MemStarter is running.");
				
			} else {
				LOGGER.info("Will to start MemStarter...");
				AppUtil.execBuilder(appDir+"/MemStarter").addParam("-s").exec();
				LOGGER.info("MemStarter started.");
			}
		}).start();	
	}
	
	
	@PreDestroy
	public void destory() {
		new Thread(() -> {
			LOGGER.info("Will to kill MemStarter.");
			AppUtil.execBuilder(appDir+"/MemStarter").addParam("-k").exec();
			LOGGER.info("MemStarter is killed.");
			
		}).start();	
	}
	
}
