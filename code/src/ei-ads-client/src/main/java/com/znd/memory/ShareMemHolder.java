package com.znd.memory;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.znd.bus.common.buffer.ModelFileBuffer;
import com.znd.bus.common.model.ModelFile;
import com.znd.ei.memdb.DbEntryCollection;
import com.znd.exception.MemoryException;
import com.znd.reliability.config.ReliabilityProperties;
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
	private DbEntryCollection collection;
	
	
	@Value("${model.cachedDir}")
	private String cachedDir;
	
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
			rootDir.mkdir();
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
			
			//clear database
			
			//save model source to filesystem
			File[] files = persistModelSource(modelSourceId);
				
			//collection.createDbEntry(name)
			//currentModelSource = modelId;
			state = ShareMemState.Loaded;
			
		}
		
		return true;
	}

	public ShareMemState getState() {
		return state;
	}

	public String getCurrentModelSource() {
		return currentModelSource;
	}
}
