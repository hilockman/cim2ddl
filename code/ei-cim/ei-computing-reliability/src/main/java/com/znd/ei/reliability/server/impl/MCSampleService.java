package com.znd.ei.reliability.server.impl;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.UUID;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.ZhongND.RedisDF.exectueDF.ExectueDF;
import com.ZhongND.RedisDF.exectueDF.exectue.RedissonDBList;
import com.ZhongND.RedisDF.messageDF.RedissonPubManager;
import com.znd.ei.reliability.config.ReliabilityProperites;
import com.znd.ei.reliability.model.ComputingResult;
import com.znd.ei.reliability.server.TaskPublisher;

@Service
public class MCSampleService implements TaskPublisher {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(MCSampleService.class);

	private ReliabilityProperites properties;

	private DFService dFService;

	@Autowired
	public MCSampleService(DFService dFService, ReliabilityProperites properties)
			throws RedissonDBException {
		this.dFService = dFService;
		// redisControl = dFService.registry(properties.getAppName());
		this.properties = properties;
	}

	private ExectueDF createControl() throws RedissonDBException {
		return dFService.registry(properties.getAppName());
	}

	private List<String> formTestList(int count) {

		List<String> listValues = new ArrayList<String>();
		for (int i = 0; i < count; i++) {
			listValues.add("Task" + i);
		}
		return listValues;
	}

	private List<String> formTestList() {
		int rcount = (int) Math.floor(100 * Math.random());
		if (rcount == 0)
			rcount = 10;
		return formTestList(rcount);
	}

	public ComputingResult run(boolean lockFlag, boolean randomTask, int taskCount) throws RedissonDBException {
		LOGGER.info("Call Monte Carlo sample algorithm.");
		// 调用抽样算法
		// 上传模型
		// String strDBEntry = "MemDB.PR";
		// ADFService adfService = Service.getADFService();
		// RedisMemDB redisMemDB = adfService.registry("电网模型");
		// try {
		// redisMemDB.uploadModel("MemDB.PR");
		// } catch (RedisMemDBException e) {
		// // TODO Auto-generated catch block
		// e.printStackTrace();
		// }
		// redisMemDB.pubMessage("PRupLoad", strDBEntry);

		// 上传计算任务
		// 创建队列

		if (!lockFlag) {
			if (!properties.getBusyLock().tryLock()) {
				ComputingResult rt = new ComputingResult("Fail",
						"Server is busy.");
				LOGGER.warn(rt.toString());
				return rt;
			}
		} else {
			properties.getBusyLock().lock();
		}

		List<String> listValue = null;
		if (randomTask)
			listValue = formTestList();
		else
			listValue = formTestList(taskCount);
		
		String messageType = properties.getMessageType();
		//String messageKey = UUID.randomUUID().toString();
		String messageKey = messageType;
		LOGGER.info("GET List:" + messageType);
		 ExectueDF redisControl = createControl();
		 RedissonDBList list = redisControl.RedissonDBList();
		LOGGER.info("GETTEd List:" + messageType);

		Map<String, List<String>> objMap = new HashMap<String, List<String>>();
		objMap.put(messageKey, listValue);
		list.BatchRPUSH(objMap);
		list.closedSyncControlClient();
		properties.getBusyLock().unlock();
		String log = String.format("%d Task uploaded.", listValue.size());
		LOGGER.info(log);
		ComputingResult result = new ComputingResult("OK", log);
		RedissonPubManager msg = redisControl.RedissonPubManager();
		String strMessage = msg.setMessage(messageType, messageKey);
		msg.pubMessage(strMessage);
		msg.closed();
		return result;
	}

	@Override
	public ComputingResult run() throws RedissonDBException {
		return run(false, true, 0);
	}

}
