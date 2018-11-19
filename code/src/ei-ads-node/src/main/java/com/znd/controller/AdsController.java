package com.znd.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import com.znd.bus.common.model.AdsNodeInfo;
import com.znd.client.Client;
import com.znd.model.SystemResourceInfo;
import com.znd.server.SystemResourceServer;

@Controller("/ads")
public class AdsController {

	@Autowired
	private Client client;
	
	@Autowired
	private SystemResourceServer resourceServer;
	
	public AdsController() {
		
	}
	@GetMapping("/node")
	public AdsNodeInfo getNode() {
		AdsNodeInfo node = client.getNode();
		SystemResourceInfo info = resourceServer.get();
		node.setCpuRate(info.getCpu().getLoad());
		node.setMemoryRate(info.getMemory().getGlobalUsedMemoryRate());
		return node;
	}
	
	
}
