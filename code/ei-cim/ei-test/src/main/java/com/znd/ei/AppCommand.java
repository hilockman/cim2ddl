package com.znd.ei;

import java.util.List;
import java.util.logging.Logger;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Component;

import com.ZhongND.RedisDF.db.DBAccess.Exception.JedisDBException;
import com.znd.ei.reliability.server.impl.MCSampleService;

/**
 * 
 * @author wangheng
 *
 *处理一些命令行参数
 *
 */
@Component
public class AppCommand  {
	static  Logger logger = Logger.getLogger(AppCommand.class.getName());
	
	private boolean exit = false;
	@Autowired
	public AppCommand(ApplicationContext context, ApplicationArguments args) {
		boolean create = args.containsOption("auto");
		if (create) {
			System.out.println("***********Enter auto test mode***********");

			List<String> strs = args.getOptionValues("times");
			int times = 10;
			if (strs != null && strs.size() > 0) {
				times = Integer.valueOf(strs.get(0));
				System.out.println("--times is "+times);
			} else {
				System.out.println("Default --times is 10");
			}
			
			MCSampleService service = context.getBean(MCSampleService.class);
			for (int i = 0; i < times; i++) {
				try {
					service.run(true, true, 1);
					System.out.println("++++++++++++Succeed "+(i+1)+" times, sum times is "+times);
				} catch (JedisDBException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			setExit(true);
			//System.exit(SpringApplication.exit(SpringApplication));
		} else {
			System.out.println("**************Enter manul mode , input url:http://localhost:8080/reliability/mcsample for test.");
			System.out.println("If you want to start auto test mode, start with command line --auto --times=<number>.");
		}
		

	}
	public boolean isExit() {
		return exit;
	}
	public void setExit(boolean exit) {
		this.exit = exit;
	}

	
}
