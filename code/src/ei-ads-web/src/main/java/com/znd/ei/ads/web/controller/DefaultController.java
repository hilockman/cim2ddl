package com.znd.ei.ads.web.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import com.znd.ei.ads.web.service.NodeService;
import com.znd.ei.ads.web.vo.NodeInfo;

@Controller
public class DefaultController {

	@Autowired
	private NodeService nodeService;
	
    @GetMapping("/")
    public String home1() {
    	//此处必须用相对路径
    	return "home";
    }

    @GetMapping("/home")
    public String home() {
        return "home";
    }
   
    
    @GetMapping("/nodes")
    public String nodes(Model model) {
    	List<NodeInfo> nodeList = nodeService.all();
    	model.addAttribute("nodeList",nodeList);
        return "nodes";
    }
    
    @GetMapping("/newnode")
    public String newnode() {
        return "newnode";
    }    
    
    @GetMapping("/pradequacy")
    public String about() {
        return "pradequacy";
    }

    @GetMapping("/model")
    public String model() {
        return "model";
    }

    @GetMapping("/test")
    public String test() {
        return "test";
    }
    
    @GetMapping("/403")
    public String error403() {
        return "/error/403";
    }

}
