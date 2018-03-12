package com.znd.ei.ads.client.control;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

@Controller("/")
public class HelloController {

	@GetMapping
	String home() {
		return "/home";
	}
}
