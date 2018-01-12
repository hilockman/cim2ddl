package com.znd.ei.memdb.reliability.web;

import java.util.Arrays;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MetaTable;

@Controller
@RequestMapping(path = "/memdb")
public class PRMemDbController {
	@Autowired
	private DbEntryOperations pROps;

	@GetMapping(path = "/tables")
	public @ResponseBody String[] getTables() {
		return pROps.getTableNames();
	}

	@GetMapping(path = "/table")
	public @ResponseBody Iterable<MetaTable> getTable(@RequestParam String name) {
		if (name != null && !name.isEmpty()) {
			return  Arrays.asList(new MetaTable[]{pROps.findTableByName(name)});
		} else
			return pROps.getTables();
	}
	
	
	@GetMapping(path = "/clear")
	public @ResponseBody String clear() {
		pROps.clearDb();
		return "clear!";
	}
}
