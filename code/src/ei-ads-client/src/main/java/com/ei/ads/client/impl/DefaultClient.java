package com.ei.ads.client.impl;

import java.util.concurrent.atomic.AtomicBoolean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.ei.ads.client.Client;
import com.ei.ads.config.ClientConfig;

@Component
public class DefaultClient implements Client {	
	
	@Autowired
	private ClientConfig config;
	
	private AtomicBoolean exit = new AtomicBoolean(false);  
	
	@PostConstruct
	public void start() {
		config.getThreadPool().execute(new Runnable() {
			
			@Override
			public void run() {
				init();
				
				System.out.println("Client started.");
				while (!exit.get()) {
					heatBeat();
					
					try {
						Thread.sleep(config.getHeartbeat());
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						
					}
				}
				
				
				destory();
				System.out.println("Client exit.");
			}
		});
	}

	
	//初始化计算节点配置
	private void init() {
		
	}

	//更新buffer中的节点表对应计算节点时间。
	private void heatBeat() {
		
	}
	
	//更改节点状态
	private void destory() {
		
	}
	
	@PreDestroy
	public void close() {
		exit.set(true);
	}
}
