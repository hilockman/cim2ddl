package com.znd.ei.reliability.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ei.reliability.server.MCSampleService;

@Controller
@RequestMapping(path = "/reliability")
public class ReliabilityController {

	@Autowired
	private MCSampleService mCSampleService;
	
	@GetMapping
	public @ResponseBody String logo() {
		return "Reliability";
	}

	@GetMapping(path = "/mcsample")
	public @ResponseBody String mcsample() {
		mCSampleService.run();
		return "MC Sample ok!";
	}
	
}
