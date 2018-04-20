package com.znd.test;

import org.junit.FixMethodOrder;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.MethodSorters;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import com.znd.buffer.common.model.AdsNode;
import com.znd.controller.AdsController;

@RunWith(SpringRunner.class)
@FixMethodOrder(MethodSorters.JVM)//指定测试方法按定义的顺序执行
@SpringBootTest
public class AdsControllerTest {
	@Autowired
	private AdsController controller;
	
	@Test
	public void testGetNode() {
		AdsNode node = controller.getNode();
		System.out.println("Node name = "+node.getName()+", url = "+node.getUrl()+", update = "+node.getLastUpdate());
	}
}
