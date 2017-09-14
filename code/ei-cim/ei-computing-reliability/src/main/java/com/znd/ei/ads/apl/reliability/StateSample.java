package com.znd.ei.ads.apl.reliability;

import java.util.ArrayList;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ListOperations;
import com.znd.ei.ads.adf.ContentCodeDefines;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.apl.AppTemplate;
import com.znd.ei.ads.apl.annotations.Apl;

@Apl(value = "StateSample", inputCC = "created_PRSettings")
public class StateSample extends AppTemplate {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(AppTemplate.class);

	

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

	public void run(boolean lockFlag, boolean randomTask, int taskCount) throws ACPException {
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



		List<String> listValue = null;
		if (randomTask)
			listValue = formTestList();
		else
			listValue = formTestList(taskCount);
		
		
		ListData data = new ListData();
		data.setName("PRSettings");
		ListOperations listOperations = getConnectionFactory().getListOperations();
		writeDataField(ContentCodeDefines.created_PRSettings, data, listOperations);
		data.setContent(listValue);
		LOGGER.info("%d Task uploaded.", listValue.size());
//		ACPResult result = null;
//		 try {
//			 String log = String.format("%d Task uploaded.", listValue.size());
//				
//			result = new ACPResult(ACPResult.SUCCESS_CODE, log);
//			listOperations.write(data);
//			LOGGER.info(log);
//			
//		} catch (ACPException e) {
//			e.printStackTrace();
//			String log = String.format("Fail to %d Task uploaded.", listValue.size());
//			result = new ACPResult(ACPResult.FAIL_CODE, log);
//			LOGGER.error(log);
//		}
		 
//		 return result;
		
	}
}
