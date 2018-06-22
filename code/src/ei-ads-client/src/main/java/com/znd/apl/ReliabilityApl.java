package com.znd.apl;


import java.io.File;
import java.io.IOException;
import java.nio.file.Paths;
import java.util.Collections;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.apl.annotation.AplController;
import com.znd.apl.annotation.AplFunction;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.channel.Channel;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.buffer.ModelFileBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.event.AplContext;
import com.znd.exception.AplException;
import com.znd.memory.DatabaseType;
import com.znd.memory.ShareMemHolder;
import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.server.BufferServer;
import com.znd.reliability.server.PrMemoryServer;
import com.znd.reliability.server.ProxyServer;
import com.znd.reliability.server.impl.BufferServerImpl;
import com.znd.reliability.server.impl.ReliabilityProxyServer;
import com.znd.reliability.utils.AppExecuteBuilder;
import com.znd.reliability.utils.AppUtil;

@AplController(value="reliability", desc="可靠性计算")
public class ReliabilityApl {
	private static final Logger logger = LoggerFactory
			.getLogger(ReliabilityApl.class);
	
	private String appDir;
	
	@Autowired
	private DbEntryOperations pROps;

	@Autowired
	private DbEntryOperations bPAOps;
	
	
	private ReliabilityProperties properties;

	@Autowired
	private Buffer defaultBuffer;

	@Autowired
	private CalcJobBuffer calcJobBuffer;
	
	@Autowired
	private ModelFileBuffer modelFileBuffer;
	
	@Autowired
	private PrMemoryServer memoryServer;
	
	
	@Autowired
	private Channel commonChannel;
	
	
	@Autowired
	private ShareMemHolder memHolder;
	
	
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
		logger.info("reliability appdir : "+appDir);
		
