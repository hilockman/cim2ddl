package com.znd.test;

import java.io.File;
import java.util.List;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MetaTable;
import com.znd.reliability.server.ReliabilityApl;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class ReliabilityAplTest {

	@Autowired
	ReliabilityApl apl;
	
	@Autowired
	private DbEntryOperations bPAOps;
	
	@Autowired
	private DbEntryOperations pROps;
	
	
	static private  String workingDir;
	
	{
		   workingDir = System.getProperty("user.dir");
		   workingDir += "/src/main/resources/RTS79/";
		   System.out.println("Current working directory : " + workingDir);	 	
		   if (!new File(workingDir).exists()) {
			   System.err.println("Current working directory does't exist : " + workingDir);
		   }
	}

	void print(DbEntryOperations ops) {
		List<MetaTable> tables = ops.getTables();
		for (MetaTable table : tables) {
			 long count = ops.getRecordCount(table);
			if (count == 0)
				continue;
			
			System.out.println(String.format("%s(%d)", table.getName(), count));
		}
	}
	
	@Test
	public void testLoadBPA() {
		File[] files = {new File(workingDir+"RTS79.dat"),new File(workingDir+"RTS79.swi") };
		apl.callBpaLoader(files);
		print(bPAOps);
	}
}
