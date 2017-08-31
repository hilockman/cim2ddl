package com.znd.ei.reliability.server.impl;

import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Control.Content.ControlList;
import com.ZhongND.RedisDF.Control.Content.PubMessage;
import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.db.DBAccess.Exception.JedisDBException;
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
			throws JedisDBException {
		this.dFService = dFService;
		// redisControl = dFService.registry(properties.getAppName());
		this.properties = properties;
	}

	private RedisControl createControl() throws JedisDBException {
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

	public ComputingResult run(boolean lockFlag, boolean randomTask, int taskCount) throws JedisDBException {
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
		String messageKey = UUID.randomUUID().toString();
		LOGGER.info("GET List:" + messageType);
		RedisControl redisControl = createControl();
		ControlList list = redisControl.controlList();
		LOGGER.info("GETTEd List:" + messageType);

		list.rpush(messageKey, listValue);
		properties.getBusyLock().unlock();
		String log = String.format("%d Task uploaded.", listValue.size());
		LOGGER.info(log);
		ComputingResult result = new ComputingResult("OK", log);
		PubMessage msg = redisControl.pubMessage();
		String strMessage = msg.setMessage(messageType, messageKey);
		msg.pubMessage(strMessage);
		return result;
	}

	@Override
	public ComputingResult run() throws JedisDBException {
		return run(false, true, 0);
	}

}
