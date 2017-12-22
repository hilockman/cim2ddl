package com.znd.ei.ads.web.controller;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.ZhongND.RedisDF.exectueDF.ExectueDF;
import com.ZhongND.RedisDF.exectueDF.ResultObject;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBKey;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBList;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBMap;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBString;
import com.ZhongND.RedisDF.messageDF.RedissonPubManager;
import com.znd.ei.Utils;
import com.znd.ei.ads.config.AdsResult;
import com.znd.ei.ads.config.FileInfo;
import com.znd.ei.ads.config.PRAdequacySetting;
import com.znd.ei.ads.web.model.ReliabilityUploadConfig;

@RestController
@RequestMapping(path = "/pr")
public class ReliabilityControl {

	private final Logger logger = LoggerFactory
			.getLogger(ReliabilityControl.class);

	// Save the uploaded file to this folder
	@Value("${model.cachedDir}")
	private String UPLOADED_FOLDER;

	@Autowired
	private ExectueDF executeDF;

	private void sendMessage(String contentCode, String key) {

		if (contentCode == null || contentCode.isEmpty()) {
			return;
		}
		RedissonPubManager msg = executeDF.RedissonPubManager();

		try {
			String strMessage = msg.setMessage(contentCode, key);
			msg.pubMessage(strMessage);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	@RequestMapping(path = "/adequacySetting", method = RequestMethod.GET)
	public @ResponseBody PRAdequacySetting prAdequacySetting() {
		PRAdequacySetting config = new PRAdequacySetting();
//		String str = Utils.toJSon(config);
//		return str;
		return config;
	}


	private static final String SUCCESS = "success.html";
	private static final String FAIL = "fail.html";
	
	@PostMapping(path="/testSubmit")
	public String testSubmit(Model model) {
		
		System.out.println("Recevied submit");
		return SUCCESS;
	}
	
	
//	@RequestMapping(path = "/stateEstimateConfig", method = RequestMethod.GET)
//	public @ResponseBody StateEstimateConfig stateEstimateConfig() {
//		StateEstimateConfig config = new StateEstimateConfig();
//		return config;
//	}
//
//	@RequestMapping(path = "/serverConfig", method = RequestMethod.GET)
//	public @ResponseBody StateEstimateConfig serverConfig() {
//		StateEstimateConfig config = new StateEstimateConfig();
//		return config;
//	}
//
//	@RequestMapping(path = "/calcReliability", method = RequestMethod.POST)
//	public @ResponseBody AdsResult calcReliability(
//			StateSampleConfig sampleConfig, StateEstimateConfig estimateConfig) {
//		System.out
//				.println("---------------start calcReliability---------------");
//		System.out.println("calcReliability : sampleConfig = "
//				+ sampleConfig.toString());
//		System.out.println("calcReliability : estimateConfig = "
//				+ estimateConfig.toString());
//		System.out.println("---------------end calcReliability---------------");
//
//		return AdsResult.ok("accepted!");
//	}

//	@RequestMapping(path = "/uploadFile", method = RequestMethod.POST)
//	public @ResponseBody String handelUploadFile(
//			@RequestParam("file") MultipartFile file) {
//		String name = "test11";
//		if (!file.isEmpty()) {
//			try {
//				byte[] bytes = file.getBytes();
//				BufferedOutputStream stream = new BufferedOutputStream(
//						new FileOutputStream(new File(name + "-uploaded")));
//				stream.write(bytes);
//				stream.close();
//				return "You successfully uploaded " + name + " into " + name
//						+ "-uploaded !";
//			} catch (Exception e) {
//				return "You failed to upload " + name + " => " + e.getMessage();
//			}
//		} else {
//			return "You failed to upload " + name
//					+ " because the file was empty.";
//		}
//	}

	// // 3.1.3 maps html form to a Model
	// @PostMapping("/submitCalc")
	// public ResponseEntity<?> submitCalc(@ModelAttribute ReliabilityConfig
	// model) {
	//
	// logger.debug("Multiple file upload! With UploadModel");
	//
	// try {
	//
	// StateSampleConfig sampleConfig = Utils.toObject(model.getSampleConfig(),
	// StateSampleConfig.class);
	// StateEstimateConfig estimateConfig =
	// Utils.toObject(model.getSampleConfig(), StateEstimateConfig.class);
	//
	// saveUploadedFiles(Arrays.asList(model.getFiles()));
	//
	// } catch (IOException e) {
	// return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
	// }
	//
	// return new ResponseEntity("Successfully uploaded!", HttpStatus.OK);
	// }

	// 3.1.3 maps html form to a Model

	public static int MAX_FILE_SIZE = 1024 * 1024 * 5;
	public static long MAX_FILE_TIME_OUT = 6000l;
	public static long MAX_LOG_TIME_OUT = 6000l;

	@RequestMapping("/log/{modelName}")
	public @ResponseBody List<String> getModelLog(
			@PathVariable("modelName") String modelName) {

		System.out.println("------------getModelLog-------------");
		String key = modelName + ":log";
		
		try {
			RedissonDBKey keyOps = executeDF.RedissonDBKey();
			ResultObject<String, Boolean> rt1 = keyOps.EXISTS(key);
			if (!rt1.getValue()) {
				return null;
			}
			List<String> strs = new ArrayList<String>();
			RedissonDBList listOps;
			listOps = executeDF.RedissonDBList();
			ResultObject<String, String> rt = null;
			int sum = 0;
			while ((rt = listOps.LockLPOP(key, MAX_LOG_TIME_OUT)) != null && sum < 5) {

				strs.add(rt.getValue());
				sum++;
			}
			
			return strs;

		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return null;

	}
	
	@PostMapping("/clearDatabase/{modelName}")
	public @ResponseBody String clearDatabase(@PathVariable("modelName")String modelName) {
		sendMessage("clear_Database", modelName);
		return "ok";
	}
	
	@RequestMapping("/testMap/{count}")
	public void testMap(@PathVariable("count")int count) {
		try {
			System.out.println("map count:"+count);
			RedissonDBMap m = executeDF.RedissonDBMap();
			for (int i = 0; i < count; i++) {
				Map<Integer, String> m1 = new HashMap<Integer, String>();
				System.out.println("i="+i);
				m1.put(i, "key"+i);
				m.LockHMSET("testMap", MAX_FILE_TIME_OUT, m1);
			}
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
	}

	@PostMapping("/submitCalc")
	public @ResponseBody AdsResult submitCalc(
			@ModelAttribute ReliabilityUploadConfig config) {

		System.out.println("---------------start submitCalc---------------");

		try {
			final String modelName = config.getModelName();
			final String modelNameTag = modelName;
			
			List<ResultObject<String, String>> keys = executeDF.RedissonDBKey().FindKeys(modelName+"*");
			for (int i = 0; i < keys.size(); i++) {
				executeDF.RedissonDBKey().BatchDEL(keys.get(0).getValue());
			}

			Path path = Paths.get(UPLOADED_FOLDER, config.getModelName());
			File file = path.toFile();
			if (!file.exists()) {
				file.mkdirs();
			}

			
			saveUploadedFiles(path, Arrays.asList(config.getFiles()), null);

			if (file.isDirectory()) { // try upload loacal file
				RedissonDBString dbstring = executeDF.RedissonDBString();

				byte[] buff = new byte[MAX_FILE_SIZE];
				File[] files = file.listFiles();
				for (File f : files) {
					String fileName = f.getName();
					int pos = fileName.lastIndexOf('.');
					String suffix = fileName.substring(pos+1);

					String keyBase = modelNameTag + ":file:" + suffix;
					
					
					InputStream is = new FileInputStream(f);
					int off = 0;
					int fileIndex = 0;
					// int count = 0;
					int readCount = 0;
					executeDF.RedissonDBKey().BatchDEL(keyBase);
					while (off < buff.length && (readCount = is.read(buff, off, buff.length - off)) > 0) {
						// count += readCount;
						String key = keyBase;
						if (fileIndex > 0) {
							key = key + ":" + fileIndex;
							executeDF.RedissonDBKey().BatchDEL(key);
						}
						
						logger.info(
								"Upload local file to redis : key = {}, size = {}. ",
								key, readCount);
						dbstring.LockSET(key, MAX_FILE_TIME_OUT, new String(buff, 0,readCount));
						fileIndex++;
						off += readCount;
					}
					
					FileInfo fileInfo = new FileInfo(fileName, fileIndex, off);
					dbstring.LockSET(keyBase+":info", MAX_FILE_TIME_OUT, Utils.toJSon(fileInfo));
					if (fileIndex > 1) {
						logger.info("Uploaded file {} , sum size = {}, split count = {}", fileName, off, fileIndex);
					}
					is.close();
				}
			}


			RedissonDBString dbstring = executeDF.RedissonDBString();
			String key = modelNameTag + ":config:PRAdequacySetting";
			//String value  = Utils.toJSon((PRAdequacySetting)config);
			String value  = config.getSetting();
			logger.info("Upload config to redis : key = {}, content = {}. ",
					key, value);
			dbstring.<String> SET(key, MAX_FILE_TIME_OUT,
					value);

			logger.info("sendMessage : cc = {}, content = {}. ",
					"created_ReliabilityTask", modelName);
			sendMessage("created_ReliabilityTask", modelName);
		} catch (Exception e) {
			e.printStackTrace();
			return AdsResult.fail(e.getMessage());
		}

		System.out.println("---------------finished submitCalc---------------");
		return AdsResult.ok("accepted!");
	}

//	@PostMapping("/submitCalc")
//	public String submitCalc(
//			@ModelAttribute ReliabilityUploadConfig config) {
//
//		System.out.println("---------------start submitCalc---------------");
//
////		try {
////			final String modelName = config.getModelName();
////			final String modelNameTag = modelName;
////			
////			List<ResultObject<String, String>> keys = executeDF.RedissonDBKey().FindKeys(modelName+"*");
////			for (int i = 0; i < keys.size(); i++) {
////				executeDF.RedissonDBKey().BatchDEL(keys.get(0).getValue());
////			}
////
////			Path path = Paths.get(UPLOADED_FOLDER, config.getModelName());
////			File file = path.toFile();
////			if (!file.exists()) {
////				file.mkdirs();
////			}
////
////			
////			saveUploadedFiles(path, Arrays.asList(config.getFiles()), null);
////
////			if (file.isDirectory()) { // try upload loacal file
////				RedissonDBString dbstring = executeDF.RedissonDBString();
////
////				byte[] buff = new byte[MAX_FILE_SIZE];
////				File[] files = file.listFiles();
////				for (File f : files) {
////					String fileName = f.getName();
////					int pos = fileName.lastIndexOf('.');
////					String suffix = fileName.substring(pos+1);
////
////					String keyBase = modelNameTag + ":file:" + suffix;
////					
////					
////					InputStream is = new FileInputStream(f);
////					int off = 0;
////					int fileIndex = 0;
////					// int count = 0;
////					int readCount = 0;
////					while (off < buff.length && (readCount = is.read(buff, off, buff.length - off)) > 0) {
////						// count += readCount;
////						String key = keyBase;
////						if (fileIndex > 0) {
////							key = key + ":" + fileIndex;
////						}
////						logger.info(
////								"Upload local file to redis : key = {}, size = {}. ",
////								key, readCount);
////						dbstring.LockSET(key, MAX_FILE_TIME_OUT, new String(buff, 0,readCount));
////						fileIndex++;
////						off += readCount;
////					}
////					
////					FileInfo fileInfo = new FileInfo(fileName, fileIndex, off);
////					dbstring.LockSET(keyBase+":info", MAX_FILE_TIME_OUT, Utils.toJSon(fileInfo));
////					if (fileIndex > 1) {
////						logger.info("Uploaded file {} , sum size = {}, split count = {}", fileName, off, fileIndex);
////					}
////					is.close();
////				}
////			}
////
////
////			RedissonDBString dbstring = executeDF.RedissonDBString();
////			String key = modelNameTag + ":config:PRAdequacySetting";
////			//String value  = Utils.toJSon((PRAdequacySetting)config);
////			String value  = config.getSetting();
////			logger.info("Upload config to redis : key = {}, content = {}. ",
////					key, value);
////			dbstring.<String> SET(key, MAX_FILE_TIME_OUT,
////					value);
////
////			logger.info("sendMessage : cc = {}, content = {}. ",
////					"post_Reliability", modelName);
////			sendMessage("post_Reliability", modelName);
////		} catch (Exception e) {
////			e.printStackTrace();
////			return FAIL;
////		}
//
//		System.out.println("---------------finished submitCalc---------------");
//		return SUCCESS;
//	}
	public static void main(String[] args) {

		Path path = Paths.get("e:/temp", "test1");
		Path path1 = Paths.get(path.toAbsolutePath().toString(), "file.txt");
		System.out.println(path1);
	}

	// save file
	private boolean saveUploadedFiles(Path base, List<MultipartFile> files,
			FileByteProcessor p) throws IOException {

		boolean flag = false;
		for (MultipartFile file : files) {

			if (file.isEmpty()) {
				continue; // next pls
			}

			byte[] bytes = file.getBytes();
			String fileName = file.getOriginalFilename();
			Path path = Paths.get(base.toAbsolutePath().toString(), fileName);
			logger.info("save file : " + path.toAbsolutePath().toString());
			Files.write(path, bytes);
			if (p != null)
				p.process(fileName, bytes);
			flag = true;
		}

		return flag;

	}
}
