package com.znd.memory;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.ZhongND.memdb.MDBDefine;
import com.znd.bus.common.buffer.ModelFileBuffer;
import com.znd.bus.common.buffer.ModelSourceBuffer;
import com.znd.bus.common.model.ModelFile;
import com.znd.ei.memdb.DbEntry;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.exception.MemoryException;
import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.utils.AppExecuteBuilder;
import com.znd.reliability.utils.AppUtil;

@Component
public class ShareMemHolder {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(ShareMemHolder.class);
	
	
	
	private String appDir;
	
	private ShareMemState state = ShareMemState.Uninitialized;
		
	private String currentModelSource;
	
	
	@Autowired
	private ModelFileBuffer modelFileBuffer;
		
	@Autowired
	private ModelSourceBuffer modelSourceBuffer;
	
	@Autowired 
	private DbEntryCollection collection;
	
	
	@Value("${model.cachedDir}")
	private String cachedDir;
	
	
	
	//private Map<DatabaseType, String> type2Name = new HashMap<>();
	
	public ShareMemHolder(ReliabilityProperties properties) {
		
		//this.properties = properties;
		appDir = properties.getAppDir();
		if (!new File(appDir).exists()) {
			appDir = System.getenv("ZND_HOME")+"\\bin_x64";
			if (!new File(appDir).exists()) {
				throw new RuntimeException("no find "+properties.getAppDir()+", or "+"$ZND_HOME");
			}
		}

		appDir = Paths.get(appDir).toAbsolutePath().toString();
		//logger.info("reliability appdir : "+appDir);
		registDabaseLoader();
	} 
	
	
	
	public static class LoaderInfo {
		//数据库类型
		private DatabaseType type;
		
		//数据库名称
		private String entryName;

		//初始化进程名称
		private String appName;
		
		//后缀名称
		private String[] filePostfixes;
		
		public LoaderInfo(DatabaseType type, String entryName, String appName, String[] postfixes ) {
			this.type = type;
			this.entryName = entryName;
			this.appName = appName;
			this.filePostfixes = postfixes;
		}
	}
	

	
	private Map<DatabaseType, LoaderInfo> loaderMap = new HashMap<>();
	
	private void registDabaseLoader() {
		
		LoaderInfo[] infos = {
				new LoaderInfo(DatabaseType.BPA, MDBDefine.g_strBpaDBEntry, AppUtil.GC_BPA_LOADER, new String[]{"dat", "swi"}),
				new LoaderInfo(DatabaseType.PR, MDBDefine.g_strPRDBEntry, AppUtil.GC_BPA_2_PR, new String[]{"dat", "swi", "xml"}),
		};
		

		for (LoaderInfo info : infos) {
			loaderMap.put(info.type, info);
		}
		

	}





	@PostConstruct
	public void init() {

		new Thread(() -> {
			if (AppUtil.isRunning("MemStarter")) {
				LOGGER.info("MemStarter is running.");
				
			} else {
				LOGGER.info("Will to start MemStarter...");
				AppUtil.execBuilder(appDir+"/MemStarter").addParam("-s").exec();
				LOGGER.info("MemStarter started.");
			}
		}).start();	
	}
	
	
	@PreDestroy
	public void destory() {
		new Thread(() -> {
			LOGGER.info("Will to kill MemStarter.");
			AppUtil.execBuilder(appDir+"/MemStarter").addParam("-k").exec();
			LOGGER.info("MemStarter is killed.");
			
		}).start();	
	}
	
	
	private File[] persistModelSource(String modelSourceId) {
		List<ModelFile> fileRecords = modelFileBuffer.findBy(modelSourceId);
		if (fileRecords.isEmpty())
			return null;
		
		File[] files = new File[fileRecords.size()];
		Path rootPath = Paths.get(cachedDir, modelSourceId);
		File rootDir = rootPath.toFile();
		if (!rootDir.exists()) {
			rootDir.mkdirs();
		} else {
			//TODO: remove model files
		}
		int i= 0;
		for (ModelFile fileRec : fileRecords) {
			
			Path filePath = Paths.get(rootDir.getAbsolutePath(), fileRec.getName());
			File file = filePath.toFile();
			//LOGGER.info("save file : {} ", file.getAbsolutePath());
			FileWriter fw = null;
			try {
				fw = new FileWriter(file);
				
				
				fw.write(fileRec.getContent());				
								
				fw.close();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				//e.printStackTrace();
				//return false;
				
				throw new MemoryException("Fail to save file :"+fileRec.getName(), e);
			}
			
			files[i++] = file;
		}
		
		return files;
	}
	
	public boolean reload(String modelSourceId, DatabaseType type) {
		synchronized(state) {
			state = ShareMemState.Loading;

			//save model source to filesystem
			File[] files = persistModelSource(modelSourceId);
				
			//初始化内存库
			reloadMemory(type, files);
					
			state = ShareMemState.Loaded;
			currentModelSource = modelSourceId;
		}
		
		return true;
	}

	private void reloadMemory(DatabaseType type, File[] files) {
		LoaderInfo info = loaderMap.get(type);
		if (info == null)
			throw new MemoryException("Fail to find dabase loader :"+type);
		System.out.println("Clear memdb : "+info.entryName);
		DbEntry ops = collection.findDbEntry(info.entryName);
		ops.clearDb();
		Map<String, Integer> posMap = new HashMap<>();
		int i = 0;
		for (String postfix: info.filePostfixes) {
			posMap.put(postfix, i++);
		}
		
		File[] sortedFiles = new File[info.filePostfixes.length];
		for (File file : files) {
			
			String fileName = file.getName();
			
			int pos = fileName.lastIndexOf('.');
			String postfix = "";
			if (pos >= 0) {
				postfix = fileName.substring(pos+1);
			}
			
			Integer index = posMap.get(postfix);
			if (index == null) {
				continue;
			}
			
			sortedFiles[index] = file;
		}
		
		for (i = 0; i < sortedFiles.length; i++) {
			if (sortedFiles[i] == null)
			  throw new MemoryException(String.format("Model files are incomplete, missing file '%s'  :", info.filePostfixes[i]));		
		}
		
		try {
			AppExecuteBuilder eb = AppUtil.execBuilder(appDir+"/"+info.appName).addParam(appDir);
			for (File file: sortedFiles) {
				eb.addParam(file.getCanonicalPath());
			}
			eb.logger((String log)->LOGGER.info(log)).exec();
		} catch (IOException e) {
			e.printStackTrace();			
			throw new MemoryException("Fail to load dabase :"+info.entryName+", appName:"+info.appName);
		}
	}





	public ShareMemState getState() {
		return state;
	}

	public String getCurrentModelSource() {
		return currentModelSource;
	}





	public void clear() {
		currentModelSource = null;	
	}
}
