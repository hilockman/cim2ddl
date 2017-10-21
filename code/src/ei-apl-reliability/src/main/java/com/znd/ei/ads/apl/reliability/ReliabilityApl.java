package com.znd.ei.ads.apl.reliability;

import java.util.HashMap;

import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.redisson.api.RMap;
import org.redisson.api.RedissonClient;
import org.redisson.api.mapreduce.RMapReduce;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.AbstractConnectionFactory;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.adf.ObjectRefData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;
import com.znd.ei.ads.apl.reliability.bean.ReliabilityIndexResult;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateConfig;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.ads.apl.reliability.bean.StateSampleTask;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.MemTable;
import com.znd.ei.memdb.reliabilty.dao.FStateDao;
import com.znd.ei.memdb.reliabilty.dao.FStateFDevDao;
import com.znd.ei.memdb.reliabilty.dao.FStateMIslandDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlAdDao;
import com.znd.ei.memdb.reliabilty.dao.FStateOvlDevDao;
import com.znd.ei.memdb.reliabilty.dao.SystemDao;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import static com.znd.ei.ads.AdsServer.*;
import static com.znd.ei.ads.apl.reliability.AppUtil.*;

//import com.znd.ei.memdb.reliabilty.domain.System;
@Apl
public class ReliabilityApl {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(ReliabilityApl.class);

	static public String rootPath = "E:/ZNDProject";
	static {
		String str = System.getenv("ZND_HOME");
		if (str != null && !str.isEmpty()) {
			rootPath = str;
		}

	}

	public static ReliabilityApl INSTANCE = null;

	public ReliabilityApl() {
		INSTANCE = this;
	}

	public static String dataRootPath = rootPath + "/data";
	public static String execRootPath = rootPath + "/bin_x64";

	@Autowired
	FStateDao fStateDao;

	@Autowired
	FStateFDevDao fStateFDevDao;

	@Autowired
	FStateMIslandDao mIslandDao;

	@Autowired
	FStateOvlAdDao ovlAdDao;

	@Autowired
	FStateOvlDevDao ovlDevDao;

	@Autowired
	SystemDao systemDao;

	@Autowired
	AbstractConnectionFactory connectionFactory;

	@Autowired
	DataFieldStorage storage;

	private String modelArea = "RTS79";

