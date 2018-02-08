package com.ei.ads.terminal.controller;

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


    @GetMapping("/admin")
    public String index() {
        return "/admin/index";
    }



    @GetMapping("/403")
    public String error403() {
        return "/error/403";
    }

}
