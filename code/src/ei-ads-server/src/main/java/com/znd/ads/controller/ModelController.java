package com.znd.ads.controller;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ads.model.AdsResult;
import com.znd.ads.model.ModelData;
import com.znd.ads.model.po.ModelSource;
import com.znd.ads.service.JobService;
import com.znd.ads.service.ModelService;
import com.znd.bus.common.model.CalcJob;

@Controller
@RequestMapping("/model")
public class ModelController {
	@Autowired 
	private ModelService modelService;
	
	@Autowired
	private JobService jobService;
	
	 @GetMapping("/browse/{modelId}")
	 public String browse(@PathVariable String modelId, Model m) {
		
		 ModelSource ms = modelService.findModel(modelId);
		 m.addAttribute("modelSource", ms);
		 return "model";
	 }
	 
    /**
     * 获得所有模型目录名称
     * @return
     */
    @GetMapping("/all")
    public @ResponseBody List getAll() {
    	
    	return  modelService.getAll();
	 }	 

    /**
     * 获得所有模型目录名称
     * @return
     */
    @GetMapping("/roots")
    public @ResponseBody List getRoots() {
    	
    	return  modelService.getRoots();
	 }	 
    
    
    @PostMapping("/upload")
    public @ResponseBody AdsResult upload(ModelData model) {
    	try {
    		modelService.upload(model);
    		return AdsResult.ok();
    	} catch (Throwable e) {
    		//e.printStackTrace();
    		return AdsResult.fail(e.getMessage());
    	}
    }
    
    @PostMapping("/remove/{modelId}") 
    public @ResponseBody AdsResult remove(@PathVariable String modelId) {
    	try {
    		List<CalcJob> jobs = jobService.findByModel(modelId);
    		if (jobs != null && !jobs.isEmpty()) {
    			List<String> names = new ArrayList<>();
    			for (CalcJob job : jobs) {
    				names.add(job.getName());
    			}
    			return AdsResult.fail(String.format("模型'%s'已被工作使用：%s", modelId, String.join(",", names)));
    		}
    		modelService.remove(modelId);
    		return AdsResult.ok();
    	} catch (Throwable e) {
    		//e.printStackTrace();
    		return AdsResult.fail(e.getMessage());
    	}
    }
    
    @GetMapping("/file/{folder}/{fileName}")
    public @ResponseBody AdsResult getFile(@PathVariable String folder, @PathVariable String fileName) {
    	return AdsResult.ok(jobService.getFile(folder, fileName));
    }
}