	private void callBpaLoader() {
		AppUtil.execute(GC_BPA_LOADER, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi");
	}

	private void callBpa2Pr() {
		AppUtil.execute(GC_BPA_2_PR, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi", dataRootPath
				+ "/RTS79.xml");
	}

	private void callStateSample() {
		AppUtil.execBuilder(GC_STATE_SAMPLE).addParam(execRootPath)
		// 抽样对象类型，全部；支路；发电机 nPRSampleObject
				.addParam("全部")
				// 抽样类型 nPRSampleMethod
				.addParam("1").
				// 抽样最大发电机故障重数 nMaxGenFault
				addParam("20")
				// 抽样最大支路故障重数 nMaxBranFault
				.addParam("20")
				// MCS最大抽样仿真时长 nMCSSimulateTime
				.addParam("2000000").
				// MCS[蒙特卡罗]设备故障概率门槛值 fMCSMinStateProb
				addParam("0.000000").
				// FST[快速排序]累积概率 fFSTMaxCumuProb
				addParam("0.990000")
				// FST[快速排序]设备故障概率门槛值 fFSTMinStateProb
				.addParam("1.000000")
				// FST[快速排序]最大状态数 nFSTMaxStateNum
				.addParam("100000")
				// STS[状态抽样]最大状态数 nSTSMaxStateNum
				.addParam("100000")
				// ANA[解析法]设备故障概率门槛值 fANAMinStateProb
				.addParam("1.000000").logger(new AppLogger() {

					@Override
					public void print(String log) {
						LOGGER.info(log);
					}
				}).exec();
	}

	public static void callStateEstimate(FState state,
			StateEstimateConfig config) {
		AppUtil.execBuilder(GC_STATE_ESTIMATE).addParam(execRootPath)
		// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam(config.getDc2AcFactor())
				// 线路消限 bLineELimit
				.addParam(config.getLineELimit())
				// 主变消限 bTranELimit
				.addParam(config.getTranELimit())
				// 调整发电机消限 bGenPELimit
				.addParam(config.getGenPELimit())
				// 调整UPFC消限 bUPFCELimit
				.addParam(config.getuPFCELimit())
				// 厂用电参与消限 bAuxLoadAdjust
				.addParam(config.getAuxLoadAdjust())
				// 等值发电机参与消限 bEQGenAdjust
				.addParam(config.geteQGenAdjust())
				// 等值负荷参与消限 bEQLoadAdjust
				.addParam(config.geteQLoadAdjust())
				// 孤岛的最小容载比 fMinIslandGLRatio
				.addParam(config.getMinIslandGLRatio())
				// UPFC采用变容法 bUPFCAdjustRC
				.addParam(config.getuPFCAdjustRC()).logger(new AppLogger() {

					@Override
					public void print(String log) {
						LOGGER.info(log);
					}
				}).exec();

	}

	public static void callStateEstimate() {
		callStateEstimate(null, new StateEstimateConfig());
	}
	

	public static void callReliabilityIndex(StateEstimateConfig config) {
		AppUtil.execBuilder(GC_RELIABILITY_INDEX)
				.addParam(execRootPath)
				// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam(config.getDc2AcFactor()).logger(new AppLogger() {

					@Override
					public void print(String log) {
						LOGGER.info(log);
					}
				}).exec();
	}

	private void printDbEntry(DbEntryOperations ops) throws DbException {
		List<MemTable> tables = ops.getTables();
		for (MemTable table : tables) {
			long count = ops.getRecordCount(table);
			if (count == 0)
				continue;

			LOGGER.info(String.format("Table :%s, desc:%s, count:%d",
					table.getName(), table.getDescription(), count));
			List<String[]> rt = ops.findAllRecords(table);
			for (String[] records : rt) {
				LOGGER.info(String.join(" ", records));
				break;
			}
		}
	}



	@Autowired
	RedissonClient redissonClient;

	@AplFunction(desc = "模型加载:加载BPA模型,BPA网络模型转可靠性网络模型")
	public void loadModel(@In(create_AllModel) StringData createConfig,
			@Out(created_BPAModel) MemDBData bPAModel,
			@Out(created_PRModel) MemDBData pRModel,
			@Out(get_Reliability) StringData calcTask) throws ACPException,
			UnsupportedOperation {

		LOGGER.info("----------------start create_BPAModel------------------------");
		LOGGER.info("config:" + createConfig.getContent());
		callBpaLoader();

		bPAModel.setEntryName(MDBDefine.g_strBpaDBEntry);
		bPAModel.setArea(modelArea);

		callBpa2Pr();
		pRModel.setEntryName(MDBDefine.g_strPRDBEntry);
		pRModel.setArea(modelArea);

		// AdsServer server = connectionFactory.getServer();
		// if (server != null)
		// server.publish(created_StateSampleTask, state_sample);

		calcTask.setKey(pRModel.getArea() + ":task:" + powersystem_reliability);

		LOGGER.info("----------------end create_BPAModel------------------------");

	}

	@AplFunction(desc = "reliability")
	public void calcReliability(
			@In(get_Reliability) StringData calcTask,
			@Out(created_StateSampleResult) MapData<Integer, StateSampleTask> stateSampleResult,
			@Out(created_StateEsteimateResult) MapData<Integer, StateEstimateResult> stateEstimateResult,
			@Out(created_ReliabilityIndexResult) ObjectRefData<ReliabilityIndexResult> reliabilityIndexResult) {
		LOGGER.info("----------------start calc reliability------------------------");
		// 状态抽样
		callStateSample();

		int count = 0;
		Iterable<FState> fStates = fStateDao.findAll();
		Map<Integer, StateSampleTask> resultMap = new HashMap<>();
		for (FState state : fStates) {
			StateSampleTask task = new StateSampleTask();
			task.setState(state);
			resultMap.put(count, task);
			count++;
			if (count == 1)
				LOGGER.info(state.toString());

		}
		LOGGER.info("FState count=" + count);

		Iterable<FStateFDev> fStateFDevs = fStateFDevDao.findAll();
		count = 0;
		for (FStateFDev dev : fStateFDevs) {
			StateSampleTask rt = resultMap.get(dev.getFState());
			if (rt == null) {
				continue;
			}
			count++;
			rt.getDevs().add(dev);

			if (count == 1)
				LOGGER.info(dev.toString());

		}
		LOGGER.info("FStateFDev count=" + count);

		RMap<Integer, StateSampleTask> map = redissonClient
				.getMap("sampleStateMap");

		Set<Entry<Integer, StateSampleTask>> s = resultMap.entrySet();
		for (Entry<Integer, StateSampleTask> e : s) {
			map.put(e.getKey(), e.getValue());
		}

		RMapReduce<Integer, StateSampleTask, Integer, StateEstimateResult> mapReduce = map
				.<Integer, StateEstimateResult> mapReduce()
				.mapper(new StateSampleMap()).reducer(new StateSampleReducer());

		System.out.println("Start state estimate ...");
		Map<Integer, StateEstimateResult> mapToResult = mapReduce.execute();
		
		stateEstimateResult.putAll(mapToResult);
		
		System.out.println("Start reliability index");
		ReliabilityIndexResult indexResult = mapReduce
				.execute(new StateSampleCollator());
		reliabilityIndexResult.setContent(indexResult);

		LOGGER.info("----------------end calc reliability------------------------");
	}

