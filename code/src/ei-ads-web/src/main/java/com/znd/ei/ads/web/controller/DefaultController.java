package com.znd.ei.ads.web.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class DefaultController {

	
    @GetMapping("/")
    public String home1() {
    	//此处必须用相对路径
    	return "home";
    }

    @GetMapping("/home")
    public String home() {
        return "home";
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
