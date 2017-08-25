package com.znd.ei.reliability.server.impl;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.UUID;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.ZhongND.RedisDF.Control.ControlList;
import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Service.DFService;
import com.znd.ei.Application;
import com.znd.ei.reliability.config.ReliabilityProperites;
import com.znd.ei.reliability.model.ComputingResult;
import com.znd.ei.reliability.server.TaskPublisher;

@Service
public class MCSampleService implements TaskPublisher {
	private static final Logger LOGGER = LoggerFactory.getLogger(MCSampleService.class);
	
	@Autowired
	private ReliabilityProperites properties;
	
	@Autowired
	private DFService dfService;

	@Autowired
	private RedisControl redisControl;
		
	@Autowired
	public MCSampleService()
	{
		
	}
	
	private List<String> formTestList() {
		int rcount = (int) Math.floor(100*Math.random());
		if (rcount == 0)
			rcount = 10;
		rcount += 1000;
		List<String> listValues = new ArrayList<String>();
		for (int i = 0; i < rcount; i++) {
			listValues.add("Task"+i);
		}
		return listValues;
	}
	@Override
	public ComputingResult run() {
		LOGGER.info("调用抽样算法");
		//调用抽样算法
		//上传模型
//		String strDBEntry = "MemDB.PR";
//		ADFService adfService = Service.getADFService();
//		RedisMemDB redisMemDB = adfService.registry("电网模型");
//		try {
//			redisMemDB.uploadModel("MemDB.PR");
//		} catch (RedisMemDBException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//		redisMemDB.pubMessage("PRupLoad", strDBEntry);
		
		//上传计算任务
		//创建队列

		

		if (!properties.getBusyLock().tryLock()) {
			return new ComputingResult("Fail", "Server is busy.");
		}

		List<String> listValue = formTestList();
		String messageType = properties.getMessageType();
		String messageKey = UUID.randomUUID().toString();
		LOGGER.info("GET List:"+messageType);
		ControlList list = redisControl.controlList(messageType);
		LOGGER.info("GETTEd List:"+messageType);

		list.rpush(messageKey, listValue);
		properties.getBusyLock().unlock();
		String log = String.format("%d Task uploaded.", listValue.size()); 
		LOGGER.info(log);		
		ComputingResult result = new ComputingResult("OK", log);
		return result;
	}




}
