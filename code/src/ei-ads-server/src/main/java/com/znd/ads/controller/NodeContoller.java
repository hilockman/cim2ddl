package com.znd.ads.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ads.model.AdsResult;
import com.znd.ads.model.po.AdsNode;
import com.znd.ads.service.NodeService;

@Controller
@RequestMapping("/node")
public class NodeContoller {

	@Autowired
	private NodeService nodeService;
	
	
	@PostMapping("/add")
	public String add(@ModelAttribute AdsNode node, Model model) {
		if (node.getId() != null || node.getId().isEmpty() || Integer.valueOf(node.getId()) < 0)
			node.setId(null);
		boolean newFlag = (node.getId() == null);
		
		AdsNode oldNode = nodeService.getByName(node.getName());
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
	public @ResponseBody AdsResult delete(@PathVariable String nodeId) {		
		nodeService.deleteById(nodeId);
		
		return AdsResult.ok(null);
	}
	
	@PostMapping("/update")
	public @ResponseBody AdsResult update(AdsNode node) {
		AdsNode oldNode = nodeService.getById(node.getId());
		if (oldNode != null) {
			oldNode.setName(node.getName());
			oldNode.setUrl(node.getUrl());
			nodeService.update(oldNode);
			System.out.println("Succeed to update node:"+node);
		}
		
		return AdsResult.ok(null);
	}
	
	
	@GetMapping("/{nodeId}")
	public @ResponseBody AdsNode get(@PathVariable String nodeId) {		
		return nodeService.getById(nodeId);
	}
	
	@GetMapping("/all")
	public @ResponseBody List getAll() {		
		return nodeService.getAll();
	}
	
	
	@GetMapping("/edit/{nodeId}")
	public String edit(@PathVariable String nodeId, Model model) {	
		AdsNode node = nodeService.getById(nodeId);
		model.addAttribute("node", node);
		return "/node/editnode";
	}
}
