package com.znd.apl;


import java.io.File;
import java.io.IOException;
import java.util.Collections;
import java.util.List;

import javax.annotation.PostConstruct;

import org.redisson.api.RCountDownLatch;
import org.redisson.api.RedissonClient;
import org.redisson.config.RedissonNodeConfig;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.annotation.AplController;
import com.znd.annotation.AplFunction;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.bus.common.model.CalcJobStateEnum;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.log.BufferLogger;
import com.znd.bus.log.BufferLoggerFactory;
import com.znd.bus.server.AdapterService;
import com.znd.bus.server.BusService;
import com.znd.bus.server.NounEnum;
import com.znd.bus.server.Topic;
import com.znd.bus.server.VerbEnum;
import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.HeaderType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;
import com.znd.ei.Utils;
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
import com.znd.reliability.server.PrBufferServer;
import com.znd.reliability.server.PrMemoryServer;
import com.znd.reliability.server.ReliabilityProxyServer;
import com.znd.reliability.server.impl.PrBufferServerImpl;
import com.znd.reliability.server.impl.ReliabilityProxyServerImpl;
import com.znd.reliability.server.impl.SimpleServer;
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
	private PrMemoryServer memoryServer;
	
	
	@Autowired
	private BusService busService;
	
	
	private AdapterService adapter;
	
	
	@Autowired
	private ShareMemHolder memHolder;
	
	
	@Autowired
	private BufferConfig bufferConfig; 
	
