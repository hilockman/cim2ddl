package com.znd.ei.reliability.server;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.UUID;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Service.DFService;

@Service
public class MCSampleService implements Computing {
	private ReliabilityProperites properties;
	

	@Autowired
	private DFService dfService;

	@Autowired
	RedisControl redisControl;
	
	@Autowired
	public MCSampleService(ReliabilityProperites properties)
	{
		this.properties = properties;
	}
	
	
	@Override
	public void run() {
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

		List<String> listValue = new ArrayList<String>(Arrays.asList("1","2","3"));
		
		String messageType = "Reliability";
		UUID messageKey = UUID.randomUUID();
		redisControl.controlList(messageType).lpush(messageKey.toString(), listValue);
	}




}