		//System.exit(0);
	} 


	public void callBpaLoader(File[] files) {
		
		System.out.println("Clear bpa memdb.");
		bPAOps.clearDb();
		
		try {
			AppExecuteBuilder eb = AppUtil.execBuilder(appDir+"/"+AppUtil.GC_BPA_LOADER).addParam(appDir);
			for (File file: files) {
				eb.addParam(file.getCanonicalPath());
			}
			eb.logger((String log)->logger.info(log)).exec();
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
			eb.logger((String log)->logger.info(log)).exec();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}		
	}
	
	public void sample(PRAdequacySetting config) {
		System.out.println("call StateSample , config = "+config);
		AppUtil.execBuilder(appDir+"/"+AppUtil.GC_STATE_SAMPLE).addParam(appDir)
		// 抽样对象类型，全部；支路；发电机 nPRSampleObject
				.addParam(config.getPRSampleObject())
				// 抽样类型 nPRSampleMethod
				.addParam(config.getPRSampleMethod()).
				// 抽样最大发电机故障重数 nMaxGenFault
				addParam(config.getMaxGenFault())
				// 抽样最大支路故障重数 nMaxBranFault
				.addParam(config.getMaxBranFault())
				// MCS最大抽样仿真时长 nMCSSimulateTime
				.addParam(config.getMCSSimulateTime()).
				// MCS[蒙特卡罗]设备故障概率门槛值 fMCSMinStateProb
				addParam(config.getMCSMinStateProb()).
				// FST[快速排序]累积概率 fFSTMaxCumuProb
				addParam(config.getFSTMaxCumuProb())
				// FST[快速排序]设备故障概率门槛值 fFSTMinStateProb
				//.addParam(config.getFSTMinStateProb())
				.addParam(0.00000)
				// FST[快速排序]最大状态数 nFSTMaxStateNum
				.addParam(config.getFSTMaxStateNum())
				// STS[状态抽样]最大状态数 nSTSMaxStateNum
				.addParam(config.getSTSMaxStateNum())
				// ANA[解析法]设备故障概率门槛值 fANAMinStateProb
				.addParam(0.000000).logger((String log)->logger.info(log)).exec();
	}
	


	public void reliability(String jobId) {		
		CalcJob job = calcJobBuffer.findById(jobId);
		
		if (job == null) {
			throw new AplException("Cann't find job id : "+jobId );
		}
		//String modelId = job.getModelId();
		logger.info("Begin to reliability analysis : "+jobId);
		
		BufferServer bufferServer = new BufferServerImpl(defaultBuffer, job);
		bufferServer.clear();
		
		PRAdequacySetting setting = CalcJob.getConfig(job);
		if (setting == null)
			throw new AplException("Can't resolve job setting : " + jobId);
		
		sample(setting);
		List<FState> fstates = memoryServer.findAllFStates();
		List<FStateFDev> devs = memoryServer.findAllFStateFDevs();
		if (fstates.isEmpty() || devs.isEmpty()) {
			throw new AplException("fstate is empty : "+job.getId());
		}
		
		bufferServer.updateTasks(fstates, devs);		 
		

			ProxyServer server = new ReliabilityProxyServer(properties, jobId, bufferServer.getTaskList(), bufferServer, setting);
		
			server.exec();

	}
	
	private void callReliabilityIndex(PRAdequacySetting config) {
		AppUtil.execBuilder(appDir+"/"+AppUtil.GC_RELIABILITY_INDEX).addParam(appDir)
		// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam(config.getDc2AcFactor()).logger((String log)->logger.info(log)).exec();
	}	
	
	public void reliabilityIndex(String jobId) {

		 System.out.println("Update result to memdb...");
		 memoryServer.clear();
		 CalcJob job = calcJobBuffer.findById(jobId);
			
		if (job == null) {
			throw new AplException("Cann't find job id : "+jobId );
		}
				
		BufferServer bufferServer = new BufferServerImpl(defaultBuffer, job);
		 
		List<FStateOvlDev> ovlDevs = bufferServer.getAllOvlDevs(); 
		List<FStateOvlAd> ovlAds = bufferServer.getOvlAds();
		List<FState> fstates = bufferServer.getFStates();
		List<FStateMIsland> islands = bufferServer.getIslands();
		
			 
		Collections.sort(ovlAds, (a, b)->a.getFStateId().compareTo(b.getFStateId()));			 
		Collections.sort(ovlDevs, (a, b)->a.getFStateId().compareTo(b.getFStateId()));		 
		Collections.sort(fstates, (a, b)->a.getFStateID().compareTo(b.getFStateID()));	 
		Collections.sort(islands, (a, b)->a.getFStateId().compareTo(b.getFStateId()));

			 		 		 
		 memoryServer.saveOvlDevs(ovlDevs);
		 memoryServer.saveOvlAds(ovlAds);
		 memoryServer.saveFStates(fstates);
		 memoryServer.saveIslands(islands);
		 
		PRAdequacySetting config = CalcJob.getConfig(job);
		callReliabilityIndex(config);
	}
	
	
	private void initModel(CalcJob job) {

		String modelId = job.getModelId();
		if (modelId == null) {
			throw new AplException("Job's model id is null : "+modelId);
		}
		
		if (memHolder.getCurrentModelSource() != null && memHolder.getCurrentModelSource().compareTo(modelId) == 0) {
			logger.info("Job({})'s model is same with current model : {}", job.getId(), modelId);
			return;
		}
		
		memHolder.reload(modelId, DatabaseType.BPA);
		memHolder.reload(modelId, DatabaseType.PR);
		
		logger.info("Job({})'model is loaded: {}.", job.getId(), modelId);
		
	}
	
	@AplFunction(value="initBuffer", desc="初始化缓存", in = MessageCodeEnum.created_job, out = MessageCodeEnum.created_reliability_task)
	public void initBuffer(String jobId, AplContext context) {
		CalcJob job = calcJobBuffer.findById(jobId);
		if (job == null) {
			throw new AplException("Job is null : "+jobId);
		}
		
		//初始化模型
		initModel(job);
		
		
		
		//初始化任务
		logger.info("Begin to reliability analysis : "+jobId);
		
		BufferServer bufferServer = new BufferServerImpl(defaultBuffer, job);
		bufferServer.clear();
		
		PRAdequacySetting setting = CalcJob.getConfig(job);
		if (setting == null)
			throw new AplException("Can't resolve job setting : " + jobId);
		
		sample(setting);
		
		List<FState> fstates = memoryServer.findAllFStates();
		List<FStateFDev> devs = memoryServer.findAllFStateFDevs();
		if (fstates.isEmpty() || devs.isEmpty()) {
			throw new AplException("fstate is empty : "+job.getId());
		}
		try {
		bufferServer.updateTasks(fstates, devs);	
		} catch (Throwable e) {
			e.printStackTrace();
		}
		
		context.setAttribute("buffer", bufferServer);
	}
	
	@AplFunction(in=MessageCodeEnum.created_reliability_task)
	public void reliability(String jobId, AplContext context) {
		CalcJob job = calcJobBuffer.findById(jobId);
		if (job == null) {
			throw new AplException("Job is null : "+jobId);
		}
		
		//初始化模型
		initModel(job);
		
		BufferServer bufferServer = (BufferServer) context.getAttribute("buffer");
		if (bufferServer == null) {
			bufferServer = new BufferServerImpl(defaultBuffer, job);
		}
		
		PRAdequacySetting setting = CalcJob.getConfig(job);
		if (setting == null)
			throw new AplException("Can't resolve job setting : " + jobId);
	
		String appName  = "GCStateEstimateServer";
		Process p = null;
		if (!AppUtil.isRunning(appName))
		  p = AppUtil.execute(properties.getAppDir()+"/"+appName);
		
		try {
			
			//充裕度评估
			ProxyServer server = new ReliabilityProxyServer(properties, jobId, bufferServer.getTaskList(), bufferServer, setting);		
			server.exec();
			
		} finally {
			if (p != null)
			   p.destroy();
		}


		reliabilityIndex(jobId);
		
		
		
	}
	
}
