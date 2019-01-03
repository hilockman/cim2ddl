package com.znd.ads.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;

import com.znd.ads.service.NodeService;

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
   
//    
//    @GetMapping("/nodes")
//    public String nodes(Model model) {
//    	List<AdsNode> nodeList = nodeService.getAll();
//    	model.addAttribute("nodeList",nodeList);
//        return "nodes";
//    }
    
    @GetMapping("/newnode")
    public String newnode() {
        return "new_or_update_node";
    }    
    
    @GetMapping("/editnode")
    public String editnode(Model model) {
        return "new_or_update_node";
    }  
    
    @GetMapping("/pradequacy")
    public String about() {
        return "pradequacy";
    }

    @GetMapping("/model")
    public String model() {
        return "model";
    }

    @GetMapping("/buffer")
    public String buffer() {
        return "buffer";
    }
    
    @GetMapping("/test")
    public String test() {
        return "test";
    }
    
    @GetMapping("/log")
    public String log() {
        return "log";
    }
    
    @GetMapping("/403")
    public String error403() {
        return "/error/403";
    }
    

    @GetMapping("/job") 
    public String job() {
    	return "job";
    }

}
