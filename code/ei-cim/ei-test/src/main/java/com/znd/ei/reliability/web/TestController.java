package com.znd.ei.reliability.web;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.znd.ei.ads.acp.ACPResult;
import com.znd.ei.reliability.server.impl.MCSampleService;

@Controller
@RequestMapping(path = "/test")
public class TestController {

	static private Logger log = LoggerFactory.getLogger(TestController.class); 
	@Autowired
	private MCSampleService mCSampleService;
	
	@GetMapping
	public @ResponseBody String logo() {
		return "Reliability";
	}

	@GetMapping(path = "/mcsample")
	public @ResponseBody ACPResult mcsample(@RequestParam Integer times, @RequestParam Integer taskCount) {
		try {
			int fail = 0;
			int succeed = 0;
			log.info("test/mcsample,times="+times+", taskCount="+taskCount);
			long startMili=System.currentTimeMillis();// 当前时间对应的毫秒数
			for (int i = 0; i < times; i++) {
				log.info("Sample index:"+i);
				ACPResult rt = mCSampleService.run(true, false, taskCount);
				if (rt.getCode().equalsIgnoreCase("OK")) {
					succeed++;
				} else
					fail++;
				log.info("Finished sample index:"+i);
			}
			
			long endMili=System.currentTimeMillis();		
			
			return new ACPResult("OK", String.format("Finished %d, fail %d, succeed %d, comsumed time %d ms."
					, times, fail, succeed,endMili-startMili));
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return new ACPResult("Error", "Failt to Sample");
		}
	}
	
}
