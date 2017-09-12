package com.znd.ei.reliability.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.znd.ei.reliability.model.ComputingResult;
import com.znd.ei.reliability.server.impl.MCSampleService;

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
	public @ResponseBody ComputingResult mcsample() {
		try {
			return mCSampleService.run();
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return new ComputingResult("Error", "Failt to Sample");
		}
	}
	
}
