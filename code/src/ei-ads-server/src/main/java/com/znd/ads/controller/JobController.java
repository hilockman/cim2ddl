package com.znd.ads.controller;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
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
	
	@GetMapping("/newjob")
	public String newJob(Model model) {	
		
		return "/job/newjob";
	}
	
	@GetMapping("/newjobname")
	public @ResponseBody String newJobName() {
		
		String prefix = "newjob";
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
    public @ResponseBody List getAllJobs() {
    	return jobService.getAll();
    }
    
    @GetMapping("/browse/{jobId}")
    public String browse(@PathVariable String jobId, Model m) {
    	CalcJob job = jobService.findJob(jobId);
    	m.addAttribute("job", job);
    	return "/job/browse";
    }
    
    @PostMapping("cancel/{jobId}")
    public @ResponseBody AdsResult cancel(@PathVariable String jobId) {
    	try {
    		jobService.cancel(jobId);
    		return AdsResult.ok("Succeed to cancel job :"+jobId);
    	} catch (Throwable e) {
    		return AdsResult.fail(e.getMessage());
    	}
    }
    
    @PostMapping("stop/{jobId}")
    public @ResponseBody AdsResult stop(@PathVariable String jobId) {
    	try {
    		jobService.stop(jobId);
    		return AdsResult.ok("Succeed to cancel job :"+jobId);
    	} catch (Throwable e) {
    		return AdsResult.fail(e.getMessage());
    	}
    }

    @PostMapping("pause/{jobId}")
    public @ResponseBody AdsResult pause(@PathVariable String jobId) {
    	try {
    		jobService.pause(jobId);
    		return AdsResult.ok("Succeed to cancel job :"+jobId);
    	} catch (Throwable e) {
    		return AdsResult.fail(e.getMessage());
    	}
    }
    
    @PostMapping("restart/{jobId}")
    public @ResponseBody AdsResult restart(@PathVariable String jobId) {
    	try {
    		jobService.restart(jobId);
    		return AdsResult.ok("Succeed to restart job :"+jobId);
    	} catch (Throwable e) {
    		return AdsResult.fail(e.getMessage());
    	}
    }    
    
    
    @PostMapping("add")
    public @ResponseBody AdsResult add(CalcJob job) {
    	try {    	
	    	//System.out.println(job);
	    	jobService.add(job);
	    	return AdsResult.ok();
	    } catch (Throwable e) {
			return AdsResult.fail(e.getMessage());
		}
    }

}
