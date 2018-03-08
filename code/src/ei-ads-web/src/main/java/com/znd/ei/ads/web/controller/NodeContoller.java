package com.znd.ei.ads.web.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import com.znd.ei.ads.web.model.AdsResult;
import com.znd.ei.ads.web.service.NodeService;
import com.znd.ei.ads.web.vo.NodeInfo;

@RestController
@RequestMapping("/node")
public class NodeContoller {

	@Autowired
	NodeService nodeService;
	
	@PostMapping("/addNode")
	public @ResponseBody AdsResult addNode(@ModelAttribute NodeInfo node) {
		NodeInfo oldNode = nodeService.getByName(node.getName());
		if (oldNode != null) {
			return AdsResult.fail(String.format("Node exist : name = '%s'", node.getName()));
		}
		
		oldNode = nodeService.getByUrl(node.getUrl());
		if (oldNode != null) {
			return AdsResult.fail(String.format("Node exist : url = '%s'", node.getUrl()));
		}
		
		nodeService.save(node);
		
		return AdsResult.ok("/nodes");
	}
	
}
