package com.znd.test;

import static org.junit.Assert.*;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.utils.AppUtil;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class AppUtilTest {

	@Autowired
	private ReliabilityProperties properties;
	@Test
	public void startGCStateEstimateServer() {
		String appName  = "GCStateEstimateServer";
		Process p = AppUtil.execute(properties.getAppDir()+"/"+appName);
		
		assertTrue(AppUtil.isRunning(appName));
		
		p.destroy();
		
	}
}
