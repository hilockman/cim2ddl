package com.znd.ei.memdb.web;

import java.util.Arrays;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ei.memdb.dao.MemDbRepository;
import com.znd.ei.memdb.dao.MemTable;

@Controller
@RequestMapping(path = "/memdb")
public class MemDbController {
	@Autowired
	private MemDbRepository memDbRepository;

	@GetMapping(path = "/tables")
	public @ResponseBody String[] getTables() {
		return memDbRepository.getTableNames();
	}

	@GetMapping(path = "/table")
	public @ResponseBody Iterable<MemTable> getTable(@RequestParam String name) {
		if (name != null && !name.isEmpty()) {
			return  Arrays.asList(new MemTable[]{memDbRepository.findTableByName(name)});
		} else
			return memDbRepository.getTables();
	}
	
	

}
