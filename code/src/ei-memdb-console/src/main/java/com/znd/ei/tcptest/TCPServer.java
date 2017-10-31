package com.znd.ei.tcptest;

import java.io.IOException;
import java.net.ServerSocket;
import java.util.concurrent.ExecutorService;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class TCPServer {
	@Autowired
	TcpTestProperties properties;

	ServerSocket serverSocket;

	@Autowired
	private ExecutorService threadPool;


	public void start() {
		Integer port = 6666;

		port = properties.getHostPort();
		System.out.println("Start server, listen on port:" + port);

		try {
			serverSocket = new ServerSocket(port);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}


	
	

	
	public void execute(SocketProccess p) throws IOException {


			threadPool.execute(() -> p.process(serverSocket));
		
		
		
	}







}
