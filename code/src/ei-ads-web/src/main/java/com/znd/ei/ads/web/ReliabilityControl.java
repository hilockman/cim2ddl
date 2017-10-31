package com.znd.ei.ads.web;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import com.ZhongND.RedisDF.exectueDF.ExectueDF;
import com.ZhongND.RedisDF.messageDF.RedissonPubManager;
import com.znd.ei.ads.config.AdsResult;
import com.znd.ei.ads.config.StateEstimateConfig;
import com.znd.ei.ads.config.StateSampleConfig;


@RestController
@RequestMapping(path = "/pr")
public class ReliabilityControl {


	@Autowired
	private ExectueDF executeDF;
	
	private void sendMessage(String contentCode, String key) {

		if (contentCode == null || contentCode.isEmpty()) {
			return;
		}
		RedissonPubManager msg = executeDF.RedissonPubManager();

		String strMessage = msg.setMessage(contentCode, key);

		
		
		try {
			msg.setMessage(contentCode, strMessage);
		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			msg.closed();
		}
	}

	@RequestMapping(path = "/stateSampleConfig", method = RequestMethod.GET)
	public @ResponseBody StateSampleConfig stateSampleConfig() {
		StateSampleConfig config = new StateSampleConfig();
		return config;
	}
	
	@RequestMapping(path = "/stateEstimateConfig", method = RequestMethod.GET)
	public @ResponseBody StateEstimateConfig stateEstimateConfig() {
		StateEstimateConfig config = new StateEstimateConfig();
		return config;
	}

	@RequestMapping(path = "/serverConfig", method = RequestMethod.GET)
	public @ResponseBody StateEstimateConfig serverConfig() {
		StateEstimateConfig config = new StateEstimateConfig();
		return config;
	}
	
	@RequestMapping(path = "/calcReliability", method = RequestMethod.POST)
	public @ResponseBody AdsResult calcReliability(StateEstimateConfig config) {
		System.out.println("calcReliability : config = "+config.toString());
		return  AdsResult.ok("accepted!");
	}
}
