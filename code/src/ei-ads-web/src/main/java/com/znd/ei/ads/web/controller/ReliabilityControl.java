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
import org.springframework.beans.factory.annotation.Value;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.ZhongND.RedisDF.exectueDF.ExectueDF;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBString;
import com.ZhongND.RedisDF.messageDF.RedissonPubManager;
import com.znd.ei.Utils;
import com.znd.ei.ads.config.AdsResult;
import com.znd.ei.ads.config.StateEstimateConfig;
import com.znd.ei.ads.config.StateSampleConfig;
import com.znd.ei.ads.web.model.ReliabilityUploadConfig;


@RestController
@RequestMapping(path = "/pr")
public class ReliabilityControl {

    private final Logger logger = LoggerFactory.getLogger(ReliabilityControl.class);

    //Save the uploaded file to this folder
    @Value("${model.cachedDir}")
    private  String UPLOADED_FOLDER;
    
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
    public @ResponseBody AdsResult  submitCalc(@ModelAttribute ReliabilityUploadConfig config) {

    	System.out.println("---------------receive submitCalc---------------");
 
        try {
        	final String modelName = config.getModelName();

        	StateSampleConfig sampleConfig = Utils.toObject(config.getSampleConfig(), StateSampleConfig.class);
        	StateEstimateConfig estimateConfig  = Utils.toObject(config.getEstimateConfig(), StateEstimateConfig.class);
        	Path path = Paths.get(UPLOADED_FOLDER, config.getModelName());
        	File file = path.toFile();
        	if (!file.exists()) {
        		file.mkdirs();
        	}
        	
            saveUploadedFiles(path, Arrays.asList(config.getFiles()), new FileByteProcessor() {
				
				@Override
				public void process(String fileName, byte[] bytes) {
					try {
						RedissonDBString dbstring = executeDF.RedissonDBString();
					} catch (RedissonDBException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			});

            sendMessage("post_Reliability", modelName);
        } catch (IOException e) {
        	return  AdsResult.fail(e.getMessage());
        }

       	System.out.println("---------------received submitCalc---------------");
        return  AdsResult.ok("accepted!");
    }
    
   
    public static void main(String [] args) {
    
    	Path path = Paths.get("e:/temp", "test1");
    	Path path1 = Paths.get(path.toAbsolutePath().toString(), "file.txt");
    	System.out.println(path1);
    }
	
    //save file
    private void saveUploadedFiles(Path base, List<MultipartFile> files, FileByteProcessor p) throws IOException {

        for (MultipartFile file : files) {

            if (file.isEmpty()) {
                continue; //next pls
            }
        
            byte[] bytes = file.getBytes();
            String fileName = file.getOriginalFilename();
            Path path = Paths.get(base.toAbsolutePath().toString(), fileName);
            logger.info("save file : "+path.toAbsolutePath().toString());
            Files.write(path, bytes);
            p.process(fileName, bytes);
        }

    }    
}
