package com.znd;

import static org.junit.Assert.assertTrue;

import java.io.File;
import java.util.Date;
import java.util.UUID;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.annotation.Repeat;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.apl.ReliabilityApl;
import com.znd.bus.common.buffer.CalcJobBuffer;
import com.znd.bus.common.model.CalcJob;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.utils.AppUtil;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class ReliabilityTest {
	@Autowired
	ReliabilityApl apl;
	
	@Autowired
	private DbEntryOperations bPAOps;
	
	@Autowired
	private DbEntryOperations pROps;
	
	
	private  String workingDir;
	private String modelName = "RTS79"; 	
	
	@Autowired
	private CalcJobBuffer calcJobMapper;
	
	
	
	@Autowired
	private ReliabilityProperties properties;	
	
	public ReliabilityTest() {
		   workingDir = System.getProperty("user.dir");
		   workingDir += "/src/main/resources/RTS79/";
		   System.out.println("Current working directory : " + workingDir);	 	
		   if (!new File(workingDir).exists()) {
			   System.err.println("Current working directory does't exist : " + workingDir);
			   System.exit(0);
		   }
	}

	
	File newFile(String posfix) {
		return new File(workingDir+modelName+"."+posfix);
	}

	@Test 
	public void testReliability() {
		CalcJob job = new CalcJob();
		job.setStart(new Date());
		job.setId(UUID.randomUUID().toString());
		job.setModelId(modelName);
		job.setName("test");
		PRAdequacySetting setting = new PRAdequacySetting();
		//setting.setMCSSimulateTime(20);
		CalcJob.setConfig(job, setting);
		calcJobMapper.save(job);
		

		{
			File[] files = {newFile("dat"),newFile("swi") };
			apl.callBpaLoader(files);
		}
		
		{
			File[] files = {newFile("dat"),newFile("swi"),newFile("xml") };
			apl.callBpa2Pr(files);
		}
		
		String appName  = "GCStateEstimateServer";
		Process p = null;
		if (!AppUtil.isRunning(appName))
		  p = AppUtil.executeWithoutLogger(properties.getAppDir()+"/"+appName);
		
		assertTrue(AppUtil.isRunning(appName));
				
		apl.reliability(job.getId());

		apl.reliabilityIndex(job.getId(), null);
		
		job.setEnd(new Date());
		job.setElapse(job.getEnd().getTime() - job.getStart().getTime());
		calcJobMapper.update(job);
		
		if (p != null)
			p.destroy();
		
	}
}