//	@AplFunction(desc = "BPA模型加载")
//	public void loadBPA(@In("create_BPAModel") StringData createConfig,
//			@Out("created_BPAModel") MemDBData bPAModel) throws ACPException,
//			UnsupportedOperation {
//
//		LOGGER.info("----------------start create_BPAModel------------------------");
//		LOGGER.info("config:" + createConfig.getContent());
//		callBpaLoader();
//
//		bPAModel.setEntryName(MDBDefine.g_strBpaDBEntry);
//		bPAModel.setArea(modelArea);
//
//		// writeDataField(ContentCodeDefines.created_BPAModel, db,
//		// getConnectionFactory().getMemDBDataOperations());
//
//		LOGGER.info("----------------end create_BPAModel------------------------");
//
//	}
//
//	@AplFunction(desc = "BPA网络模型转可靠性网络模型")
//	public void bpa2Pr(@In("created_BPAModel") MemDBData bPAModel,
//			@Out("created_PRModel") MemDBData pRModel,
//			@Out("created_StateSampleTask") ListData tasks)
//			throws ACPException, UnsupportedOperation {
//
//		LOGGER.info("----------------start BPA2PR------------------------");
//		callBpa2Pr();
//
//		pRModel.setEntryName(MDBDefine.g_strPRDBEntry);
//		pRModel.setArea(modelArea);
//
//		// writeDataField(ContentCodeDefines.created_BPAModel, db,
//		// getConnectionFactory().getMemDBDataOperations());
//
//		List<String> strs = new ArrayList<String>();
//		strs.add(state_sample);
//		tasks.setContent(strs);
//		tasks.setKey(pRModel.getArea() + ":task:" + state_sample);
//
//		LOGGER.info("----------------end BPA2PR------------------------");
//
//	}

//	@AplFunction(value = "StateSample", desc = "状态抽样")
//	public void stateSample(@In("created_BPAModel") MemDBData bPAModel,
//			@In("created_PRModel") MemDBData pRModel,
//			@In("created_StateSampleTask") ListData stateSampleTasks,
//			@Out(created_StateEstimateTask) ListData sateEstimateTasks,
//			@Out("created_StateSampleResult") MapData stateSampleResult,
//			@Out("created_StateEsteimateResultWatch") ListData watchTask) {
//		LOGGER.info("----------------start stateSample------------------------");
//		// 状态抽样
//		callStateSample();
//
//		// 获取抽样任务
//		String str = null;
//		try {
//			str = stateSampleTasks.lpop();
//		} catch (ACPException e1) {
//			// TODO Auto-generated catch block
//			e1.printStackTrace();
//		}
//
//		// 未获得抽样任务，则直接返回
//		if (str == null) {
//			LOGGER.info("----------------end stateSample------------------------");
//			return;
//		}
//
//		// 清除总线上前一次计算结果
//		Set<String> keys = new HashSet<String>();
//		keys.addAll(connectionFactory.findKeys(pRModel.getArea() + ":result:*"));
//		keys.addAll(connectionFactory.findKeys(pRModel.getArea() + ":task:*"));
//		if (keys.size() > 0) {
//			LOGGER.info("清除缓存keys:" + String.join(",", keys));
//			connectionFactory.deleteKeys(keys.toArray(new String[0]));
//		}
//
//		int count = 0;
//		Iterable<FState> fStates = fStateDao.findAll();
//		Map<Integer, StateSampleResult> resultMap = new HashMap<Integer, StateSampleResult>();
//		List<String> taskList = new ArrayList<String>();
//		for (FState state : fStates) {
//			StateSampleResult task = new StateSampleResult();
//			taskList.add(String.valueOf(count));
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
//			StateSampleResult rt = resultMap.get(dev.getFState());
//			if (rt == null) {
//				continue;
//			}
//			count++;
//			rt.devs.add(dev);
//
//			if (count == 1)
//				LOGGER.info(dev.toString());
//
//		}
//		LOGGER.info("FStateFDev count=" + count);
//
//		Iterator<Entry<Integer, StateSampleResult>> it = resultMap.entrySet()
//				.iterator();
//		Map<String, String> rtMap = new HashMap<String, String>();
//		while (it.hasNext()) {
//			Entry<Integer, StateSampleResult> e = it.next();
//			String content = Utils.toString(e.getValue());
//			rtMap.put(String.valueOf(e.getKey()), content);
//
//		}
//
//		if (!taskList.isEmpty()) {
//			String statEstimateTaskKey = pRModel.getArea() + ":task:"
//					+ state_estimate;
//			if (!connectionFactory.hasKey(statEstimateTaskKey)) {
//				sateEstimateTasks.setContent(taskList);
//				sateEstimateTasks.setKey(statEstimateTaskKey);
//			}
//
//			String statSampleResultKey = pRModel.getArea() + ":result:"
//					+ state_sample;
//			if (!connectionFactory.hasKey(statSampleResultKey)) {
//				stateSampleResult.setContent(rtMap);
//				stateSampleResult.setKey(statSampleResultKey);
//			}
//
//			String stateEstimateWatchKey = pRModel.getArea() + ":task:"
//					+ state_estimate_watch;
//			if (!connectionFactory.hasKey(stateEstimateWatchKey)) {
//				List<String> counts = new ArrayList<String>();
//				ResultWatchTask t = new ResultWatchTask();
//				t.setCount(Long.valueOf(taskList.size()));
//				String statEstimateResultKey = pRModel.getArea() + ":result:"
//						+ state_estimate;
//				t.setKey(statEstimateResultKey);
//				counts.add(Utils.toString(t));
//				watchTask.setKey(stateEstimateWatchKey);
//				watchTask.setContent(counts);
//			}
//
//		}
//		LOGGER.info("StateEstimateTask count=" + taskList.size());
//		LOGGER.info("----------------end stateSample------------------------");
//	}

