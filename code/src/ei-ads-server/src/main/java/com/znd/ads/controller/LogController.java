package com.znd.ads.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ads.service.LogService;
import com.znd.bus.log.Log;


@Controller
@RequestMapping("/logs")
public class LogController {

	@Autowired
	private LogService logService;
	
	@GetMapping
    public @ResponseBody List<Log> getAll() {
    	return logService.findAll();
    }
}
