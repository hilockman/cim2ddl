package com.znd.ei.ads.web.controller;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.znd.ei.ads.web.model.NodeInfo;
import com.znd.ei.ads.web.service.BufferService;
import com.znd.ei.ads.web.service.MemoryService;

@RestController
@RequestMapping("/model")
public class ModelController {
	@Autowired
	private BufferService bufferService;
	
	@Autowired
	private MemoryService memoryService;
	
    @GetMapping("/categories")
    public List getCategories() {
    	List<NodeInfo> bufferItems = bufferService.getDbNodes();
    	
    	List<NodeInfo> memoryItems = memoryService.getDbNodes();
    	
    	List<NodeInfo> items = new ArrayList<>();
    	if (bufferItems != null)
    		items.addAll(bufferItems);
    	
    	if (memoryItems != null)
    		items.addAll(memoryItems);
    	
        return items;
    }
    
    @GetMapping("/tables/{dbtype}/{dbid}")
    public List getTables(@PathVariable String dbtype, @PathVariable String dbid) {
    	if (dbtype.equalsIgnoreCase(NodeInfo.MEMORY)) {
    		return memoryService.getTableNodes(dbid);
    	} else if (dbtype.equalsIgnoreCase(NodeInfo.BUFFER)) {
    		return bufferService.getTableNodes(dbid);
    	} else {
    		return null;
    	}
        
    }
    
    @GetMapping("/records/{dbtype}/{dbid}/{tableid}")
    public List getRecords(@PathVariable String dbtype, @PathVariable String dbid, @PathVariable String tableid) {
        return Arrays.asList("FState", "FDev");
    } 
    
    
}