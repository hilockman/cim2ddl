package com.znd.controller;

import java.util.Collection;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.model.CPUInfo;
import com.znd.model.SystemResourceInfo;
import com.znd.server.SystemResourceServer;

@Controller
public class SystemController {

	@Autowired
	private SystemResourceServer resourceServer;
	
	@GetMapping("system/systemInfo")
	public @ResponseBody  SystemResourceInfo getSystemInfo() {
		return resourceServer.get();
	}

	
	@GetMapping("system/systemInfos")
	public @ResponseBody  Collection getSystemInfos() {
		return resourceServer.getList();
	}
	
//	@GetMapping("system/cpu")
//	public @ResponseBody  CPUInfo getCPU()
//	{
//		return resourceServer.getCPU();
//	}
	

//	@GetMapping("system/cpus")
//	public @ResponseBody  List getCPUs()
//	{
//		return resourceServer.getHistoryCpu();
//	}
}
