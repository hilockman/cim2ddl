package com.ei.ads.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
@Controller
public class DefaultController {

	@GetMapping("/")
	public String home() {
		return "/home";
	}
	
	@GetMapping("/home")
	public String home1() {
		return "/home";
	}
}
