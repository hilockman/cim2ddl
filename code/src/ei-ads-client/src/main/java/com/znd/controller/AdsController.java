package com.znd.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import com.znd.buffer.common.model.AdsNode;
import com.znd.client.Client;

@Controller("/ads")
public class AdsController {

	@Autowired
	private Client client;
	
	
	@GetMapping("/node")
	public AdsNode getNode() {
		return client.getNode();
	}
	
	
}
