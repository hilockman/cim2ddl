package com.znd.ei.ads.apl.reliability;

import static com.znd.ei.ads.apl.reliability.AppUtil.GC_BPA_2_PR;
import static com.znd.ei.ads.apl.reliability.AppUtil.GC_BPA_LOADER;
import static com.znd.ei.ads.apl.reliability.AppUtil.GC_RELIABILITY_INDEX;
import static com.znd.ei.ads.apl.reliability.AppUtil.GC_STATE_SAMPLE;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.concurrent.CountDownLatch;

import org.redisson.api.RedissonClient;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ads.model.PRAdequacySetting;
import com.znd.ei.Utils;
import com.znd.ei.ads.acp.AbstractConnectionFactory;
import com.znd.ei.ads.acp.ListDataOperations;
import com.znd.ei.ads.adf.ContentCodeDefines;
import com.znd.ei.ads.adf.AplManager;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.apl.annotations.AplController;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.reliability.bean.RequestEstimate;
import com.znd.ei.ads.apl.reliability.bean.ResponseEstimate;
import com.znd.ei.ads.apl.reliability.server.StateEstimateServer;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.reliabilty.dao.FStateDao;
import com.znd.ei.memdb.reliabilty.dao.FStateFDevDao;
import com.znd.ei.memdb.reliabilty.dao.FStateMIslandDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlAdDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlDevDao;
import com.znd.ei.memdb.reliabilty.dao.SystemDao;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;

@AplController
public class ReliabilityApl {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(ReliabilityApl.class);


	public String execRootPath;


	private StateEstimateProperties properties;

	

	public ReliabilityApl(StateEstimateProperties properties) {
		
		this.properties = properties;
		execRootPath = properties.getAppDir();
		if (!new File(execRootPath).exists()) {
			execRootPath = System.getenv("ZND_HOME")+"\\bin_x64";
			if (!new File(execRootPath).exists()) {
				throw new RuntimeException("no find "+properties.getAppDir()+", or "+"$ZND_HOME");
			}
		}
//		rootPath = Paths.get(properties.getAppDir()).toAbsolutePath().toString();
//		dataRootPath = rootPath + "/data";
//		execRootPath = rootPath + "/bin_x64";
		
		execRootPath = Paths.get(execRootPath).toAbsolutePath().toString();
	} 

//	public String dataRootPath;
//	public String execRootPath;

	@Autowired
	private FStateDao fStateDao;

	@Autowired
	private FStateFDevDao fStateFDevDao;

	@Autowired
	private FStateMIslandDao mIslandDao;

	@Autowired
	private FStateOvlAdDao ovlAdDao;

	@Autowired
	private FStateOvlDevDao ovlDevDao;

	@Autowired
	private SystemDao systemDao;

	@Autowired
	private AbstractConnectionFactory connectionFactory;

	@Autowired
	private DbEntryOperations pROps;

	@Autowired
	private DbEntryOperations bPAOps;
	
	

	@Autowired
	private AplManager aplManager;
	

//
//	public void callStateEstimate(FState state,
//			StateEstimateConfig config) {
//		AppUtil.execBuilder(GC_STATE_ESTIMATE).addParam(execRootPath)
//		// 直流潮流2 交流潮流系数 fDc2AcFactor
//				.addParam(config.getDc2AcFactor())
//				// 线路消限 bLineELimit
//				.addParam(config.getLineELimit())
//				// 主变消限 bTranELimit
//				.addParam(config.getTranELimit())
//				// 调整发电机消限 bGenPELimit
//				.addParam(config.getGenPELimit())
//				// 调整UPFC消限 bUPFCELimit
//				.addParam(config.getuPFCELimit())
//				// 厂用电参与消限 bAuxLoadAdjust
//				.addParam(config.getAuxLoadAdjust())
//				// 等值发电机参与消限 bEQGenAdjust
//				.addParam(config.geteQGenAdjust())
//				// 等值负荷参与消限 bEQLoadAdjust
//				.addParam(config.geteQLoadAdjust())
//				// 孤岛的最小容载比 fMinIslandGLRatio
//				.addParam(config.getMinIslandGLRatio())
//				// UPFC采用变容法 bUPFCAdjustRC
//				.addParam(config.getuPFCAdjustRC()).logger(new AppLogger() {
//
//					@Override
//					public void print(String log) {
//						LOGGER.info(log);
//					}
//				}).exec();
//
//	}
//
//	public void callStateEstimate() {
//		callStateEstimate(null, new StateEstimateConfig());
//	}

