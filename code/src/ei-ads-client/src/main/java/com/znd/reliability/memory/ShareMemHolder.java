package com.znd.reliability.memory;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.springframework.stereotype.Component;

import com.znd.reliability.utils.AppUtil;

@Component
public class ShareMemHolder {

	@PostConstruct
	public void init() {

		new Thread(() -> {
			if (AppUtil.checkAppIsRunning("MemStarter")) {
				System.out.println("***********MemStarter is running****************");
				
			} else {
				System.out.println("***********MemStarter start****************");
				AppUtil.execBuilder("MemStarter").addParam("-s").exec();
			}
		}).start();	
	}
	
	
	@PreDestroy
	public void destory() {
		new Thread(() -> {
			AppUtil.execBuilder("MemStarter").addParam("-k").exec();
			System.out.println("***********MemStarter exit****************");
		}).start();	
	}
	
}
