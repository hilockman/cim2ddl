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
import com.znd.ei.memdb.MemTable;
import com.znd.ei.memdb.bpa.dao.ACLineRepository;
import com.znd.ei.memdb.bpa.domain.BpaDat_ACLine;

@RunWith(SpringRunner.class)
@SpringBootTest
public class AppUtilTest {

	String dataRootPath = "E:/data/RTS79";
	String execRootPath = "E:/ZNDCWare/bin_x64";
	@Autowired
	private ACLineRepository repository;

	@Autowired
	private DbEntryOperations bPAOps;

	@Autowired
	private DbEntryOperations pROps;

	@Test
	public void testBpaLoader() throws Exception {
		System.out
				.println("----------------------start testBpaLoader-----------------------------");
		AppUtil.execute(AppUtil.GC_BPA_LOADER, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi");
		Iterable<BpaDat_ACLine> states = repository.findAll();
		int n = 0;
		for (BpaDat_ACLine state : states) {
			System.out.println(state);
			n++;
		}
		System.out.println("Load BpaDat_ACLine:" + n);

		List<MemTable> tables = bPAOps.getTables();
		for (MemTable table : tables) {
			long count = bPAOps.getRecordCount(table);
			if (count == 0)
				continue;

			System.out.println(String.format("Table :%s, desc:%s, count:%d",
					table.getName(), table.getDescription(), count));
			List<String[]> rt = bPAOps.findAllRecords(table);
			for (String[] records : rt) {
				System.out.println(String.join(" ", records));
				break;
			}
		}
		System.out
				.println("----------------------end testBpaLoader-----------------------------");

	}

	@Test
	public void testBpa2Pr() throws DbException {
		System.out
				.println("----------------------start testBpa2Pr-----------------------------");
		bPAOps.clearDb();
		pROps.clearDb();

		AppUtil.execute(AppUtil.GC_BPA_LOADER, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi");
		AppUtil.execute(AppUtil.GC_BPA_2_PR, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi", dataRootPath
				+ "/RTS79.xml");

		List<MemTable> tables = pROps.getTables();
		for (MemTable table : tables) {
			long count = pROps.getRecordCount(table);
			if (count == 0)
				continue;

			System.out.println(String.format("Table :%s, desc:%s, count:%d",
					table.getName(), table.getDescription(), count));
			List<String[]> rt = pROps.findAllRecords(table);
			for (String[] records : rt) {
				System.out.println(String.join(" ", records));
				break;
			}
		}

		System.out
				.println("----------------------end testBpa2Pr-----------------------------");
	}

	@Test
	public void testStateSample() throws DbException {
		System.out
				.println("----------------------start testStateSample-----------------------------");
		bPAOps.clearDb();
		pROps.clearDb();

		AppUtil.execute(AppUtil.GC_BPA_LOADER, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi");
		AppUtil.execute(AppUtil.GC_BPA_2_PR, execRootPath, dataRootPath
				+ "/RTS79.dat", dataRootPath + "/RTS79.swi", dataRootPath
				+ "/RTS79.xml");
		AppUtil.execBuilder(AppUtil.GC_STATE_SAMPLE).addParam(execRootPath)
				.addParam("全部").addParam("1").addParam("20").addParam("20")
				.addParam("2000000").addParam("0.000000").addParam("0.990000")
				.addParam("1.000000").addParam("100000").addParam("100000")
				.addParam("1.000000").exec();

		List<MemTable> tables = pROps.getTables();
		for (MemTable table : tables) {
			long count = pROps.getRecordCount(table);
			if (count == 0)
				continue;

			System.out.println(String.format("Table :%s, desc:%s, count:%d",
					table.getName(), table.getDescription(), count));
			List<String[]> rt = pROps.findAllRecords(table);
			for (String[] records : rt) {
				System.out.println(String.join(" ", records));
				break;
			}
		}

		System.out
				.println("----------------------end testStateSample-----------------------------");
	}

}
