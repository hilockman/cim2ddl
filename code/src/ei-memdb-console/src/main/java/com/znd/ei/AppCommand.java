package com.znd.ei;

import java.util.logging.Logger;

import javax.annotation.PostConstruct;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Component;

import com.znd.ei.tcptest.TCPClient;
import com.znd.ei.tcptest.TCPServer;
import com.znd.ei.tcptest.TcpTestProperties;

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
	private ApplicationContext context;
	
	private TcpTestProperties properties;
	@Autowired
	public AppCommand(ApplicationArguments args, TcpTestProperties properties) {
		this.properties = properties;
		
//		String strs[] = args.getSourceArgs();
//		if (strs.length == 0) {
//			System.out.println("--testTcp for testing tcp. ");
//			return;
//		}
	}

	
	@PostConstruct
	public void init() {
//		if (args.containsOption("testTcp")) {
//			context.getBean(requiredType)
//		}
//			
		System.out.println("Setting : "+properties);

		TCPServer server = context.getBean(TCPServer.class);
		server.start();
		
		TCPClient client = context.getBean(TCPClient.class);
		client.start();
	}
	
}
