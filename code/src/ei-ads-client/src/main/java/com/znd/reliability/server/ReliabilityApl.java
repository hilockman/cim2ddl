package com.znd.reliability.server;

import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import antlr.Utils;

import com.znd.ads.model.PRAdequacySetting;
import com.znd.buffer.common.mapper.CalcJobMapper;
import com.znd.buffer.common.model.CalcJob;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.task.TaskQueue;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.mapper.FStateMIslandMapper;
import com.znd.reliability.mapper.FStateMapper;
import com.znd.reliability.mapper.FStateOvlAdMapper;
import com.znd.reliability.mapper.FStateOvlDevMapper;
import com.znd.reliability.model.RequestEstimate;
import com.znd.reliability.server.impl.ReliabilityProxyServer;
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


	@Autowired
	private CalcJobMapper calcJobMapper;
	
	
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
	
	
	public void reliability(String modelName) {
	
		BufferFactoryBuilder builder  = new BufferFactoryBuilder();
		BufferFactory factory = builder.build(modelName, "com.znd.buffer.reliability.model", "com.znd.buffer.reliability.mapper");
		Buffer buffer = factory.openSession();
		
		CalcJob job = calcJobMapper.findByName(modelName);
		String param = job.getParameter();

		TaskQueue<RequestEstimate> taskList = factory.config().getTaskList(job.getId());
		FStateMapper fstateMapper = factory.config().getMapper(FStateMapper.class, buffer);
		FStateOvlAdMapper fstateOvlAdMapper = factory.config().getMapper(FStateOvlAdMapper.class, buffer);
		FStateOvlDevMapper fstateOvlDevMapper = factory.config().getMapper(FStateOvlDevMapper.class, buffer);
		FStateMIslandMapper fstateMIsland = factory.config().getMapper(FStateMIslandMapper.class, buffer);

		taskList.clear();
		fstateMapper.deleteAll();
		fstateOvlAdMapper.deleteAll();
		fstateOvlDevMapper.deleteAll();
		fstateMIsland.deleteAll();
		
		PRAdequacySetting setting = new PRAdequacySetting(); 
		ProxyServer server = new ReliabilityProxyServer(properties, modelName, taskList, fstateMapper, fstateOvlAdMapper, fstateOvlDevMapper, fstateMIsland, setting);
	
		server.exec();
	
	}
		
	
}
