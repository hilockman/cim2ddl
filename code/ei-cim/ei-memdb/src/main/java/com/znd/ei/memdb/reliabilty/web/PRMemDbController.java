package com.znd.ei.memdb.reliabilty.web;

import java.util.Arrays;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MemTable;

@Controller
@RequestMapping(path = "/memdb")
public class PRMemDbController {
	@Autowired
	private DbEntryOperations pRMemTableOperations;

	@GetMapping(path = "/tables")
	public @ResponseBody String[] getTables() {
		return pRMemTableOperations.getTableNames();
	}

	@GetMapping(path = "/table")
	public @ResponseBody Iterable<MemTable> getTable(@RequestParam String name) {
		if (name != null && !name.isEmpty()) {
			return  Arrays.asList(new MemTable[]{pRMemTableOperations.findTableByName(name)});
		} else
			return pRMemTableOperations.getTables();
	}
	
	
	@GetMapping(path = "/clear")
	public @ResponseBody String clear() {
		pRMemTableOperations.clearDb();
		return "clear!";
	}
}
