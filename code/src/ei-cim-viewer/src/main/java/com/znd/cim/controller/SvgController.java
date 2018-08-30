package com.znd.cim.controller;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.cim.model.dto.AdsResult;

@Controller
@RequestMapping("/svg")
public class SvgController {
	
	@Value("${model-path}")
	private String modelPath;
	
	private AdsResult getFile(File file) {
		StringBuffer buffer = new StringBuffer();
		try(BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(file),"UTF-8"))) {

			String line = null;
			while ((line = br.readLine()) != null) {
				buffer.append(line);
			}
			
		} catch (Exception e) {
			return  AdsResult.fail(e);
		}
        return AdsResult.ok(buffer.toString());
	}
	
	private AdsResult getFile(String filepath) {
		File file = new File(filepath);
		if (!file.exists()) {
			return AdsResult.fail("文件不存在:"+filepath);
		}
		return getFile(file);
	}
	
	@GetMapping("/file/{filename}")
    public @ResponseBody AdsResult getSvg(@PathVariable String filename) {	
		return getFile(filename);
    }
	
	@GetMapping("/file/{path}/{filename}")
	 public @ResponseBody AdsResult getSvg(@PathVariable String path, @PathVariable String filename) {		
		String filepath = modelPath+"/"+path +"/"+filename;
		return getFile(filepath);
    }
	
	@GetMapping("/test")
	 public @ResponseBody AdsResult test() {
		
       return AdsResult.ok();
   }
}
