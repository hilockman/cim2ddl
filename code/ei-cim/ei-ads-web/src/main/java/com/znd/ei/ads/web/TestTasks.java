package com.znd.ei.ads.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.google.gson.Gson;
import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ACPResult;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.StringDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.StringData;

@Controller
@RequestMapping(path = "/test")
public class TestTasks {
	
	@Autowired
	ConnectionFactory connectionFactory;
	
	@GetMapping(path = "/tasks")
	public @ResponseBody ACPResult tasks() {
		int count = 100;
		TaskConfig config = new TaskConfig(count);
		String content = Utils.toString(config);
		
		try {
			connectionFactory.publishData("create_TestTasks", content);
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		};
		return new ACPResult("OK", String.format("created %s tasks.", count));
	}
}
