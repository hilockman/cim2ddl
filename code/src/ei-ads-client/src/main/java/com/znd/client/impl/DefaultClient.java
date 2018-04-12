package com.znd.client.impl;

import java.util.Date;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.buffer.common.mapper.AdsNodeMapper;
import com.znd.buffer.common.model.AdsNode;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.config.BufferConfig;
import com.znd.client.Client;
import com.znd.config.ClientConfig;

@Component
public class DefaultClient implements Client {	
	
	private final Logger logger = LoggerFactory
			.getLogger(DefaultClient.class);
	
	@Autowired
	private ClientConfig config;
	
	@Autowired
	private BufferFactory bufferFactory;
	
	private AtomicBoolean exit = new AtomicBoolean(false);  
	
	
	private AdsNode node;
	
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
		node = mapper.getNodeByUrl(url);
			
		if (node == null) {
			
			node = new AdsNode();
			node.setId(UUID.randomUUID().toString());
			node.setLastUpdate(new Date());
			node.setName(config.getHostName()+config.getPort());
			mapper.insert(node);
			
			logger.info("Succeed to regist ads node : "+node.getName());
			
		} 
		
		buffer.close();
		
		
	}

	//更新buffer中的节点表对应计算节点时间。
	private void heatBeat() {
		Buffer buffer = bufferFactory.openSession();
		BufferConfig bufferConfig = bufferFactory.config();
		
		AdsNodeMapper mapper = bufferConfig.getMapper(AdsNodeMapper.class, buffer);
		node.setLastUpdate(new Date());
		mapper.update(node);
		buffer.close();
	}
	
	//更改节点状态
	private void destory() {
		
	}
	
	@PreDestroy
	public void close() {
		exit.set(true);
	}
}
