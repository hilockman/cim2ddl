package com.ei.ads.client.impl;

import java.util.Date;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.ei.ads.client.Client;
import com.ei.ads.config.ClientConfig;
import com.ei.ads.mappper.AdsNodeMapper;
import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.buffer.BufferFactory;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.vo.AdsNode;

@Component
public class DefaultClient implements Client {	
	
	private final Logger logger = LoggerFactory
			.getLogger(DefaultClient.class);
	
	@Autowired
	private ClientConfig config;
	
	@Autowired
	private BufferFactory bufferFactory;
	
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
		Buffer buffer = bufferFactory.openSession();
		BufferConfig bufferConfig = bufferFactory.config();
		AdsNodeMapper mapper = bufferConfig.getMapper(AdsNodeMapper.class, buffer);
		String url = "http://"+config.getIp()+":"+config.getPort();
		AdsNode node = mapper.getNodeByUrl(url);
		
		
		if (node == null) {
			
			node = new AdsNode();
			node.setId(UUID.randomUUID().toString());
			node.setLastUpdate(new Date());
			node.setName(config.getHostName()+config.getPort());
			mapper.insert(node);
			
			logger.info("Succeed to regist ads node : "+node.getName());
		} 
		
		
		
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
