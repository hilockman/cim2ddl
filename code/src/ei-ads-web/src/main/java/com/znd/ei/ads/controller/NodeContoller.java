package com.znd.ei.ads.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ei.ads.model.AdsResult;
import com.znd.ei.ads.service.NodeService;
import com.znd.ei.ads.vo.NodeInfo;

@Controller
@RequestMapping("/node")
public class NodeContoller {

	@Autowired
	NodeService nodeService;
	
	@PostMapping("/add")
	public String add(@ModelAttribute NodeInfo node, Model model) {
		if (node.getId() != null && node.getId() < 0)
			node.setId(null);
		boolean newFlag = (node.getId() == null);
		
		NodeInfo oldNode = nodeService.getByName(node.getName());
		if (oldNode != null) {
			if (newFlag || (!newFlag && node.getId() != oldNode.getId())) {
				model.addAttribute("error", String.format("Node exist: name = %s", node.getName()));
				model.addAttribute("node", node);
				return "/new_or_update_node";
			}
		}
		
		oldNode = nodeService.getByUrl(node.getUrl());
		if (oldNode != null) {
			if (newFlag  || (!newFlag && node.getId() != oldNode.getId())) {
				model.addAttribute("error", String.format("Node exist: url = %s", node.getUrl()));
				model.addAttribute("node", node);
				return "/new_or_update_node";
			}
			
		}

		if (newFlag) {	
			nodeService.save(node);
		} else {			
			nodeService.update(node);
		}
				
		return "redirect:/nodes";
	}
	
	@PostMapping("/delete/{nodeId}")
	public @ResponseBody AdsResult delete(@PathVariable Integer nodeId) {		
		nodeService.deleteById(nodeId);
		
		return AdsResult.ok(null);
	}
	
	@GetMapping("/{nodeId}")
	public @ResponseBody NodeInfo get(@PathVariable Integer nodeId) {		
		return nodeService.getById(nodeId);
	}
	
	@GetMapping("/edit/{nodeId}")
	public String edit(@PathVariable Integer nodeId, Model model) {	
		NodeInfo node = nodeService.getById(nodeId);
		model.addAttribute("node", node);
		//model.addAttribute("name", node.getName()).addAttribute("id", node.getId()).addAttribute("url", node.getUrl());		
		return "/new_or_update_node";
	}
}
