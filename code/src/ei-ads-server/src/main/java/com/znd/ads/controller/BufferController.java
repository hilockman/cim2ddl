package com.znd.ads.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ads.model.AdsResult;
import com.znd.ads.model.CategoryInfo;
import com.znd.ads.service.BufferService;
import com.znd.bus.common.model.CategoryTypeEnum;
import com.znd.bus.config.ColumnMeta;
/**
 * 总线公共数据
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
    public @ResponseBody List<CategoryInfo> getCategories() {
    	List<CategoryInfo> bufferItems = bufferService.getDbNodes();
    	for (CategoryInfo info : bufferItems) {
    		
    		info.getChildren().addAll(bufferService.getTableNodes(info.getId(), info.getType()));
    		
    		info.setChildCount(info.getChildren().size());
    	}

    	List<CategoryInfo> items = new ArrayList<>();
    	if (bufferItems != null)
    		items.addAll(bufferItems);

    	
        return items;
    }
    
    @GetMapping("/tables")
    public @ResponseBody  List<CategoryInfo> getTables(@RequestParam(value="dbid", defaultValue="common") String dbid,
    		@RequestParam(value="type", defaultValue="common")String type) {
    	return bufferService.getTableNodes(dbid, CategoryTypeEnum.valueOf(type));
    }
    
    @GetMapping("/tableColumns/{dbid}/{tableid}")
    public @ResponseBody  List<ColumnMeta> getTableColumns(@PathVariable String dbid, @PathVariable String tableid) {    	
    	return bufferService.getTableColumns(dbid, tableid);
    }
    
    
    @GetMapping(value="/records")
    public @ResponseBody List<String[]> getRecords(@RequestParam(value="dbid", defaultValue="common") String dbid,
    		@RequestParam(value="tableid") String tableid) {
    	
    	return bufferService.getRecords(dbid, tableid);
    } 
    
    
    @DeleteMapping(value="/records")
    public @ResponseBody AdsResult removeRecords(@RequestParam(value="dbid", defaultValue="common")String dbid, 
    		@RequestParam(value="tableid") String tableid,
    		@RequestParam(value="ids") String ids) {
    	if (ids.equalsIgnoreCase("*"))
    	   bufferService.removeRecords(dbid, tableid, new String[0]);
    	else 
    	   bufferService.removeRecords(dbid, tableid, ids.split(" "));
    	return AdsResult.ok();
    }
    

    
    
}
