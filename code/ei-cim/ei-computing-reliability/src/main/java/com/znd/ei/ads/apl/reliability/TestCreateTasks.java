package com.znd.ei.ads.apl.reliability;

import java.util.ArrayList;
import java.util.List;

import com.google.gson.Gson;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.apl.AppTemplate;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;
import com.znd.ei.ads.web.TaskConfig;

@Apl(desc = "测试创建任务列表")
public class TestCreateTasks extends AppTemplate {

	@AplFunction
	public void createTask(@In("create_TestTasks") StringData configData, @Out("created_TestTasks") ListData testTask) {
	
		String str = configData.getContent();
		Gson gson = new Gson();
		TaskConfig config = gson.fromJson(str, TaskConfig.class);
		
		System.out.println("Start create task :"+config.getCount());
		List<String> tasks = new ArrayList<String>();
		for (int i = 0; i < config.getCount(); i++) {
			String str1 = new String("Task"+i);
			tasks.add(str1);
		}
		
		testTask.setContent(tasks);
	}
}
