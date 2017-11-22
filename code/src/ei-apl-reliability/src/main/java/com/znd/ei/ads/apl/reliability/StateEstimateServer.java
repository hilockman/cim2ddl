package com.znd.ei.ads.apl.reliability;

import io.netty.bootstrap.Bootstrap;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelInitializer;
import io.netty.channel.ChannelOption;
import io.netty.channel.ChannelPipeline;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioSocketChannel;
import io.netty.util.concurrent.Future;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.ServerSocket;
import java.net.Socket;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.znd.ei.Utils;
import com.znd.ei.ads.apl.reliability.bean.DataReady;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.ads.apl.reliability.server.StateEstimateRemoteServer;
import com.znd.ei.memdb.reliabilty.domain.FState;

@Component
public class StateEstimateServer implements StateEstimateRemoteServer {
	private static final Logger logger = LoggerFactory
			.getLogger(StateEstimateServerProxy.class);

	@Value("${ads.appDir}")
	private String baseDir;
	
	private AppExecuteBuilder appExec;

	private ServerSocket socketServer;

	@Autowired
	private StateEstimateProperties properties;
	
	@PostConstruct
	public void init() {
		new Thread(
				() -> {
					if (AppUtil.checkAppIsRunning("GCStateEstimateServer")) {
						logger.info("***********StateEstimateServer is running ****************");
					} else {
						logger.info("***********StateEstimateServer start****************");
						appExec = AppUtil.execBuilder(baseDir
								+ "/GCStateEstimateServer");
						appExec.exec();
					}
				}).start();
		
		try {
			socketServer = new ServerSocket(properties.getListenPort());
		} catch (IOException e1) {
			e1.printStackTrace();
			return;
		}
		logger.info("Start state estimate listen on port:"
				+ properties.getListenPort());
	}

	@PreDestroy
	public void destory() {
		new Thread(
				() -> {
					if (appExec != null) {
						appExec.terminate();
						logger.info("***********StateEstimateServer exit****************");
					}

				}).start();
		
		try {
			socketServer.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	private void sendData(Object data) {
		Socket client = null;

		logger.info(String.format(
				"Try to connect to estimate server : ip:%s, port:%d",
				properties.getServerIp(), properties.getServerPort()));

		try {
			client = new Socket(properties.getServerIp(),
					properties.getServerPort());
		} catch (IOException e1) {
			logger.error("Fail to connect to server.");
			try {
				Thread.sleep(2000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		String sendData = Utils.toJSon(data);

		System.out.println("Send data :\n" + sendData);

		try {
			BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(
					client.getOutputStream()));
			bw.write(sendData);
			bw.flush();
			bw.close();
			client.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
	}
	
	private String readData(Socket s) {
		char cbuff[] = new char[1024];
		BufferedReader br;
		try {
			br = new BufferedReader(new InputStreamReader(s.getInputStream()));
			StringBuffer buffer = new StringBuffer();
			int size = 0;
			while ((size = br.read(cbuff, 0, cbuff.length)) != -1) {
				buffer.append(new String(cbuff, 0, size));
			}

			br.close();
			return buffer.toString();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return null;
	}

	
	private String waitForDataReadyResponse(final long timeout) {

		try {
			Socket s = socketServer.accept();
			logger.info("A client connected from " + s.getInetAddress()
					+ ", port : " + s.getPort());
			return readData(s);
		} catch (IOException e1) {
			logger.info("Socket server interrupte!");
		}

		return null;
	}
	
	@Override
	public String dataReady(DataReady setting) {

		initClient();
        // Configure the client.
        EventLoopGroup group = new NioEventLoopGroup();
        try {
            Bootstrap b = new Bootstrap();
            b.group(group)
             .channel(NioSocketChannel.class)
             .option(ChannelOption.TCP_NODELAY, true)
             .handler(new ChannelInitializer<SocketChannel>() {
                 @Override
                 public void initChannel(SocketChannel ch) throws Exception {
                     ChannelPipeline p = ch.pipeline();

                     //p.addLast(new LoggingHandler(LogLevel.INFO));
                     p.addLast(new StateEstimateReadyHandler(setting));
                 }
             });

            // Start the client.
            ChannelFuture f = b.connect(properties.getServerIp(), properties.getServerPort()).sync();

           
            // Wait until the connection is closed.
            f.channel().closeFuture().sync();
            
            
        } catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
            // Shut down the event loop to terminate all threads.
            group.shutdownGracefully();
        }
        
        return "";
	}

	private void initClient() {
	       EventLoopGroup group = new NioEventLoopGroup();
	        try {
	            Bootstrap b = new Bootstrap();
	            b.group(group)
	             .channel(NioSocketChannel.class)
	             .option(ChannelOption.TCP_NODELAY, true);

	            // Start the client.
	            ChannelFuture f = b.connect(properties.getServerIp(), properties.getServerPort()).sync();

	            // Wait until the connection is closed.
	            f.channel().closeFuture().sync();
	            
	            
	        } catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} 
	}

	@Override
	public StateEstimateResult execute(FState state) {
		// TODO Auto-generated method stub
		
		
		return null;
	}

}
