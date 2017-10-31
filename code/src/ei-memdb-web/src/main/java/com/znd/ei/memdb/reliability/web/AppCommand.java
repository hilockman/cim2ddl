package com.znd.ei.memdb.reliability.web;

import java.util.logging.Logger;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.stereotype.Component;

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
	public AppCommand(FormJSonString control, ApplicationArguments args) {
		control.test();
	}

	
}
