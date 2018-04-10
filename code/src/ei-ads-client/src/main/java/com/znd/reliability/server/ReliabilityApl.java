package com.znd.reliability.server;

import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.memdb.DbEntryOperations;
import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.utils.AppExecuteBuilder;
import com.znd.reliability.utils.AppUtil;

@Component
public class ReliabilityApl {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(ReliabilityApl.class);
	
	private String appDir;
	
	@Autowired
	private DbEntryOperations pROps;

	@Autowired
	private DbEntryOperations bPAOps;
	
	private ReliabilityProperties properties;

	

	public ReliabilityApl(ReliabilityProperties properties) {
		
		this.properties = properties;
		appDir = properties.getAppDir();
		if (!new File(appDir).exists()) {
			appDir = System.getenv("ZND_HOME")+"\\bin_x64";
			if (!new File(appDir).exists()) {
				throw new RuntimeException("no find "+properties.getAppDir()+", or "+"$ZND_HOME");
			}
		}

		appDir = Paths.get(appDir).toAbsolutePath().toString();
		LOGGER.info("reliability appdir : "+appDir);
	} 


	public void callBpaLoader(File[] files) {
		
		System.out.println("Clear bpa memdb.");
		bPAOps.clearDb();
		
		try {
			AppExecuteBuilder eb = AppUtil.execBuilder(appDir+"/"+AppUtil.GC_BPA_LOADER).addParam(appDir);
			for (File file: files) {
				eb.addParam(file.getCanonicalPath());
			}
			eb.logger((String log)->LOGGER.info(log)).exec();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void callBpa2Pr(File [] files) {
		System.out.println("Clear pr memdb.");
		pROps.clearDb();
		
		try {
			AppExecuteBuilder eb = AppUtil.execBuilder(appDir+"/"+AppUtil.GC_BPA_2_PR).addParam(appDir);
			for (File file: files) {
				eb.addParam(file.getCanonicalPath());
			}
			eb.logger((String log)->LOGGER.info(log)).exec();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
		
	
}
