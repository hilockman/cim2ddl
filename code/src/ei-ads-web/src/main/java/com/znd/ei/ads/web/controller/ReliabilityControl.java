package com.znd.ei.ads.web.controller;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Arrays;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.ZhongND.RedisDF.exectueDF.ExectueDF;
import com.ZhongND.RedisDF.messageDF.RedissonPubManager;
import com.znd.ei.Utils;
import com.znd.ei.ads.config.AdsResult;
import com.znd.ei.ads.config.StateEstimateConfig;
import com.znd.ei.ads.config.StateSampleConfig;
import com.znd.ei.ads.web.model.ReliabilityConfig;


@RestController
@RequestMapping(path = "/pr")
public class ReliabilityControl {

    private final Logger logger = LoggerFactory.getLogger(ReliabilityControl.class);

    //Save the uploaded file to this folder
    private static String UPLOADED_FOLDER = "e://temp//";
    
	@Autowired
	private ExectueDF executeDF;
	
	private void sendMessage(String contentCode, String key) {

		if (contentCode == null || contentCode.isEmpty()) {
			return;
		}
		RedissonPubManager msg = executeDF.RedissonPubManager();


		try {
			String strMessage = msg.setMessage(contentCode, key);
			msg.setMessage(contentCode, strMessage);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@RequestMapping(path = "/stateSampleConfig", method = RequestMethod.GET)
	public @ResponseBody StateSampleConfig stateSampleConfig() {
		StateSampleConfig config = new StateSampleConfig();
		return config;
	}
	
	@RequestMapping(path = "/stateEstimateConfig", method = RequestMethod.GET)
	public @ResponseBody StateEstimateConfig stateEstimateConfig() {
		StateEstimateConfig config = new StateEstimateConfig();
		return config;
	}

	@RequestMapping(path = "/serverConfig", method = RequestMethod.GET)
	public @ResponseBody StateEstimateConfig serverConfig() {
		StateEstimateConfig config = new StateEstimateConfig();
		return config;
	}
	
	@RequestMapping(path = "/calcReliability", method = RequestMethod.POST)
	public @ResponseBody AdsResult calcReliability(StateSampleConfig sampleConfig, StateEstimateConfig estimateConfig) {
		System.out.println("---------------start calcReliability---------------");
		System.out.println("calcReliability : sampleConfig = "+sampleConfig.toString());
		System.out.println("calcReliability : estimateConfig = "+estimateConfig.toString());
		System.out.println("---------------end calcReliability---------------");
		
		return  AdsResult.ok("accepted!");
	}
	
	@RequestMapping(path = "/uploadFile", method=RequestMethod.POST)
	public @ResponseBody String handelUploadFile(  @RequestParam("file") MultipartFile file)
	{
		 String name = "test11";
	        if (!file.isEmpty()) {
	            try {
	                byte[] bytes = file.getBytes();
	                BufferedOutputStream stream = 
	                        new BufferedOutputStream(new FileOutputStream(new File(name + "-uploaded")));
	                stream.write(bytes);
	                stream.close();
	                return "You successfully uploaded " + name + " into " + name + "-uploaded !";
	            } catch (Exception e) {
	                return "You failed to upload " + name + " => " + e.getMessage();
	            }
	        } else {
	            return "You failed to upload " + name + " because the file was empty.";
	        }	
	}
	

//    // 3.1.3 maps html form to a Model
//    @PostMapping("/submitCalc")
//    public ResponseEntity<?> submitCalc(@ModelAttribute ReliabilityConfig model) {
//
//        logger.debug("Multiple file upload! With UploadModel");
//
//        try {
//
//        	StateSampleConfig sampleConfig = Utils.toObject(model.getSampleConfig(), StateSampleConfig.class);
//        	StateEstimateConfig estimateConfig  = Utils.toObject(model.getSampleConfig(), StateEstimateConfig.class);
//        	
//            saveUploadedFiles(Arrays.asList(model.getFiles()));
//
//        } catch (IOException e) {
//            return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
//        }
//
//        return new ResponseEntity("Successfully uploaded!", HttpStatus.OK);
//    }
    
    // 3.1.3 maps html form to a Model
    @PostMapping("/submitCalc")
    public @ResponseBody AdsResult  submitCalc(@ModelAttribute ReliabilityConfig model) {

        logger.debug("Multiple file upload! With UploadModel");

        try {

        	StateSampleConfig sampleConfig = Utils.toObject(model.getSampleConfig(), StateSampleConfig.class);
        	StateEstimateConfig estimateConfig  = Utils.toObject(model.getSampleConfig(), StateEstimateConfig.class);
        	
            saveUploadedFiles(Arrays.asList(model.getFiles()));

        } catch (IOException e) {
        	return  AdsResult.fail(e.getMessage());
        }

        return  AdsResult.ok("accepted!");
    }
    
   
	
    //save file
    private void saveUploadedFiles(List<MultipartFile> files) throws IOException {

        for (MultipartFile file : files) {

            if (file.isEmpty()) {
                continue; //next pls
            }

            byte[] bytes = file.getBytes();
            Path path = Paths.get(UPLOADED_FOLDER + file.getOriginalFilename());
            Files.write(path, bytes);

        }

    }    
}