//	class ResultWatchTask {
//		private String key;
//		private Long count;
//
//		public String getKey() {
//			return key;
//		}
//
//		public void setKey(String key) {
//			this.key = key;
//		}
//
//		public Long getCount() {
//			return count;
//		}
//
//		public void setCount(Long count) {
//			this.count = count;
//		}
//
//	}

//	@AplFunction(value = "WatchStateEstimate", desc = "监控状态后评估")
//	public void watchStateEstimate(
//			@In("created_StateEsteimateResultWatch") ListData watchTask,
//			@Out("created_ReliabilityIndexTask") StringData reliabilityIndexTask)
//			throws ACPException {
//		String task = watchTask.lpop();
//		if (task == null) // 未分配到任务，直接返回
//			return;
//
//		ResultWatchTask t = Utils.toObject(task, ResultWatchTask.class);
//
//		LOGGER.info("----------------start watchStateEstimate------------------------");
//
//		MapDataOperations ops = connectionFactory.getMapDataOperations();
//		Long n = ops.getSize(t.getKey());
//		Long start = System.currentTimeMillis();
//		Long now = start;
//		Long timeout = t.getCount() * 3000;// 设置超时
//		LOGGER.info("设置计算超时:" + timeout);
//		while (!n.equals(t.getCount()) && (now - start) < timeout) {
//			n = ops.getSize(t.getKey());
//
//			try {
//				Thread.sleep(5);
//				now = System.currentTimeMillis();
//			} catch (InterruptedException e) {
//				// TODO Auto-generated catch block
//				e.printStackTrace();
//			}
//		}
//
//		if (now - start >= timeout) {
//			LOGGER.info("计算超时:" + timeout);
//		} else if (n.equals(t.getCount())) {
//			LOGGER.info("发布可靠性指标任务");
//			reliabilityIndexTask.setContent("reliabilityIndexTask");
//		}
//		LOGGER.info("----------------end watchStateEstimate------------------------");
//	}

