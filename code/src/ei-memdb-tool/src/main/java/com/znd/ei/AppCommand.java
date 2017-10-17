package com.znd.ei;

import java.util.logging.Level;
import java.util.logging.Logger;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.stereotype.Component;

import com.znd.ei.codegen.service.CheckService;
import com.znd.ei.codegen.service.ClassCreateService;
import com.znd.ei.memdb.DbEntryOperations;

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
	@Autowired
	public AppCommand(ClassCreateService classCreator, CheckService checkService, DbEntryOperations[] opss, ApplicationArguments args) {
		boolean create = args.containsOption("createCode");
		if (create) {
			logger.log(Level.INFO, "Create code");
			//classCreator.deleteAll();
			checkService.check(opss, classCreator.getRootLocation().toString());
			classCreator.init();
			classCreator.createClasses();
			
			//System.exit(SpringApplication.exit(SpringApplication));
		}
		
		if (args.containsOption("clear")) {
			//classCreator.deleteAll();
			classCreator.init();			
		}
		
		
		//System.out.println("arguments:"+args.toString());
		
		//List<String> files = args.getNonOptionArgs();
		// if run with "--debug logfile.txt" debug=true, files=["logfile.txt"]
	}

	
}
