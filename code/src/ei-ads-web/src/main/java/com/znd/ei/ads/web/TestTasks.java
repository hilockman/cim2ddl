package com.znd.ei.ads.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.znd.ei.Utils;
import com.znd.ei.ads.AdsServer;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ACPResult;
import com.znd.ei.ads.acp.ConnectionFactory;

@Controller
@RequestMapping(path = "/test")
public class TestTasks {
	
	@Autowired
	ConnectionFactory connectionFactory;
	


	@GetMapping()
	public @ResponseBody ACPResult home() {
		
		return new ACPResult("OK", String.format("url:"+"tasks  uploadBPA testRPC"));
	}
	
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
	
	@GetMapping(path = "/uploadBPA")
	public @ResponseBody ACPResult uploadBPA() {
		int count = 100;
		TaskConfig config = new TaskConfig(count);
		String content = Utils.toString(config);
		
		try {
			connectionFactory.publishData("create_BPAModel", content);
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		};
		return new ACPResult("OK", String.format("created %s tasks.", count));
	}

	@GetMapping(path = "/testRPC")
	public @ResponseBody String testRPC() {
		AdsServer server = null;
		
		server = connectionFactory.getServer();


		int count = 100;
		TaskConfig config = new TaskConfig(count);
		String content = Utils.toString(config);
		
		try {
			return server.publish("create_BPAModel", content);
		} catch (ACPException e) {
			return "Error : "+e.getMessage();
		}
	}
	
	@GetMapping(path = "/serverInfos")
	public @ResponseBody String getServerInfos() {
		AdsServer server = null;
		
		server = connectionFactory.getServer();

		String content = null;
		try {
			content = server.publish(AdsServer.ADS_GET_SERVERINFOS, "");
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
		}
		
		return content;
	}
}
