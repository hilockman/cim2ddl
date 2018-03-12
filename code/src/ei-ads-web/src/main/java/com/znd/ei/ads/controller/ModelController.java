package com.znd.ei.ads.controller;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.znd.ei.ads.model.CategroyInfo;
import com.znd.ei.ads.service.BufferService;
import com.znd.ei.ads.service.MemoryService;

@RestController
@RequestMapping("/model")
public class ModelController {
	@Autowired
	private BufferService bufferService;
	
	@Autowired
	private MemoryService memoryService;
	
    @GetMapping("/categories")
    public List getCategories() {
    	List<CategroyInfo> bufferItems = bufferService.getDbNodes();
    	
    	List<CategroyInfo> memoryItems = memoryService.getDbNodes();
    	
    	List<CategroyInfo> items = new ArrayList<>();
    	if (bufferItems != null)
    		items.addAll(bufferItems);
    	
    	if (memoryItems != null)
    		items.addAll(memoryItems);
    	
        return items;
    }
    
    @GetMapping("/tables/{dbtype}/{dbid}")
    public List getTables(@PathVariable String dbtype, @PathVariable String dbid) {
    	if (dbtype.equalsIgnoreCase(CategroyInfo.MEMORY)) {
    		return memoryService.getTableNodes(dbid);
    	} else if (dbtype.equalsIgnoreCase(CategroyInfo.BUFFER)) {
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