//	@AplFunction(value = "StateEstimate", desc = "状态后评估")
//	public void stateEstimate(@In(created_PRModel) MemDBData pRModel,
//			@In(created_StateEstimateTask) ListData estimateTask,
//			@In(created_StateSampleResult) MapData stateSampleResult,
//			@Out(created_StateEsteimateResult) MapData stateEstimateResult)
//			throws ACPException {
//		LOGGER.info("----------------start stateEstimate------------------------");
//		// TODO:
//		callStateEstimate();
//		String statIndex = null;
//		int taskCount = 0;
//		while ((statIndex = estimateTask.lpop()) != null) {
//			System.out.println("Process estimate task : " + statIndex);
//			taskCount++;
//		}
//
//		System.out.println("Process estimate task count :" + taskCount);
//
//		int count = 0;
//		Iterable<FState> fStates = fStateDao.findAll();
//		Map<Integer, StateEstimateResult> resultMap = new HashMap<Integer, StateEstimateResult>();
//		// List<String> taskList = new ArrayList<String>();
//		for (FState state : fStates) {
//			StateEstimateResult rt = new StateEstimateResult();
//			rt.setState(state);
//			// taskList.add(String.valueOf(count));
//			resultMap.put(count, rt);
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
//			StateEstimateResult rt = resultMap.get(dev.getFState());
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
//		Iterable<FStateMIsland> mIslands = mIslandDao.findAll();
//		count = 0;
//		for (FStateMIsland mIsland : mIslands) {
//			StateEstimateResult rt = resultMap.get(mIsland.getFState());
//			if (rt == null) {
//				continue;
//			}
//			count++;
//
//			rt.getMislands().add(mIsland);
//
//			if (count == 1)
//				LOGGER.info(mIsland.toString());
//
//		}
//		LOGGER.info("FStateMIsland count=" + count);
//
//		Iterable<FStateOvlAd> ovlAds = ovlAdDao.findAll();
//		count = 0;
//		for (FStateOvlAd ovlAd : ovlAds) {
//			StateEstimateResult rt = resultMap.get(ovlAd.getFState());
//			if (rt == null) {
//				continue;
//			}
//
//			count++;
//			rt.getOvlAds().add(ovlAd);
//
//			if (count == 1)
//				LOGGER.info(ovlAd.toString());
//
//		}
//		LOGGER.info("FStateOvlAd count=" + count);
//
//		Iterable<FStateOvlDev> ovlDevs = ovlDevDao.findAll();
//		count = 0;
//		for (FStateOvlDev ovlDev : ovlDevs) {
//			StateEstimateResult rt = resultMap.get(ovlDev.getFState());
//			if (rt == null) {
//				continue;
//			}
//
//			count++;
//			rt.getOvlDevs().add(ovlDev);
//
//			if (count == 1)
//				LOGGER.info(ovlDev.toString());
//
//		}
//		LOGGER.info("FStateOvlDev count=" + count);
//
//		Iterator<Entry<Integer, StateEstimateResult>> it = resultMap.entrySet()
//				.iterator();
//		Map<String, String> rtMap = new HashMap<String, String>();
//		while (it.hasNext()) {
//			Entry<Integer, StateEstimateResult> e = it.next();
//			rtMap.put(String.valueOf(e.getKey()), Utils.toString(e.getValue()));
//
//		}
//
//		stateEstimateResult.setContent(rtMap);
//
//		stateEstimateResult.setKey(pRModel.getArea() + ":result:"
//				+ state_estimate);
//
//		// LOGGER.info("StateEstimateTask count=" + tasks.size());
//		LOGGER.info("----------------end stateEstimate------------------------");
//	}
//
//	@AplFunction(value = "ReliabilityIndex", desc = "可靠性指标计算")
//	public void reliabilityIndex(
//			@In("created_PRModel") MemDBData pRModel,
//			@In("created_ReliabilityIndexTask") StringData reliabilityIndexTask,
//			@Out("created_ReliabilityIndexResult") MapData reliabilityIndexResult) {
//		LOGGER.info("----------------start reliabilityIndex------------------------");
//		// TODO:
//		//
//
//		callReliabilityIndex();
//
//		Iterable<com.znd.ei.memdb.reliabilty.domain.System> syss = systemDao
//				.findAll();
//		Map<String, String> rtMap = new HashMap<String, String>();
//		int count = 0;
//		for (com.znd.ei.memdb.reliabilty.domain.System sys : syss) {
//			rtMap.put(String.valueOf(count++), Utils.toString(sys));
//		}
//
//		reliabilityIndexResult.setKey(pRModel.getArea() + ":result:"
//				+ reliability_index);
//		reliabilityIndexResult.setContent(rtMap);
//		LOGGER.info("----------------end reliabilityIndex------------------------");
//
//	}

	public FStateDao getfStateDao() {
		return fStateDao;
	}

	public FStateFDevDao getfStateFDevDao() {
		return fStateFDevDao;
	}
}

//class StateSampleResult {
//	FState state;
//	List<FStateFDev> devs = new ArrayList<FStateFDev>();
//
//	public FState getState() {
//		return state;
//	}
//
//	public void setState(FState state) {
//		this.state = state;
//	}
//
//	public List<FStateFDev> getDevs() {
//		return devs;
//	}
//
//	public void setDevs(List<FStateFDev> devs) {
//		this.devs = devs;
//	}
//
//}
