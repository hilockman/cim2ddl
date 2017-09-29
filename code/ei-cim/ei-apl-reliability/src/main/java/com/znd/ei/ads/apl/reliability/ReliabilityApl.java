package com.znd.ei.ads.apl.reliability;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;

import com.ZhongND.memdb.MDBDefine;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.MemTable;
import com.znd.ei.memdb.reliabilty.dao.FStateFDevRepository;
import com.znd.ei.memdb.reliabilty.dao.FStateRepository;

@Apl
public class ReliabilityApl {
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
	FStateRepository fStateRepository;
	
	@Autowired
	FStateFDevRepository fStateFDevRepository;
	
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
				.addParam("1.000000").exec();
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
				.addParam("1").exec();

	}

	private void callReliabilityIndex() {
		AppUtil.execBuilder(AppUtil.GC_RELIABILITY_INDEX)
				.addParam(execRootPath)
				// 直流潮流2 交流潮流系数 fDc2AcFactor
				.addParam("1.100000").exec();
	}

	private void printDbEntry(DbEntryOperations ops) throws DbException {
		List<MemTable> tables = ops.getTables();
		for (MemTable table : tables) {
			long count = ops.getRecordCount(table);
			if (count == 0)
				continue;

			System.out.println(String.format("Table :%s, desc:%s, count:%d",
					table.getName(), table.getDescription(), count));
			List<String[]> rt = ops.findAllRecords(table);
			for (String[] records : rt) {
				System.out.println(String.join(" ", records));
				break;
			}
		}
	}
	@AplFunction
	public void loadBPA(@In("create_BPAModel") StringData createConfig,
			@Out("created_BPAModel") MemDBData bPAModel) throws ACPException,
			UnsupportedOperation {

		System.out.println("----------------start create_BPAModel------------------------");
		System.out.println("config:"+createConfig.getContent());
		callBpaLoader();
		
		bPAModel.setEntryName(MDBDefine.g_strBpaDBEntry);
		bPAModel.setArea("test");

		// writeDataField(ContentCodeDefines.created_BPAModel, db,
		// getConnectionFactory().getMemDBDataOperations());
		
		System.out.println("----------------end create_BPAModel------------------------");
      
	}
	@AplFunction
	public void bpa2Pr(@In("created_BPAModel") MemDBData bPAModel, @Out("created_PRModel") MemDBData pRModel) throws ACPException,
			UnsupportedOperation {

		System.out.println("----------------start BPA2PR------------------------");
		callBpa2Pr();
		
		pRModel.setEntryName(MDBDefine.g_strPRDBEntry);
		bPAModel.setArea("test");

		// writeDataField(ContentCodeDefines.created_BPAModel, db,
		// getConnectionFactory().getMemDBDataOperations());
		
		System.out.println("----------------end BPA2PR------------------------");
      
	}
	
	@AplFunction
	public void stateSample(@In("created_BPAModel") MemDBData bPAModel,
			@In("created_PRModel") MemDBData pRModel,
			//@In("created_PRSettings") StringRefData pRSettings,
			@Out("created_EstimateTask") ListData estimateTask) {
		System.out.println("----------------start stateSample------------------------");
		System.out.println("----------------end stateSample------------------------");
	}
}
