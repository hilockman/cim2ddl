package com.znd.ei.ads.apl.reliability;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;

//@Apl(desc = "测试处理列表")
public class TestProcessTasks {
	@AplFunction
	public void processTask(@In("created_TestTasks") ListData testTask) {
	
		System.out.println("Receive tasks.");
		String str = null;
		int count = 0;
		try {
			while ((str = testTask.lpop()) != null) {
				System.out.println("Process Task :"+str+", count="+(++count)+", key="+testTask.getKey());
			}
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
}
