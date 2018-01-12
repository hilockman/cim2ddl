package com.znd.ei.ads.console;

import java.util.List;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.ei.ads.apl.reliability.AppUtil;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.DbException;
import com.znd.ei.memdb.MetaTable;
import com.znd.ei.memdb.bpa.dao.ACLineRepository;
import com.znd.ei.memdb.bpa.domain.BpaDat_ACLine;
import com.znd.ei.memdb.reliabilty.dao.FStateDao;

@RunWith(SpringRunner.class)
@SpringBootTest
public class AppUtilTest {

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
	private ACLineRepository aclineRepository;

	@Autowired
	private FStateDao fStateRepository;

	@Autowired
	private DbEntryOperations bPAOps;

	@Autowired
	private DbEntryOperations pROps;

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
		List<MetaTable> tables = ops.getTables();
		for (MetaTable table : tables) {
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

	@Test
	public void testBpaLoader() throws Exception {
		System.out
				.println("----------------------start testBpaLoader-----------------------------");
		callBpaLoader();

		Iterable<BpaDat_ACLine> states = aclineRepository.findAll();
		for (BpaDat_ACLine state : states) {
			System.out.println(state);
		}

		printDbEntry(bPAOps);

		System.out
				.println("----------------------end testBpaLoader-----------------------------");

	}

	@Test
	public void testBpa2Pr() throws DbException {
		System.out
				.println("----------------------start testBpa2Pr-----------------------------");
		bPAOps.clearDb();
		pROps.clearDb();

		callBpaLoader();
		callBpa2Pr();
		// AppUtil.execute(AppUtil.GC_BPA_LOADER, execRootPath, dataRootPath
		// + "/RTS79.dat", dataRootPath + "/RTS79.swi");
		// AppUtil.execute(AppUtil.GC_BPA_2_PR, execRootPath, dataRootPath
		// + "/RTS79.dat", dataRootPath + "/RTS79.swi", dataRootPath
		// + "/RTS79.xml");

		printDbEntry(pROps);

		System.out
				.println("----------------------end testBpa2Pr-----------------------------");
	}

	@Test
	public void testStateSample() throws DbException {
		System.out
				.println("----------------------start testStateSample-----------------------------");
		bPAOps.clearDb();
		pROps.clearDb();

		callBpaLoader();
		callBpa2Pr();

		callStateSample();
		// AppUtil.execBuilder(AppUtil.GC_STATE_SAMPLE).addParam(execRootPath)
		// .addParam("全部").addParam("1").addParam("20").addParam("20")
		// .addParam("2000000").addParam("0.000000").addParam("0.990000")
		// .addParam("1.000000").addParam("100000").addParam("100000")
		// .addParam("1.000000").exec();

		// List<MemTable> tables = pROps.getTables();
		// for (MemTable table : tables) {
		// long count = pROps.getRecordCount(table);
		// if (count == 0)
		// continue;
		//
		// System.out.println(String.format("Table :%s, desc:%s, count:%d",
		// table.getName(), table.getDescription(), count));
		// List<String[]> rt = pROps.findAllRecords(table);
		// for (String[] records : rt) {
		// System.out.println(String.join(" ", records));
		// break;
		// }
		// }

		System.out
				.println("----------------------end testStateSample-----------------------------");
	}

	@Test
	public void testStateEstimate() throws DbException {
		System.out
				.println("----------------------start testStateEstimate-----------------------------");
		bPAOps.clearDb();
		pROps.clearDb();

		callBpaLoader();
		callBpa2Pr();

		callStateSample();
		callStateEstimate();

		printDbEntry(pROps);

		System.out
				.println("----------------------end testStateEstimate-----------------------------");
	}

	@Test
	public void testReliabilityIndex() throws DbException {
		System.out
				.println("----------------------start testReliabilityIndex-----------------------------");
		bPAOps.clearDb();
		pROps.clearDb();
		
		callBpaLoader();
		
		callBpa2Pr();
		callStateSample();
		callStateEstimate();
		callReliabilityIndex();

		printDbEntry(pROps);

		System.out
				.println("----------------------end testReliabilityIndex-----------------------------");
	}

}
