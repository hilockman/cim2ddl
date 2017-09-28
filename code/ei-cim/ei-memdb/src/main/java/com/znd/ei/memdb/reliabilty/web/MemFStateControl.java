package com.znd.ei.memdb.reliabilty.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ei.memdb.reliabilty.dao.FStateRepository;

@Controller
@RequestMapping(path = "/memfstate")
public class MemFStateControl {
	@Autowired
	private FStateRepository pROps;
	
	
	@GetMapping(path = "/records")
	public @ResponseBody Iterable getRecords() {
		return pROps.findAll();
	}
}
