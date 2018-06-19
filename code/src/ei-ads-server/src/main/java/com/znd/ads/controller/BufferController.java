package com.znd.ads.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ads.model.CategoryInfo;
import com.znd.ads.service.BufferService;
/**
 * 总线缓存数据
 * @author wangheng
 * @date 2018年5月24日
 * @time 上午11:11:03
 * @type_name BufferController
 */
@Controller
@RequestMapping("/buffer")
public class BufferController {
	@Autowired
	private BufferService bufferService;
	
//	@Autowired
//	private MemoryService memoryService;
	

    @GetMapping("/categories")
    public @ResponseBody List getCategories() {
    	List<CategoryInfo> bufferItems = bufferService.getDbNodes();
    	for (CategoryInfo info : bufferItems) {
    		
    		info.getChildren().addAll(bufferService.getTableNodes(info.getId()));
    		
    		info.setChildCount(info.getChildren().size());
    	}
    	//List<CategroyInfo> memoryItems = memoryService.getDbNodes();
    	
    	List<CategoryInfo> items = new ArrayList<>();
    	if (bufferItems != null)
    		items.addAll(bufferItems);
    	
//    	if (memoryItems != null)
//    		items.addAll(memoryItems);
    	
        return items;
    }
    
    @GetMapping("/tables/{dbtype}/{dbid}")
    public @ResponseBody  List getTables(@PathVariable String dbtype, @PathVariable String dbid) {
//    	if (dbtype.equalsIgnoreCase(CategroyInfo.MEMORY)) {
//    		return memoryService.getTableNodes(dbid);
//    	} else 
    	if (dbtype.equalsIgnoreCase(CategoryInfo.BUFFER)) {
    		return bufferService.getTableNodes(dbid);
    	} else {
    		return null;
    	}
        
    }
    @GetMapping("/tableColumns/{dbid}/{tableid}")
    public @ResponseBody  List getTableColumns(@PathVariable String dbid, @PathVariable String tableid) {
    	
    	return bufferService.getTableColumns(dbid, tableid);
       // return Arrays.asList("FState", "FDev");
    }
    
    
    @GetMapping("/records/{dbid}/{tableid}")
    public @ResponseBody List getRecords(@PathVariable String dbid, @PathVariable String tableid) {
    	
    	return bufferService.getRecords(dbid, tableid);
       // return Arrays.asList("FState", "FDev");
    } 
    

    
    
}
