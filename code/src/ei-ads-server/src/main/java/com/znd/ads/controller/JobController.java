package com.znd.ads.controller;

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
import com.znd.ads.service.JobService;
import com.znd.bus.common.model.CalcJob;

@Controller
@RequestMapping("/job")
public class JobController {

	@Autowired
	private JobService jobService;
	
//	@GetMapping("/newjob")
//	public String newJob(Model model) {	
//		
//		return "/job/newjob";
//	}
	
	@GetMapping("/newjobname")
	public @ResponseBody String newName() {
		
		String prefix = "新建工作";
		int i = 0;
		String newName = prefix; 
		while(true) {
			newName = prefix+i;
			
			if (jobService.findJobByName(newName) == null)
				break;
			
			i++;
		}
		return newName;
	}
	
    @GetMapping("/pradequacy")
	public String newPradequacy(Model model) {	
		
		return "/job/pradequacy";
	}
	
    @GetMapping("/all")
    public @ResponseBody List<CalcJob> getAll() {
    	return jobService.getAll();
    }
    
    @GetMapping("/browse/{jobId}")
    public String browse(@PathVariable String jobId, Model m) {
    	CalcJob job = jobService.findJob(jobId);
    	m.addAttribute("job", job);
    	return "/job/browse";
    }
    
    @PostMapping("delete/{jobId}")
    public @ResponseBody AdsResult delete(@PathVariable String jobId) {
    	try {
    		jobService.delete(jobId);
    		return AdsResult.ok("Succeed to cancel job :"+jobId);
    	} catch (Throwable e) {
    		e.printStackTrace();
    		return AdsResult.fail(e.getMessage());
    	}
    }
    
    @PostMapping("cancel/{jobId}")
    public @ResponseBody AdsResult cancel(@PathVariable String jobId) {
    	try {
    		jobService.cancel(jobId);
    		return AdsResult.ok("Succeed to cancel job :"+jobId);
    	} catch (Throwable e) {
    		e.printStackTrace();
    		return AdsResult.fail(e.getMessage());
    	}
    }
   
    @PostMapping("start/{jobId}")
    public @ResponseBody AdsResult start(@PathVariable String jobId) {
    	try {
    		jobService.start(jobId);
    		return AdsResult.ok("Succeed to restart job :"+jobId);
    	} catch (Throwable e) {
    		e.printStackTrace();
    		return AdsResult.fail(e.getMessage());
    	}
    }    
        
    @PostMapping("create")
    public @ResponseBody AdsResult create(CalcJob job) {
    	try {    	
	    	//System.out.println(job);
	    	jobService.create(job);
	    	return AdsResult.ok();
	    } catch (Throwable e) {
	    	e.printStackTrace();
			return AdsResult.fail(e.getMessage());
		}
    }

}
