package com.znd.client.impl;

import java.util.Date;
import java.util.UUID;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

import com.znd.buffer.common.mapper.AdsNodeMapper;
import com.znd.buffer.common.model.AdsNode;
import com.znd.bus.buffer.Buffer;
import com.znd.client.Client;
import com.znd.config.ClientConfig;


public class DefaultClient implements Client {	
	
	private final Logger logger = LoggerFactory
			.getLogger(DefaultClient.class);

	
	@Autowired
	private ClientConfig config;
	
	@Autowired
	private AdsNodeMapper adsNodeMapper;
	
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

	public AdsNode getNode() {
		return node;
	}
	
	//初始化计算节点配置
	private void init() {

		//AdsNode node1 = adsNodeMapper.getNodeById("f42da8d0-2ba3-47b5-bb69-119a32e0c23c");
		String url = "http://"+config.getIp()+":"+config.getPort();
		//List<AdsNode> nodes = adsNodeMapper.findAll();
		node = adsNodeMapper.getNodeByUrl(url);
		
		if (node == null) {
			
			node = new AdsNode();
			node.setId(UUID.randomUUID().toString());
			node.setLastUpdate(new Date());
			node.setName(config.getHostName());
			node.setUrl(url);
			adsNodeMapper.insert(node);			
			logger.info("Succeed to regist ads node : {}, url : {}", node.getName(), node.getUrl());			
		} else {
			node.setName(config.getHostName());
		}
		
	}

	//更新buffer中的节点表对应计算节点时间。
	private void heatBeat() {
		logger.debug("update node time.");
		node.setLastUpdate(new Date());
		adsNodeMapper.update(node);

	}
	
	//更改节点状态
	private void destory() {
		
	}
	
	@PreDestroy
	public void close() {
		exit.set(true);
	}
}