//	@Autowired
//	private BufferLogger bufferLogger;
	
	private BufferLogger bufferLogger = BufferLoggerFactory.getLogger(ReliabilityApl.class);

	
	public ReliabilityApl(ReliabilityProperties properties) {
		
		this.properties = properties;
		appDir = Utils.getSysHome(properties.getAppDir());		
		if (appDir == null) {
			logger.error("Fail to get sys home : "+appDir);
		}
		//System.exit(0);
	} 

	
	@PostConstruct
	public void init() {
		adapter = busService.registAdapter(new AdapterService() {
			
			@Override
			public ResponseMessageType response(ResponseMessageType message) {

				return null;
			}
			
			@Override
			public ResponseMessageType request(RequestMessageType message) {
				logger.debug("ReliabilityApl收到请求: "+Utils.toJSon(message));	
				
				
				HeaderType header = message.getHeader();
				if (header.isTopic(VerbEnum.execute, NounEnum.job)) {
					String jobId = message.getPayload().getSimpleContent();
					logger.debug("ReliabilityApl receive execute job : jobId = {} ", jobId);	
				    
					//执行计算
				    work(jobId);
				    
				    //回复执行
				    sendResponse(VerbEnum.reply, NounEnum.job, jobId);
				}
				return null;
			}
			
			@Override
			public ResponseMessageType publish(EventMessageType message) {
				logger.debug("ReliabilityApl收到事件 : "+Utils.toJSon(message));	
				
				
				HeaderType header = message.getHeader();
				if (header.isTopic(VerbEnum.created, NounEnum.ReliabilityBuffer)) { //收到发布可靠性计算缓存已创建事件，初始化本地缓存
					String jobId = message.getPayload().getSimpleContent();				
					logger.debug("ReliabilityApl receive created ReliabilityBuffer : jobId = {} ", jobId);	
				    
					initLocalMemory(jobId);
				} else if (header.isTopic(VerbEnum.created, NounEnum.ReliabilityTasks)) {//抽样任务队列已经创建事件
					String jobId = message.getPayload().getSimpleContent();		
					logger.debug("ReliabilityApl  created ReliabilityTasks : jobId = {} ", jobId);
					executeTasks(jobId);
				}
				
				
				return null;
			}
		}, "ReliabilityAplControler", Topic.out(VerbEnum.execute, NounEnum.job));
		
	}
	
	/*
	 * 主要的计算流程
	 * @param jobId
	 */
	private void work(String jobId) {
		CalcJob job = calcJobBuffer.findById(jobId);
		
		if (job == null) {
			throw new AplException("Cann't find job id : jobId = "+jobId );
		}
		
		//初始化可靠性计算缓存 create ReliabilityBuffer
		PrBufferServer bufferServer = initReliabilityBuffer(job);
		
		//发布可靠性计算缓存已创建事件 (publish created ReliabilityBuffer)
		adapter.sendPublish(VerbEnum.created, NounEnum.ReliabilityBuffer, jobId);
		
				
		//抽样，并形成抽样任务队列 create CalcTasks
		sampleAndCreateTasks(bufferServer, job);
		
		//发布抽样任务队列已经创建事件(publish created ReliabilityTasks)
		adapter.sendPublish(VerbEnum.created, NounEnum.ReliabilityTasks, jobId);
		
		//等待任务队列执行完
		JobUpdater updater = new JobUpdater(job);		
		try {
			updater.await();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		//后评估
		reliabilityIndex(job, bufferServer);
		
			
	}
	
	/*
	 * 后评估
	 */
	private void reliabilityIndex(CalcJob job, PrBufferServer bufferServer) {
		
		if (bufferServer == null)
		  bufferServer = new PrBufferServerImpl(defaultBuffer, job);
		 
		//下载可靠性计算结果
		List<FStateOvlDev> ovlDevs = bufferServer.getAllOvlDevs(); 
		List<FStateOvlAd> ovlAds = bufferServer.getOvlAds();
		List<FState> fstates = bufferServer.getFStates();
		List<FStateMIsland> islands = bufferServer.getIslands();
		
			 
		Collections.sort(ovlAds, (a, b)->a.getFStateId().compareTo(b.getFStateId()));			 
		Collections.sort(ovlDevs, (a, b)->a.getFStateId().compareTo(b.getFStateId()));		 
		Collections.sort(fstates, (a, b)->a.getFStateID().compareTo(b.getFStateID()));	 
		Collections.sort(islands, (a, b)->a.getFStateId().compareTo(b.getFStateId()));

		//可靠性计算结果存入本地 	
		 memoryServer.clear();
		 memoryServer.saveOvlDevs(ovlDevs);
		 memoryServer.saveOvlAds(ovlAds);
		 memoryServer.saveFStates(fstates);
		 memoryServer.saveIslands(islands);
		 
		PRAdequacySetting config = CalcJob.getConfig(job);
		callReliabilityIndex(config);
		
		//上传可靠性指标到数据库
		List<com.znd.ei.memdb.reliabilty.domain.System> systems = memoryServer.findAllSystems();
		bufferServer.saveSystems(systems);
	}
	
	
	private RCountDownLatch getJobLatch(CalcJob job) {
		RedissonClient redisson = bufferConfig.getRedissonClient();
		RCountDownLatch latch = redisson.getCountDownLatch(job.getId());
		return latch;
	}
	
	private void sampleAndCreateTasks(PrBufferServer bufferServer, CalcJob job) {

		//检查本地内存是否初始化成功
		initLocalMemory(job);
			
		PRAdequacySetting setting = CalcJob.getConfig(job);
		if (setting == null)
			throw new AplException("Can't resolve job setting : " + job);
		
		//抽样
		sample(setting);

		  		
		List<FState> fstates = memoryServer.findAllFStates();
		List<FStateFDev> devs = memoryServer.findAllFStateFDevs();
		if (fstates.isEmpty() || devs.isEmpty()) {
			throw new AplException("fstate is empty : "+job.getId());
		}
		
		//设置闭锁
		JobUpdater updater = new JobUpdater(job);
		updater.setJobSize(fstates.size());

		
		//上传抽样状态和故障设备
		bufferServer.updateTasks(fstates, devs);	
	}
	
	/*
	 * 初始化初始化网络buffer
	 */	
	private PrBufferServer initReliabilityBuffer(CalcJob job) {
		PrBufferServer bufferServer = new PrBufferServerImpl(defaultBuffer, job);
		bufferServer.clear();
		return bufferServer;
	}
	
	/*
	 * 初始化本地缓存
	 * @param jobId
	 */
	private synchronized  void  initLocalMemory(CalcJob job) {
		String dbId = job.getId();
		if (dbId == null) {
			throw new AplException("Job's model id is null : "+dbId);
		}
		
		if (memHolder.getCurrentModelSource() != null && memHolder.getCurrentModelSource().compareTo(dbId) == 0) {
			logger.info("Job({})'s model is the same with current model : {}", job.getId(), dbId);
			return;
		}
		
		memHolder.reload(dbId, DatabaseType.BPA);
		memHolder.reload(dbId, DatabaseType.PR);
		
		logger.info("Job({})'s model is loaded: {}.", job.getId(), dbId);
	}
	
	
	/*
	 * 初始化本地缓存
	 * @param jobId
	 */
	private  void  initLocalMemory(String jobId) {
		CalcJob job = calcJobBuffer.findById(jobId);
		initLocalMemory(job);
	}
	
	
	public class JobUpdater
	{
		private CalcJob job;
		private RCountDownLatch latch;
		public JobUpdater(CalcJob job) {
			this.job = job;
			this.latch = getJobLatch(job);
		}
		public void setJobSize(int size) {
			job.setState(CalcJobStateEnum.running);
			job.setMaxStep(size);
			latch.trySetCount(size);
			calcJobBuffer.update(job);
		}
		
		public void decrease() {
			latch.countDown();
			job.setStep((int) latch.getCount());
			calcJobBuffer.update(job);
		}
		
		public void await() throws InterruptedException {
			this.latch.await();
			job.setState(CalcJobStateEnum.stop);
		}
		
		
		
	}
	
	/*
	 * 执行任务
	 * @param jobId
	 */
	private void executeTasks(String jobId) {
		CalcJob job = calcJobBuffer.findById(jobId);
		
		if (job == null) {
			throw new AplException("Cann't find job id : jobId = "+jobId );
		}
		
		String appName  = "state-estimate";
		
		AppUtil.kill(appName);
		if (!AppUtil.isRunning(appName)) {
			new Thread(()->{
//				RedissonNodeConfig localConfig = bufferConfig.getLocalConfig();				
				AppUtil.executeWithoutLogger(appDir+"/bin/"+appName, "127.0.0.1","10001");
			}).start();
		}
		  		
		
		
		
		PrBufferServer bufferServer = new PrBufferServerImpl(defaultBuffer, job);	
		PRAdequacySetting setting = CalcJob.getConfig(job);
		if (setting == null)
			throw new AplException("Can't resolve job setting : " + jobId);
		
		try {
			System.out.println("Start SimpleServer");
		    ReliabilityProxyServer server = new SimpleServer(properties,
		    		bufferServer.getTaskList(),
		    		bufferServer, 
		    		setting, 
		    		bufferConfig.getLocalClient(), 
		    		new JobUpdater(job));		
			server.exec();
		} finally {
			AppUtil.kill(appName);
		}
		bufferServer.flushResult();
	}
	

	public void callBpaLoader(File[] files) {
		
		System.out.println("Clear bpa memdb.");
		bPAOps.clearDb();
		
		try {
			AppExecuteBuilder eb = AppUtil.execBuilder(appDir+"/bin_x64/"+AppUtil.GC_BPA_LOADER).addParam(appDir);
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
			AppExecuteBuilder eb = AppUtil.execBuilder(appDir+"/bin_x64/"+AppUtil.GC_BPA_2_PR).addParam(appDir);
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
		AppUtil.execBuilder(appDir+"/bin_x64/"+AppUtil.GC_STATE_SAMPLE).addParam(appDir)
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
	
	public void reliabilityLocal(String jobId) {		
		CalcJob job = calcJobBuffer.findById(jobId);
		
		if (job == null) {
			throw new AplException("Cann't find job id : jobId = "+jobId );
		}
		//String modelId = job.getModelId();
		logger.info("Begin to reliability analysis : jobId = "+jobId);
		
		PrBufferServer bufferServer = new PrBufferServerImpl(defaultBuffer, job);
		bufferServer.clear();
		
		PRAdequacySetting setting = CalcJob.getConfig(job);
		if (setting == null)
			throw new AplException("Can't resolve job setting : " + jobId);
		
		sample(setting);
 		
		String appName  = "state-estimate";
			
		AppUtil.kill(appName);
		if (!AppUtil.isRunning(appName)) {
			new Thread(()->{
				RedissonNodeConfig localConfig = bufferConfig.getLocalConfig();				
				AppUtil.executeWithoutLogger(appDir+"/bin/"+appName, "127.0.0.1","10001");
			}).start();
		}
		  		
		List<FState> fstates = memoryServer.findAllFStates();
		List<FStateFDev> devs = memoryServer.findAllFStateFDevs();
		if (fstates.isEmpty() || devs.isEmpty()) {
			throw new AplException("fstate is empty : "+job.getId());
		}
		
		bufferServer.updateTasks(fstates, devs);		
		
		try {
			System.out.println("Start SimpleServer");
		    ReliabilityProxyServer server = new SimpleServer(properties, bufferServer.getTaskList(), bufferServer, setting, bufferConfig.getLocalClient(), null);		
			server.exec();
		} finally {
			AppUtil.kill(appName);
		}
		bufferServer.flushResult();
	}

	public void reliability(String jobId) {		
		CalcJob job = calcJobBuffer.findById(jobId);
		
		if (job == null) {
			throw new AplException("Cann't find job id : "+jobId );
		}
		//String modelId = job.getModelId();
		logger.info("Begin to reliability analysis : "+jobId);
		
		PrBufferServer bufferServer = new PrBufferServerImpl(defaultBuffer, job);
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
		
	    ReliabilityProxyServer server = new ReliabilityProxyServerImpl(properties, jobId, bufferServer.getTaskList(), bufferServer, setting);
		
		server.exec();
		bufferServer.flushResult();
	}
	
	private void callReliabilityIndex(PRAdequacySetting config) {
		AppUtil.execBuilder(appDir+"/bin_x64/"+AppUtil.GC_RELIABILITY_INDEX).addParam(appDir)
		// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam(config.getDc2AcFactor()).logger((String log)->logger.info(log)).exec();
	}	
	
	

	
	public void reliabilityIndex(String jobId, PrBufferServer bufferServer) {

		 System.out.println("Update result to memdb...");
		 memoryServer.clear();
		 CalcJob job = calcJobBuffer.findById(jobId);
			
		if (job == null) {
			throw new AplException("Cann't find job id : "+jobId );
		}
				
		reliabilityIndex(job, bufferServer);
	}
	
	
	private void initModel(CalcJob job) {

		String modelId = job.getModelId();
		if (modelId == null) {
			throw new AplException("Job's model id is null : "+modelId);
		}
		
		if (memHolder.getCurrentModelSource() != null && memHolder.getCurrentModelSource().compareTo(modelId) == 0) {
			logger.info("Job({})'s model is the same with current model : {}", job.getId(), modelId);
			return;
		}
		
		memHolder.reload(modelId, DatabaseType.BPA);
		memHolder.reload(modelId, DatabaseType.PR);
		
		logger.info("Job({})'model is loaded: {}.", job.getId(), modelId);
		
	}
	
	@AplFunction(value="initBuffer", desc="初始化缓存", in = MessageCodeEnum.start_job, out = MessageCodeEnum.created_reliability_task)
	public void initBuffer(String jobId, AplContext context) {
		CalcJob job = calcJobBuffer.findById(jobId);
		if (job == null) {
			throw new AplException("Job is null : "+jobId);
		}
		
		//初始化模型
		initModel(job);
		
				
		//初始化任务
		logger.info("Begin to reliability analysis : "+jobId);
		bufferLogger.info("开始可靠性分析, jobId = {}", jobId);
		
		PrBufferServer bufferServer = new PrBufferServerImpl(defaultBuffer, job);
		bufferServer.clear();
		
		PRAdequacySetting setting = CalcJob.getConfig(job);
		if (setting == null) {
			bufferLogger.info("解析任务配置失败:{}", jobId);
			throw new AplException("Can't resolve job setting : " + jobId);
		}
		
		bufferLogger.info("开始生成抽样状态。");
		sample(setting);

		List<FState> fstates = memoryServer.findAllFStates();
		List<FStateFDev> devs = memoryServer.findAllFStateFDevs();
		bufferLogger.info("抽样完成，生成状态数量:{}, 故障设备数:{}", fstates.size(), devs.size());
		
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
		
		PrBufferServer bufferServer = (PrBufferServer) context.getAttribute("buffer");
		if (bufferServer == null) {
			bufferServer = new PrBufferServerImpl(defaultBuffer, job);
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
			ReliabilityProxyServer server = new ReliabilityProxyServerImpl(properties, jobId, bufferServer.getTaskList(), bufferServer, setting);		
			server.exec();
			bufferServer.flushResult();
		} finally {
			if (p != null)
			   p.destroy();
		}


		reliabilityIndex(jobId, bufferServer);
		
		
		
	}
	
}
