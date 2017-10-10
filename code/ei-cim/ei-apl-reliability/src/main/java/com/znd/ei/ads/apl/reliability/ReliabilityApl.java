package com.znd.ei.ads.apl.reliability;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.AbstractConnectionFactory;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;
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
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;

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

	String dataRootPath = rootPath + "/data";
	String execRootPath = rootPath + "/bin_x64";

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

	private String modelArea = "RTS79";

	private void callBpaLoader() {
		AppUtil.execute(AppUtil.GC_BPA_LOADER, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi");
	}

	private void callBpa2Pr() {
		AppUtil.execute(AppUtil.GC_BPA_2_PR, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi", dataRootPath
				+ "/RTS79.xml");
	}

	private void callStateSample() {
		AppUtil.execBuilder(AppUtil.GC_STATE_SAMPLE).addParam(execRootPath)
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

	private void callStateEstimate() {
		AppUtil.execBuilder(AppUtil.GC_STATE_ESTIMATE).addParam(execRootPath)
		// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam("1.100000")
				// 线路消限 bLineELimit
				.addParam("1")
				// 主变消限 bTranELimit
				.addParam("1")
				// 调整发电机消限 bGenPELimit
				.addParam("1")
				// 调整UPFC消限 bUPFCELimit
				.addParam("1")
				// 厂用电参与消限 bAuxLoadAdjust
				.addParam("1")
				// 等值发电机参与消限 bEQGenAdjust
				.addParam("0")
				// 等值负荷参与消限 bEQLoadAdjust
				.addParam("0")
				// 孤岛的最小容载比 fMinIslandGLRatio
				.addParam("0.500000")
				// UPFC采用变容法 bUPFCAdjustRC
				.addParam("1").logger(new AppLogger() {

					@Override
					public void print(String log) {
						LOGGER.info(log);
					}
				}).exec();

	}

	private void callReliabilityIndex() {
		AppUtil.execBuilder(AppUtil.GC_RELIABILITY_INDEX)
				.addParam(execRootPath)
				// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam("1.100000").logger(new AppLogger() {

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

	@AplFunction(desc = "BPA模型加载")
	public void loadBPA(@In("create_BPAModel") StringData createConfig,
			@Out("created_BPAModel") MemDBData bPAModel) throws ACPException,
			UnsupportedOperation {

		LOGGER.info("----------------start create_BPAModel------------------------");
		LOGGER.info("config:" + createConfig.getContent());
		callBpaLoader();

		bPAModel.setEntryName(MDBDefine.g_strBpaDBEntry);
		bPAModel.setArea(modelArea);

		// writeDataField(ContentCodeDefines.created_BPAModel, db,
		// getConnectionFactory().getMemDBDataOperations());

		LOGGER.info("----------------end create_BPAModel------------------------");

	}

	@AplFunction(desc = "BPA网络模型转可靠性网络模型")
	public void bpa2Pr(@In("created_BPAModel") MemDBData bPAModel,
			@Out("created_PRModel") MemDBData pRModel,
			@Out("created_StateSampleTask") ListData tasks)
			throws ACPException, UnsupportedOperation {

		LOGGER.info("----------------start BPA2PR------------------------");
		callBpa2Pr();

		pRModel.setEntryName(MDBDefine.g_strPRDBEntry);
		pRModel.setArea(modelArea);

		// writeDataField(ContentCodeDefines.created_BPAModel, db,
		// getConnectionFactory().getMemDBDataOperations());

		List<String> strs = new ArrayList<String>();
		strs.add(state_sample);
		tasks.setContent(strs);		
		tasks.setKey(pRModel.getArea() + ":task:"
				+ state_sample);
		LOGGER.info("----------------end BPA2PR------------------------");

	}

	public final static String state_estimate = "state-estimate";
	public final static String state_sample = "state-sample";
	public final static String reliability_index = "reliability-index";

	@AplFunction(desc = "状态抽样")
	public void stateSample(@In("created_BPAModel") MemDBData bPAModel,
			@In("created_PRModel") MemDBData pRModel,
			@In("created_StateSampleTask") ListData stateSampleTasks,
			@Out("created_StateEstimateTask") ListData sateEstimateTasks,
			@Out("created_StateSampleResult") MapData stateSampleResult) {
		String str = null;
		try {
			str = stateSampleTasks.lpop();
		} catch (ACPException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		if (str == null)
			return;
		
		
		LOGGER.info("----------------start stateSample------------------------");
		// 清除前一次计算结果

		// String[] keys ={state_estimate_task, state_sample_result,
		// reliability_index_task, state_estimate_result,
		// reliability_index_result};
		// for (int i = 0; i < keys.length; i++) {
		// keys[i] = pRModel.getArea() + ":" + keys[i];

		// }

		
		Set<String> keys = new HashSet<String>();
		keys.addAll(connectionFactory.findKeys(pRModel.getArea() + ":result:*"));
		// keys.addAll(connectionFactory.findKeys(pRModel.getArea() +
		// "*-result"));
		keys.addAll(connectionFactory.findKeys(pRModel.getArea() + ":task:*"));
		// keys.addAll(connectionFactory.findKeys(pRModel.getArea() +
		// "*-task"));
		if (keys.size() > 0) {
			LOGGER.info("清除缓存keys:" + String.join(",", keys));
			connectionFactory.deleteKeys(keys.toArray(new String[0]));
		}

		callStateSample();
		int count = 0;
		Iterable<FState> fStates = fStateDao.findAll();
		Map<Integer, StateSampleResult> resultMap = new HashMap<Integer, StateSampleResult>();
		List<String> taskList = new ArrayList<String>();
		for (FState state : fStates) {
			StateSampleResult task = new StateSampleResult();
			taskList.add(String.valueOf(count));
			resultMap.put(count, task);
			count++;
			if (count == 1)
				LOGGER.info(state.toString());

		}
		LOGGER.info("FState count=" + count);

		Iterable<FStateFDev> fStateFDevs = fStateFDevDao.findAll();
		count = 0;
		for (FStateFDev dev : fStateFDevs) {
			StateSampleResult rt = resultMap.get(dev.getFState());
			if (rt == null) {
				continue;
			}
			count++;
			rt.devs.add(dev);

			if (count == 1)
				LOGGER.info(dev.toString());

		}
		LOGGER.info("FStateFDev count=" + count);

		Iterator<Entry<Integer, StateSampleResult>> it = resultMap.entrySet()
				.iterator();
		List<String> tasks = new ArrayList<String>();
		Map<String, String> rtMap = new HashMap<String, String>();
		while (it.hasNext()) {
			Entry<Integer, StateSampleResult> e = it.next();
			String content = Utils.toString(e.getValue());
			rtMap.put(String.valueOf(e.getKey()), content);
			tasks.add(content);
		}

		if (!tasks.isEmpty()) {
			sateEstimateTasks.setContent(tasks);
			sateEstimateTasks.setKey(pRModel.getArea() + ":task:"
					+ state_estimate);
			stateSampleResult.setContent(rtMap);
			stateSampleResult.setKey(pRModel.getArea() + ":result:"
					+ state_sample);

		}
		LOGGER.info("StateEstimateTask count=" + tasks.size());

		LOGGER.info("----------------end stateSample------------------------");
	}

	@AplFunction(desc = "状态后评估")
	public void stateEstimate(
			@In("created_PRModel") MemDBData pRModel,
			@In("created_StateEstimateTask") ListData estimateTask,
			@In("created_StateSampleResult") MapData stateSampleResult,
			@Out("created_ReliabilityIndexTask") ListData reliabilityIndexTasks,
			@Out("created_StateEsteimateResult") MapData stateEstimateResult) {
		LOGGER.info("----------------start stateEstimate------------------------");
		// TODO:
		// String statIndex = null;
		// while ((statIndex = estimateTask.lpop()) != null) {
		//
		// }

		callStateEstimate();

		int count = 0;
		Iterable<FState> fStates = fStateDao.findAll();
		Map<Integer, StateEstimateResult> resultMap = new HashMap<Integer, StateEstimateResult>();
		// List<String> taskList = new ArrayList<String>();
		for (FState state : fStates) {
			StateEstimateResult rt = new StateEstimateResult();
			rt.state = state;
			// taskList.add(String.valueOf(count));
			resultMap.put(count, rt);
			count++;
			if (count == 1)
				LOGGER.info(state.toString());

		}
		LOGGER.info("FState count=" + count);

		Iterable<FStateFDev> fStateFDevs = fStateFDevDao.findAll();
		count = 0;
		for (FStateFDev dev : fStateFDevs) {
			StateEstimateResult rt = resultMap.get(dev.getFState());
			if (rt == null) {
				continue;
			}
			count++;
			rt.devs.add(dev);

			if (count == 1)
				LOGGER.info(dev.toString());

		}
		LOGGER.info("FStateFDev count=" + count);

		Iterable<FStateMIsland> mIslands = mIslandDao.findAll();
		count = 0;
		for (FStateMIsland mIsland : mIslands) {
			StateEstimateResult rt = resultMap.get(mIsland.getFState());
			if (rt == null) {
				continue;
			}
			count++;

			rt.mislands.add(mIsland);

			if (count == 1)
				LOGGER.info(mIsland.toString());

		}
		LOGGER.info("FStateMIsland count=" + count);

		Iterable<FStateOvlAd> ovlAds = ovlAdDao.findAll();
		count = 0;
		for (FStateOvlAd ovlAd : ovlAds) {
			StateEstimateResult rt = resultMap.get(ovlAd.getFState());
			if (rt == null) {
				continue;
			}

			count++;
			rt.ovlAds.add(ovlAd);

			if (count == 1)
				LOGGER.info(ovlAd.toString());

		}
		LOGGER.info("FStateOvlAd count=" + count);

		Iterable<FStateOvlDev> ovlDevs = ovlDevDao.findAll();
		count = 0;
		for (FStateOvlDev ovlDev : ovlDevs) {
			StateEstimateResult rt = resultMap.get(ovlDev.getFState());
			if (rt == null) {
				continue;
			}

			count++;
			rt.ovlDevs.add(ovlDev);

			if (count == 1)
				LOGGER.info(ovlDev.toString());

		}
		LOGGER.info("FStateOvlDev count=" + count);

		Iterator<Entry<Integer, StateEstimateResult>> it = resultMap.entrySet()
				.iterator();
		List<String> tasks = new ArrayList<String>();
		Map<String, String> rtMap = new HashMap<String, String>();
		while (it.hasNext()) {
			Entry<Integer, StateEstimateResult> e = it.next();
			rtMap.put(String.valueOf(e.getKey()), Utils.toString(e.getValue()));

		}

		tasks.add("reliabilityIndex");

		if (!tasks.isEmpty()) {
			reliabilityIndexTasks.setContent(tasks);

			reliabilityIndexTasks.setKey(pRModel.getArea() + ":task:"
					+ reliability_index);
			stateEstimateResult.setContent(rtMap);

			stateEstimateResult.setKey(pRModel.getArea() + ":result:"
					+ state_estimate);
		}
		LOGGER.info("StateEstimateTask count=" + tasks.size());
		LOGGER.info("----------------end stateEstimate------------------------");
	}

	@AplFunction(desc = "可靠性指标计算")
	public void reliabilityIndex(
			@In("created_PRModel") MemDBData pRModel,
			@In("created_ReliabilityIndexTask") ListData reliabilityIndexTask,
			@Out("created_ReliabilityIndexResult") MapData reliabilityIndexResult) {
		LOGGER.info("----------------start reliabilityIndex------------------------");
		// TODO:
		//

		callReliabilityIndex();

		Iterable<com.znd.ei.memdb.reliabilty.domain.System> syss = systemDao
				.findAll();
		Map<String, String> rtMap = new HashMap<String, String>();
		int count = 0;
		for (com.znd.ei.memdb.reliabilty.domain.System sys : syss) {
			rtMap.put(String.valueOf(count++), Utils.toString(sys));
		}

		reliabilityIndexResult.setKey(pRModel.getArea() + ":result:"
				+ reliability_index);
		reliabilityIndexResult.setContent(rtMap);
		LOGGER.info("----------------end reliabilityIndex------------------------");

	}
}

class StateSampleResult {
	FState state;
	List<FStateFDev> devs = new ArrayList<FStateFDev>();

	public FState getState() {
		return state;
	}

	public void setState(FState state) {
		this.state = state;
	}

	public List<FStateFDev> getDevs() {
		return devs;
	}

	public void setDevs(List<FStateFDev> devs) {
		this.devs = devs;
	}

}

class StateEstimateResult {
	FState state;
	List<FStateFDev> devs = new ArrayList<FStateFDev>();
	// List<FStateMState> mstate = new ArrayList<FStateMState>();
	List<FStateMIsland> mislands = new ArrayList<FStateMIsland>();
	List<FStateOvlDev> ovlDevs = new ArrayList<FStateOvlDev>();
	List<FStateOvlAd> ovlAds = new ArrayList<FStateOvlAd>();
}

class ReliabilityIndexResult {
	// FState state;
	// List<CopGen> copGens = new ArrayList<CopGen>();
	// List<CopTable> copTables = new ArrayList<CopTable>();
	com.znd.ei.memdb.reliabilty.domain.System sys;
}