	public void callReliabilityIndex(PRAdequacySetting config) {
		AppUtil.execBuilder(execRootPath+"/"+GC_RELIABILITY_INDEX).addParam(execRootPath)
		// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam(config.getDc2AcFactor()).logger(new AppLogger() {

					@Override
					public void print(String log) {
						LOGGER.info(log);
					}
				}).exec();
	}


	@Autowired
	private RedissonClient redissonClient;
	
//	@AplFunction(desc = "模型加载:加载BPA模型,BPA网络模型转可靠性网络模型")
//	public void loadModel(@In(create_AllModel) StringData createConfig,
//			@Out(created_BPAModel) MemDBData bPAModel,
//			@Out(created_PRModel) MemDBData pRModel,
//			@Out(get_Reliability) StringData calcTask) throws ACPException,
//			UnsupportedOperation {
//
//		LOGGER.info("----------------start create_BPAModel------------------------");
//		LOGGER.info("config:" + createConfig.getContent());
//		callBpaLoader();
//
//		bPAModel.setEntryName(MDBDefine.g_strBpaDBEntry);
//		bPAModel.setArea(modelArea);
//
//		callBpa2Pr();
//		pRModel.setEntryName(MDBDefine.g_strPRDBEntry);
//		pRModel.setArea(modelArea);
//
//		// AdsServer server = connectionFactory.getServer();
//		// if (server != null)
//		// server.publish(created_StateSampleTask, state_sample);
//
//		calcTask.setKey(pRModel.getArea() + ":task:" + powersystem_reliability);
//
//		LOGGER.info("----------------end create_BPAModel------------------------");
//
//	}
	
	private void callStateSample(PRAdequacySetting config) {
		System.out.println("call StateSample , config = "+config);
		AppUtil.execBuilder(execRootPath+"/"+GC_STATE_SAMPLE).addParam(execRootPath)
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
				.addParam(0.000000).logger((String log)->LOGGER.info(log)).exec();
	}
	

	
	private void callBpaLoader(File[] files) {
		System.out.println("Clear bpa memdb.");
		bPAOps.clearDb();
		
		try {
			AppExecuteBuilder eb = AppUtil.execBuilder(execRootPath+"/"+GC_BPA_LOADER).addParam(execRootPath);
			for (File file: files) {
				eb.addParam(file.getCanonicalPath());
			}
			eb.logger((String log)->LOGGER.info(log)).exec();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private void callBpa2Pr(File [] files) {
		System.out.println("Clear pr memdb.");
		pROps.clearDb();
		try {
			AppExecuteBuilder eb = AppUtil.execBuilder(execRootPath+"/"+GC_BPA_2_PR).addParam(execRootPath);
			for (File file: files) {
				eb.addParam(file.getCanonicalPath());
			}
			eb.logger((String log)->LOGGER.info(log)).exec();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	@Autowired
	private StateEstimateServer stateEstimateServer; 
	

	@AplFunction( desc = "clear database")
	public void clearDatabase(@In("clear_Database")String data) {
		bPAOps.clearDb();
		pROps.clearDb();
	}
	

	

	private CountDownLatch memDbCreatedLatch;

	@AplFunction( desc = " create BPA and PR memory database")
	public void createMemDb(@In(ContentCodeDefines.created_BPAFiles) String modelName) {
		memDbCreatedLatch = new CountDownLatch(1);
		ReliabilityNetBuffer buffer = new ReliabilityNetBuffer(connectionFactory, modelName);
		
		File flowFile = buffer.saveFile(properties.getCachedDir(), ReliabilityNetBuffer.FLOW_FILE);
		File stableFile = buffer.saveFile(properties.getCachedDir(), ReliabilityNetBuffer.STATLE_FILE);
		File paramFile = buffer.saveFile(properties.getCachedDir(), ReliabilityNetBuffer.PARAM_FILE);

		// bpa model loader	 
		callBpaLoader(new File[]{flowFile, stableFile});
		callBpa2Pr(new File[]{flowFile, stableFile, paramFile});
		
		memDbCreatedLatch.countDown();
		
	}
	
	@AplFunction( desc = "Reliability")
	public void reliability(@In(ContentCodeDefines.created_ReliabilityTask) String modelName) {
		long start = System.currentTimeMillis();
		//String modelName = data;
		LOGGER.info("recieved model : ", modelName);
		
		aplManager.publishAndWait(ContentCodeDefines.created_BPAFiles, modelName);

		ReliabilityNetBuffer buffer = new ReliabilityNetBuffer(connectionFactory, modelName);
		PRAdequacySetting config = buffer.get(ReliabilityNetBuffer.PR_ADEQUACY_SETTING, PRAdequacySetting.class);	
		
		//call state sample
		 callStateSample(config);
		 	
		//upload fstates
		List<FState> fstates = fStateDao.findAll();
		System.out.println("Upload fstates..., size = "+fstates.size());
		buffer.removeKeys(ReliabilityNetBuffer.FSTATE_LIST);
		buffer.pushAll(ReliabilityNetBuffer.FSTATE_LIST, fstates);
			
		buffer.removeKeys(ReliabilityNetBuffer.FDEV_LIST);
		List<FStateFDev> devs = fStateFDevDao.findAll();
		System.out.println("Upload fdevs..., size = "+devs.size());
		buffer.pushAll(ReliabilityNetBuffer.FDEV_LIST, devs);
		
		Collections.sort(fstates, (a, b)->a.getFStateID().compareTo(b.getFStateID()));
		Collections.sort(devs, (a, b)->a.getFStateId().compareTo(b.getFStateId()));

		int i = 0; 
		int j = 0;
		List<RequestEstimate> tasks = new ArrayList<RequestEstimate>();
		for (; i < fstates.size() ; i++) {
			FState fstate = fstates.get(i);
			//设置评估标志为1(否则分析结果有误）
			fstate.setEstimated(1);
			RequestEstimate task = new RequestEstimate();
			task.setValue(String.valueOf(fstate.getFStateID()));
			task.getContent().getFState().add(fstate);
			while (j < devs.size()) {
				FStateFDev dev = devs.get(j);
				int cmp = dev.getFStateId().compareTo(fstate.getFStateID());
				if (cmp < 0 ) {
					j++;
				} else if (cmp == 0) {
					task.getContent().getFStateFDev().add(dev);
					j++;
				} else {
					break;
				}
			}
			
			tasks.add(task);
		}
		
		Collections.reverse(tasks);
		
		System.out.println("Upload tasks..., size = "+fstates.size());
		buffer.removeKeys(ReliabilityNetBuffer.ESTIMATE_TASK_LIST);
		buffer.pushAll(ReliabilityNetBuffer.ESTIMATE_TASK_LIST, tasks);
				
		//发布后评估任务
		LOGGER.info("publish estimate tasks.");
		aplManager.publishAndWait(ContentCodeDefines.created_EstimateTask, modelName);
		

		//发布后评估计算结果
		LOGGER.info("publish estimate result."); 
		 aplManager.publishAndWait(ContentCodeDefines.created_EstemateResult, modelName);
		 
		 System.out.println("Finished reliabity, elapse time is :" +(System.currentTimeMillis() - start) / 1000+" s.");
		 
	}
	
	/**
	 * 收到创建后评估任务后，启动后评估
	 * @param modelName
	 */
	@AplFunction( desc = "StateEstimate")
	public void stateEstimate(@In(ContentCodeDefines.created_EstimateTask)String modelName) {
		if (memDbCreatedLatch != null) {
			try {
				memDbCreatedLatch.await();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		ReliabilityNetBuffer buffer = new ReliabilityNetBuffer(connectionFactory, modelName);
		PRAdequacySetting config = buffer.get(ReliabilityNetBuffer.PR_ADEQUACY_SETTING, PRAdequacySetting.class);	
		log(modelName, "Start state estimate...");
		buffer.removeKeys(ReliabilityNetBuffer.ESTIMATE_RESULT_MAP);
		
		//启动本地计算
		stateEstimateServer.exec(buffer, config);
	}
	
	@AplFunction( desc = "ReliabilityIndex")
	public void reliabilityIndex(@In(ContentCodeDefines.created_EstemateResult)String modelName) {
		ReliabilityNetBuffer buffer = new ReliabilityNetBuffer(connectionFactory, modelName);
		
		 System.out.println("Update result to memdb...");
		 ovlAdDao.deleteAll();
		 ovlDevDao.deleteAll();
		 fStateDao.deleteAll();
		 mIslandDao.deleteAll();
		 
		 
		 MapData<Integer, ResponseEstimate> resultMap = buffer.getMap(ReliabilityNetBuffer.ESTIMATE_RESULT_MAP);
		ListData<FState> fstates = buffer.getList(ReliabilityNetBuffer.FSTATE_LIST);
		List<FState> fstates0 = fstates.getContent();
		Collections.sort(fstates0, (a, b)->a.getFStateID().compareTo(b.getFStateID()));
		
		 Map<Integer, ResponseEstimate> m = resultMap.getAll();
		 Set<Entry<Integer, ResponseEstimate>> entrys = m.entrySet();
		List<FStateOvlDev> ovlDevs = new ArrayList<>();
		List<FStateOvlAd> ovlAds = new ArrayList<>();
		List<FState> fstates1 = new ArrayList<>();
		List<FStateMIsland> islands = new ArrayList<>();
		 for (Entry<Integer, ResponseEstimate> e : entrys) {
			 ResponseEstimate r = e.getValue();
			 if (r.getContent().getFStateOvlAd() != null)
			    ovlAds.addAll(r.getContent().getFStateOvlAd());
			 
			 if (r.getContent().getFStateOvlDev() != null)
				 ovlDevs.addAll(r.getContent().getFStateOvlDev());
			 
			 if (r.getContent().getFState() != null) {
				 fstates1.addAll(r.getContent().getFState());
			 }	
			 
			 if (r.getContent().getFStateMIsland() != null) {
				 islands.addAll(r.getContent().getFStateMIsland());
			 }
		 }
		 

		 Collections.sort(ovlAds, (a, b)->a.getFStateId().compareTo(b.getFStateId()));
		 ovlAdDao.saveOrUpdate(ovlAds);
		 
		 Collections.sort(ovlDevs, (a, b)->a.getFStateId().compareTo(b.getFStateId()));
		 ovlDevDao.saveOrUpdate(ovlDevs);
		 
		 Collections.sort(fstates1, (a, b)->a.getFStateID().compareTo(b.getFStateID()));	 
		 fStateDao.saveOrUpdate(fstates1);
		 
		 Collections.sort(islands, (a, b)->a.getFStateId().compareTo(b.getFStateId()));
		 mIslandDao.saveOrUpdate(islands);
		 
		PRAdequacySetting config = buffer.get(ReliabilityNetBuffer.PR_ADEQUACY_SETTING, PRAdequacySetting.class);	
		callReliabilityIndex(config);
	}
	


	public class LogInfo {
		private Date date;
		private String content;
		
		public LogInfo(Date date, String content) {
			this.setDate(date);
			this.content = content;
		}

		public String getContent() {
			return content;
		}
		public void setContent(String content) {
			this.content = content;
		}

		public Date getDate() {
			return date;
		}

		public void setDate(Date date) {
			this.date = date;
		}
	}
	
	private ListDataOperations logListOps;
	private void log(String key, String fmt, Object... args) {
		String log = String.format(fmt, args);
		LOGGER.info(log);
		if (logListOps == null)
			logListOps = connectionFactory.getListDataOperations();
		
		logListOps.push(key+":log", Utils.toJSon(new LogInfo(new Date(), log)));
	}
	
	public static File saveFile(String tempDir, String fileName, String fileContent) {
		
		Path path = Paths.get(tempDir);
		File pathFile = path.toFile();
		if (!pathFile.exists()) {
			LOGGER.info("mkdir {}. ", tempDir);
			pathFile.mkdirs();
		}
		
	
		Path filePath = Paths.get(tempDir, fileName);
		File file = filePath.toFile();
		LOGGER.info("save file : {} ", file.getAbsolutePath());
		FileWriter fw = null;
		try {
			fw = new FileWriter(file);
			fw.write(fileContent);
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		
		return file;

	}

//	@AplFunction(desc = "calc reliability")
//	public void calcReliability(
//			@In(get_Reliability) StringData calcTask,
//			@Out(created_StateSampleResult) MapData<Integer, StateSampleTask> stateSampleResult,
//			@Out(created_StateEsteimateResult) MapData<Integer, StateEstimateResult> stateEstimateResult,
//			@Out(created_ReliabilityIndexResult) ObjectRefData<ReliabilityIndexResult> reliabilityIndexResult) {
//		LOGGER.info("----------------start calc reliability------------------------");
//		// 状态抽样
//		callStateSample();
//
//		int count = 0;
//		Iterable<FState> fStates = fStateDao.findAll();
//		Map<Integer, StateSampleTask> resultMap = new HashMap<>();
//		for (FState state : fStates) {
//			StateSampleTask task = new StateSampleTask();
//			task.setState(state);
//			resultMap.put(count, task);
//			count++;
//			if (count == 1)
//				LOGGER.info(state.toString());
//
//		}
//		LOGGER.info("FState count=" + count);
//
//		Iterable<FStateFDev> fStateFDevs = fStateFDevDao.findAll();
//		count = 0;
//		for (FStateFDev dev : fStateFDevs) {
//			StateSampleTask rt = resultMap.get(dev.getFStateNo());
//			if (rt == null) {
//				continue;
//			}
//			count++;
//			rt.getDevs().add(dev);
//
//			if (count == 1)
//				LOGGER.info(dev.toString());
//
//		}
//		LOGGER.info("FStateFDev count=" + count);
//
//		RMap<Integer, StateSampleTask> map = redissonClient
//				.getMap("sampleStateMap");
//
//		Set<Entry<Integer, StateSampleTask>> s = resultMap.entrySet();
//		for (Entry<Integer, StateSampleTask> e : s) {
//			map.put(e.getKey(), e.getValue());
//		}
//
//		RMapReduce<Integer, StateSampleTask, Integer, StateEstimateResult> mapReduce = map
//				.<Integer, StateEstimateResult> mapReduce()
//				.mapper(new StateSampleMap()).reducer(new StateSampleReducer());
//
//		System.out.println("Start state estimate ...");
//		Map<Integer, StateEstimateResult> mapToResult = mapReduce.execute();
//
//		stateEstimateResult.putAll(mapToResult);
//
//		System.out.println("Start reliability index");
//		ReliabilityIndexResult indexResult = mapReduce
//				.execute(new StateSampleCollator());
//		reliabilityIndexResult.setContent(indexResult);
//
//		LOGGER.info("----------------end calc reliability------------------------");
//	}

//	@AplFunction(desc = "download state estimate result")
//	public void downloadEstimateResult(
//			@In(created_StateEsteimateResult) MapData<Integer, StateEstimateResult> stateEstimateResult) {
//
//	}

//	@AplFunction(desc = "download reliability index result")
//	public void downloadReliabilityIndexResult(
//			@In(created_ReliabilityIndexResult) ObjectRefData<ReliabilityIndexResult> reliabilityIndexResult) {
//
//	}

	// @AplFunction(desc = "BPA模型加载")
	// public void loadBPA(@In("create_BPAModel") StringData createConfig,
	// @Out("created_BPAModel") MemDBData bPAModel) throws ACPException,
	// UnsupportedOperation {
	//
	// LOGGER.info("----------------start create_BPAModel------------------------");
	// LOGGER.info("config:" + createConfig.getContent());
	// callBpaLoader();
	//
	// bPAModel.setEntryName(MDBDefine.g_strBpaDBEntry);
	// bPAModel.setArea(modelArea);
	//
	// // writeDataField(ContentCodeDefines.created_BPAModel, db,
	// // getConnectionFactory().getMemDBDataOperations());
	//
	// LOGGER.info("----------------end create_BPAModel------------------------");
	//
	// }
	//
	// @AplFunction(desc = "BPA网络模型转可靠性网络模型")
	// public void bpa2Pr(@In("created_BPAModel") MemDBData bPAModel,
	// @Out("created_PRModel") MemDBData pRModel,
	// @Out("created_StateSampleTask") ListData tasks)
	// throws ACPException, UnsupportedOperation {
	//
	// LOGGER.info("----------------start BPA2PR------------------------");
	// callBpa2Pr();
	//
	// pRModel.setEntryName(MDBDefine.g_strPRDBEntry);
	// pRModel.setArea(modelArea);
	//
	// // writeDataField(ContentCodeDefines.created_BPAModel, db,
	// // getConnectionFactory().getMemDBDataOperations());
	//
	// List<String> strs = new ArrayList<String>();
	// strs.add(state_sample);
	// tasks.setContent(strs);
	// tasks.setKey(pRModel.getArea() + ":task:" + state_sample);
	//
	// LOGGER.info("----------------end BPA2PR------------------------");
	//
	// }

	// @AplFunction(value = "StateSample", desc = "状态抽样")
	// public void stateSample(@In("created_BPAModel") MemDBData bPAModel,
	// @In("created_PRModel") MemDBData pRModel,
	// @In("created_StateSampleTask") ListData stateSampleTasks,
	// @Out(created_StateEstimateTask) ListData sateEstimateTasks,
	// @Out("created_StateSampleResult") MapData stateSampleResult,
	// @Out("created_StateEsteimateResultWatch") ListData watchTask) {
	// LOGGER.info("----------------start stateSample------------------------");
	// // 状态抽样
	// callStateSample();
	//
	// // 获取抽样任务
	// String str = null;
	// try {
	// str = stateSampleTasks.lpop();
	// } catch (ACPException e1) {
	// // TODO Auto-generated catch block
	// e1.printStackTrace();
	// }
	//
	// // 未获得抽样任务，则直接返回
	// if (str == null) {
	// LOGGER.info("----------------end stateSample------------------------");
	// return;
	// }
	//
	// // 清除总线上前一次计算结果
	// Set<String> keys = new HashSet<String>();
	// keys.addAll(connectionFactory.findKeys(pRModel.getArea() + ":result:*"));
	// keys.addAll(connectionFactory.findKeys(pRModel.getArea() + ":task:*"));
	// if (keys.size() > 0) {
	// LOGGER.info("清除缓存keys:" + String.join(",", keys));
	// connectionFactory.deleteKeys(keys.toArray(new String[0]));
	// }
	//
	// int count = 0;
	// Iterable<FState> fStates = fStateDao.findAll();
	// Map<Integer, StateSampleResult> resultMap = new HashMap<Integer,
	// StateSampleResult>();
	// List<String> taskList = new ArrayList<String>();
	// for (FState state : fStates) {
	// StateSampleResult task = new StateSampleResult();
	// taskList.add(String.valueOf(count));
	// resultMap.put(count, task);
	// count++;
	// if (count == 1)
	// LOGGER.info(state.toString());
	//
	// }
	// LOGGER.info("FState count=" + count);
	//
	// Iterable<FStateFDev> fStateFDevs = fStateFDevDao.findAll();
	// count = 0;
	// for (FStateFDev dev : fStateFDevs) {
	// StateSampleResult rt = resultMap.get(dev.getFState());
	// if (rt == null) {
	// continue;
	// }
	// count++;
	// rt.devs.add(dev);
	//
	// if (count == 1)
	// LOGGER.info(dev.toString());
	//
	// }
	// LOGGER.info("FStateFDev count=" + count);
	//
	// Iterator<Entry<Integer, StateSampleResult>> it = resultMap.entrySet()
	// .iterator();
	// Map<String, String> rtMap = new HashMap<String, String>();
	// while (it.hasNext()) {
	// Entry<Integer, StateSampleResult> e = it.next();
	// String content = Utils.toString(e.getValue());
	// rtMap.put(String.valueOf(e.getKey()), content);
	//
	// }
	//
	// if (!taskList.isEmpty()) {
	// String statEstimateTaskKey = pRModel.getArea() + ":task:"
	// + state_estimate;
	// if (!connectionFactory.hasKey(statEstimateTaskKey)) {
	// sateEstimateTasks.setContent(taskList);
	// sateEstimateTasks.setKey(statEstimateTaskKey);
	// }
	//
	// String statSampleResultKey = pRModel.getArea() + ":result:"
	// + state_sample;
	// if (!connectionFactory.hasKey(statSampleResultKey)) {
	// stateSampleResult.setContent(rtMap);
	// stateSampleResult.setKey(statSampleResultKey);
	// }
	//
	// String stateEstimateWatchKey = pRModel.getArea() + ":task:"
	// + state_estimate_watch;
	// if (!connectionFactory.hasKey(stateEstimateWatchKey)) {
	// List<String> counts = new ArrayList<String>();
	// ResultWatchTask t = new ResultWatchTask();
	// t.setCount(Long.valueOf(taskList.size()));
	// String statEstimateResultKey = pRModel.getArea() + ":result:"
	// + state_estimate;
	// t.setKey(statEstimateResultKey);
	// counts.add(Utils.toString(t));
	// watchTask.setKey(stateEstimateWatchKey);
	// watchTask.setContent(counts);
	// }
	//
	// }
	// LOGGER.info("StateEstimateTask count=" + taskList.size());
	// LOGGER.info("----------------end stateSample------------------------");
	// }

	// class ResultWatchTask {
	// private String key;
	// private Long count;
	//
	// public String getKey() {
	// return key;
	// }
	//
	// public void setKey(String key) {
	// this.key = key;
	// }
	//
	// public Long getCount() {
	// return count;
	// }
	//
	// public void setCount(Long count) {
	// this.count = count;
	// }
	//
	// }

	// @AplFunction(value = "WatchStateEstimate", desc = "监控状态后评估")
	// public void watchStateEstimate(
	// @In("created_StateEsteimateResultWatch") ListData watchTask,
	// @Out("created_ReliabilityIndexTask") StringData reliabilityIndexTask)
	// throws ACPException {
	// String task = watchTask.lpop();
	// if (task == null) // 未分配到任务，直接返回
	// return;
	//
	// ResultWatchTask t = Utils.toObject(task, ResultWatchTask.class);
	//
	// LOGGER.info("----------------start watchStateEstimate------------------------");
	//
	// MapDataOperations ops = connectionFactory.getMapDataOperations();
	// Long n = ops.getSize(t.getKey());
	// Long start = System.currentTimeMillis();
	// Long now = start;
	// Long timeout = t.getCount() * 3000;// 设置超时
	// LOGGER.info("设置计算超时:" + timeout);
	// while (!n.equals(t.getCount()) && (now - start) < timeout) {
	// n = ops.getSize(t.getKey());
	//
	// try {
	// Thread.sleep(5);
	// now = System.currentTimeMillis();
	// } catch (InterruptedException e) {
	// // TODO Auto-generated catch block
	// e.printStackTrace();
	// }
	// }
	//
	// if (now - start >= timeout) {
	// LOGGER.info("计算超时:" + timeout);
	// } else if (n.equals(t.getCount())) {
	// LOGGER.info("发布可靠性指标任务");
	// reliabilityIndexTask.setContent("reliabilityIndexTask");
	// }
	// LOGGER.info("----------------end watchStateEstimate------------------------");
	// }

	// @AplFunction(value = "StateEstimate", desc = "状态后评估")
	// public void stateEstimate(@In(created_PRModel) MemDBData pRModel,
	// @In(created_StateEstimateTask) ListData estimateTask,
	// @In(created_StateSampleResult) MapData stateSampleResult,
	// @Out(created_StateEsteimateResult) MapData stateEstimateResult)
	// throws ACPException {
	// LOGGER.info("----------------start stateEstimate------------------------");
	// // TODO:
	// callStateEstimate();
	// String statIndex = null;
	// int taskCount = 0;
	// while ((statIndex = estimateTask.lpop()) != null) {
	// System.out.println("Process estimate task : " + statIndex);
	// taskCount++;
	// }
	//
	// System.out.println("Process estimate task count :" + taskCount);
	//
	// int count = 0;
	// Iterable<FState> fStates = fStateDao.findAll();
	// Map<Integer, StateEstimateResult> resultMap = new HashMap<Integer,
	// StateEstimateResult>();
	// // List<String> taskList = new ArrayList<String>();
	// for (FState state : fStates) {
	// StateEstimateResult rt = new StateEstimateResult();
	// rt.setState(state);
	// // taskList.add(String.valueOf(count));
	// resultMap.put(count, rt);
	// count++;
	// if (count == 1)
	// LOGGER.info(state.toString());
	//
	// }
	// LOGGER.info("FState count=" + count);
	//
	// Iterable<FStateFDev> fStateFDevs = fStateFDevDao.findAll();
	// count = 0;
	// for (FStateFDev dev : fStateFDevs) {
	// StateEstimateResult rt = resultMap.get(dev.getFState());
	// if (rt == null) {
	// continue;
	// }
	// count++;
	// rt.getDevs().add(dev);
	//
	// if (count == 1)
	// LOGGER.info(dev.toString());
	//
	// }
	// LOGGER.info("FStateFDev count=" + count);
	//
	// Iterable<FStateMIsland> mIslands = mIslandDao.findAll();
	// count = 0;
	// for (FStateMIsland mIsland : mIslands) {
	// StateEstimateResult rt = resultMap.get(mIsland.getFState());
	// if (rt == null) {
	// continue;
	// }
	// count++;
	//
	// rt.getMislands().add(mIsland);
	//
	// if (count == 1)
	// LOGGER.info(mIsland.toString());
	//
	// }
	// LOGGER.info("FStateMIsland count=" + count);
	//
	// Iterable<FStateOvlAd> ovlAds = ovlAdDao.findAll();
	// count = 0;
	// for (FStateOvlAd ovlAd : ovlAds) {
	// StateEstimateResult rt = resultMap.get(ovlAd.getFState());
	// if (rt == null) {
	// continue;
	// }
	//
	// count++;
	// rt.getOvlAds().add(ovlAd);
	//
	// if (count == 1)
	// LOGGER.info(ovlAd.toString());
	//
	// }
	// LOGGER.info("FStateOvlAd count=" + count);
	//
	// Iterable<FStateOvlDev> ovlDevs = ovlDevDao.findAll();
	// count = 0;
	// for (FStateOvlDev ovlDev : ovlDevs) {
	// StateEstimateResult rt = resultMap.get(ovlDev.getFState());
	// if (rt == null) {
	// continue;
	// }
	//
	// count++;
	// rt.getOvlDevs().add(ovlDev);
	//
	// if (count == 1)
	// LOGGER.info(ovlDev.toString());
	//
	// }
	// LOGGER.info("FStateOvlDev count=" + count);
	//
	// Iterator<Entry<Integer, StateEstimateResult>> it = resultMap.entrySet()
	// .iterator();
	// Map<String, String> rtMap = new HashMap<String, String>();
	// while (it.hasNext()) {
	// Entry<Integer, StateEstimateResult> e = it.next();
	// rtMap.put(String.valueOf(e.getKey()), Utils.toString(e.getValue()));
	//
	// }
	//
	// stateEstimateResult.setContent(rtMap);
	//
	// stateEstimateResult.setKey(pRModel.getArea() + ":result:"
	// + state_estimate);
	//
	// // LOGGER.info("StateEstimateTask count=" + tasks.size());
	// LOGGER.info("----------------end stateEstimate------------------------");
	// }
	//
	// @AplFunction(value = "ReliabilityIndex", desc = "可靠性指标计算")
	// public void reliabilityIndex(
	// @In("created_PRModel") MemDBData pRModel,
	// @In("created_ReliabilityIndexTask") StringData reliabilityIndexTask,
	// @Out("created_ReliabilityIndexResult") MapData reliabilityIndexResult) {
	// LOGGER.info("----------------start reliabilityIndex------------------------");
	// // TODO:
	// //
	//
	// callReliabilityIndex();
	//
	// Iterable<com.znd.ei.memdb.reliabilty.domain.System> syss = systemDao
	// .findAll();
	// Map<String, String> rtMap = new HashMap<String, String>();
	// int count = 0;
	// for (com.znd.ei.memdb.reliabilty.domain.System sys : syss) {
	// rtMap.put(String.valueOf(count++), Utils.toString(sys));
	// }
	//
	// reliabilityIndexResult.setKey(pRModel.getArea() + ":result:"
	// + reliability_index);
	// reliabilityIndexResult.setContent(rtMap);
	// LOGGER.info("----------------end reliabilityIndex------------------------");
	//
	// }

//	public FStateDao getfStateDao() {
//		return fStateDao;
//	}
//
//	public FStateFDevDao getfStateFDevDao() {
//		return fStateFDevDao;
//	}
}

