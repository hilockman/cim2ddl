package com.znd.controller;

import java.util.Arrays;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.server.MemoryServer;


@Controller
public class MemoryController {

	
	@Autowired
	private MemoryServer memoryServer;
	
	
	@GetMapping("/memory/dbList")
	public @ResponseBody List dbList() {
		return Arrays.asList(memoryServer.getConnections());
	}
	
	@GetMapping("/memory/tableList/{dbName}")
	public  @ResponseBody List tableList(@PathVariable String dbName) {
		return memoryServer.getTables(dbName);
	}
	
	
	@GetMapping("/memory/recordList/{dbname}/{tableName}")
	public  @ResponseBody List recordList(@PathVariable String dbName, @PathVariable String tableName) {
		return memoryServer.getRecords(dbName, tableName);
	}	
	
	@GetMapping("/memory/recordSize/{dbname}/{tableName}")
	public  @ResponseBody Integer recordSize(@PathVariable String dbName, @PathVariable String tableName) {
		return memoryServer.getRecordSize(dbName, tableName);
	}	
}
