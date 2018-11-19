package com.znd;

import java.io.File;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.apl.ReliabilityApl;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.reliability.config.ReliabilityProperties;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class MemoryLoadTest {

	@Autowired
	ReliabilityApl apl;
	
	@Autowired
	private DbEntryOperations bPAOps;
	
	@Autowired
	private DbEntryOperations pROps;
	
	
	private  String workingDir;
	private String modelName = "RTS79"; 
	
	@Autowired
	private ReliabilityProperties properties;	
	
	public MemoryLoadTest() {
		   workingDir = System.getProperty("user.dir");
		   workingDir += "/src/main/resources/RTS79/";
		   System.out.println("Current working directory : " + workingDir);	 	
		   if (!new File(workingDir).exists()) {
			   System.err.println("Current working directory does't exist : " + workingDir);
			   System.exit(0);
		   }
	}

//	void print(DbEntryOperations ops) {
//		List<MetaTable> tables = ops.getTables();
//		int sum = 0;
//		for (MetaTable table : tables) {
//			 long count = ops.getRecordCount(table);
//			if (count == 0)
//				continue;
//			
//			sum += count;
//			System.out.println(String.format("%s(%d)", table.getName(), count));
//		}
//		String log = String.format("%s db load , record sum = %d > 0.", ops.getName(), sum);
//		System.out.println(log);
//		Assert.assertTrue(log, sum > 0);
//	}
	
	File newFile(String posfix) {
		return new File(workingDir+modelName+"."+posfix);
	}
	
	
	@Test
	public void testLoadBPA() {
		File[] files = {newFile("dat"),newFile("swi") };
		apl.callBpaLoader(files);
		TestUtils.print(bPAOps);
	}
	
	@Test
	public void testLoadPr() {
		{
			File[] files = {newFile("dat"),newFile("swi") };
			apl.callBpaLoader(files);
		}
		
		{
			File[] files = {newFile("dat"),newFile("swi"),newFile("xml") };
			apl.callBpa2Pr(files);
		}
		TestUtils.print(pROps);
	}
	

}
