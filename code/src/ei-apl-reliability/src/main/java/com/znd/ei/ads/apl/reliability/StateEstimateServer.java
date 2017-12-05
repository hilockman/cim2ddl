package com.znd.ei.ads.apl.reliability;

import io.netty.bootstrap.Bootstrap;
import io.netty.bootstrap.ServerBootstrap;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelFutureListener;
import io.netty.channel.ChannelHandler;
import io.netty.channel.ChannelInitializer;
import io.netty.channel.ChannelOption;
import io.netty.channel.ChannelPipeline;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioServerSocketChannel;
import io.netty.channel.socket.nio.NioSocketChannel;
import io.netty.handler.codec.DelimiterBasedFrameDecoder;
import io.netty.handler.codec.Delimiters;
import io.netty.handler.codec.string.StringDecoder;
import io.netty.handler.codec.string.StringEncoder;

import java.io.BufferedWriter;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.charset.Charset;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.znd.ei.Utils;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.apl.reliability.bean.RequestDataReady;
import com.znd.ei.ads.apl.reliability.bean.ResponseEstimate;
import com.znd.ei.ads.apl.reliability.server.StateEstimateRemoteServer;
import com.znd.ei.ads.config.PRAdequacySetting;
import com.znd.ei.memdb.reliabilty.domain.FState;

@Component
public class StateEstimateServer implements StateEstimateRemoteServer {
	private static final Logger logger = LoggerFactory
			.getLogger(StateEstimateServer.class);

	@Value("${ads.appDir}")
	private String baseDir;

	private AppExecuteBuilder appExec;

	@Autowired
	private StateEstimateProperties properties;


	public StateEstimateProperties getProperties() {
		return properties;
	}


	public void setProperties(StateEstimateProperties properties) {
		this.properties = properties;
	}


	private ServerBootstrap localBootstrap;
	//private Channel responseChannel;

	private Bootstrap clientBootStrap;
	
	private  ExecutorService threadPool = Executors.newCachedThreadPool();

	private Charset defaultCharset = Charset.forName("GBK");
	/**
	 * 开始监听来自StateEstimate计算服务的消息
	 * @param buffer
	 * @param setting
	 * @param latch
	 * @param semaphore
	 * @throws InterruptedException
	 */
	private void startListen(ReliabilityCaseBuffer buffer,
			PRAdequacySetting setting,
			CountDownLatch serverFinishedLatch) throws InterruptedException {
		Semaphore semaphore = new Semaphore(properties.getServerThread(), true);

		EventLoopGroup bossGroup = new NioEventLoopGroup(); // (1)
		EventLoopGroup workerGroup = new NioEventLoopGroup();
		StateEstimateServer server = this;
		ListData<FState> taskList;
		MapData<String, ResponseEstimate> resultMap;
        taskList = buffer.getList(ReliabilityCaseBuffer.ESTIMATE_TASK_LIST);
        resultMap = buffer.getMap(ReliabilityCaseBuffer.ESTIMATE_RESULT_MAP);
        Integer taskSize = taskList.getSize();
        AtomicBoolean closedFlag = new AtomicBoolean(false);
        
        AtomicInteger currentTaskIndex = new AtomicInteger(0);
        



        ChannelInitializer<SocketChannel> chanelInit = new ChannelInitializer<SocketChannel>() { // 7
			@Override
			public void initChannel(SocketChannel ch)
					throws Exception {
		        ch.pipeline().addLast("framer", new DelimiterBasedFrameDecoder(8192, Delimiters.lineDelimiter()));
		        ch.pipeline().addLast("decoder", new StringDecoder(defaultCharset));
		        ch.pipeline().addLast("encoder", new StringEncoder(defaultCharset));		
		        StateEstimateResponseHandler handler = new StateEstimateResponseHandler(taskList, 
						resultMap, 
						taskSize, 
						currentTaskIndex, 
						server, 
						semaphore) {
					
					@Override
					public void closeParent(Long delay, TimeUnit unit) {
						if (closedFlag.getAndSet(true))
							return;
																
						unit = ((unit == null) ? TimeUnit.MILLISECONDS : unit);
						delay = ((delay 
								== null)? 0 : delay);

		               TimerTask task = new TimerTask() {												
							@Override
							public void run() {
								try {
									bossGroup.shutdownGracefully().sync();									
									workerGroup.shutdownGracefully().sync();
									serverFinishedLatch.countDown();
								} catch (InterruptedException e) {
									// TODO Auto-generated catch block
									e.printStackTrace();
								} 
							}
						};
						new Timer(true).schedule(task, unit.toMillis(delay));
					}
				};		        
				ch.pipeline().addLast(handler);
			}
		};
        
		//try {
			localBootstrap = new ServerBootstrap();
			localBootstrap
					.group(bossGroup, workerGroup)
					// 4
					.channel(NioServerSocketChannel.class)
					.childHandler(chanelInit);
			
			
			ChannelFuture f = localBootstrap.bind(properties.getListenPort()).sync(); // 8
			logger.info(StateEstimateServer.class.getName()
					+ " started and listen on " + f.channel().localAddress());
			//responseChannel = f.channel();
			f.channel().closeFuture().sync(); // 9
			//responseChannel.close().sync();
			System.out.println("监听端口已关闭。");
		//}
//		finally {
//			bossGroup.shutdownGracefully().sync(); // 10
//			workerGroup.shutdownGracefully().sync(); // 10
//		}

	}

	@PreDestroy
	public void destory() {
//		new Thread(
//				() -> {
//					if (appExec != null) {
//						appExec.terminate();
//						logger.info("***********StateEstimateServer exit****************");
//					}
//
//					//responseChannel.close();
//				}).start();

	}



//	 private ChannelHandler decoder;
//	 private ChannelHandler encoder;
//	 private ChannelHandler framer;
//	private EventLoopGroup clientEventGroup;

	@Override
	public void exec(ReliabilityCaseBuffer buffer, PRAdequacySetting setting) {
	//client
	   	
	   	 
		
		CountDownLatch serverFinishedLatch = new CountDownLatch(1);
		
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				try {
					startListen(buffer, setting,serverFinishedLatch);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}).start();
		
		
   	 
		RequestDataReady ready = new RequestDataReady();
		ready.setValue(String.valueOf(properties.getServerThread()));
		ready.getContent().setPRAdequacySetting(setting);
		
		String msg = Utils.toJSon(ready);
		simpleSendMessage(msg);
		System.out.println("Wait for server finished ...");
		try {
			serverFinishedLatch.await();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

	private Byte sendFlag = new Byte((byte) 0);
	
	public void simpleSendMessage(String msg) {
		System.out.println("Send data :\n" + msg);
		Socket ouputSocket = null;							synchronized(sendFlag) {
			while (ouputSocket == null) {
				System.out.println(String.format(
						"try to connect to server : ip:%s, port:%d",
						properties.getServerIp(), properties.getServerPort()));

				try {
					ouputSocket = new Socket(properties.getServerIp(), properties.getServerPort());
				} catch (IOException e1) {
					System.err.println("Fail to connect to server.");
					try {
						Thread.sleep(2000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}								
		}
				
		try {
			BufferedWriter bw = new BufferedWriter(
					new OutputStreamWriter(
							ouputSocket.getOutputStream()));
			bw.write(msg);
			bw.flush();
			bw.close();
			ouputSocket.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			//e1.printStackTrace();
			System.out.println("Fail to send data, prepare to send data again:"+ e1.getMessage());			
		}
	}

	public void sendMessage(String msg) {
		threadPool.execute(new Runnable() {
			
			@Override
			public void run() {
										
				NioEventLoopGroup clientEventGroup = new NioEventLoopGroup();
				try {
					clientBootStrap = new Bootstrap();
					clientBootStrap.group(clientEventGroup)
		             .channel(NioSocketChannel.class)
		             .option(ChannelOption.TCP_NODELAY, true)
		             .handler(new ChannelInitializer<SocketChannel>() {

		                 @Override
		                 public void initChannel(SocketChannel ch) throws Exception {
		                     ChannelPipeline p = ch.pipeline();
		                	 p.addLast("framer", new DelimiterBasedFrameDecoder(8192, Delimiters.lineDelimiter()));
		                     p.addLast("decoder", new StringDecoder(defaultCharset));
		                     p.addLast("encoder", new StringEncoder(defaultCharset));
		                     p.addLast(new StateEstimateRequestHandler(msg));
		                 }
		             });
					
			
					// Start the client.				
					ChannelFuture future = clientBootStrap.connect(properties.getServerIp(), properties.getServerPort()).sync();
					future.addListener(new ChannelFutureListener() {
						
						@Override
						public void operationComplete(ChannelFuture future) throws Exception {
							if (future.isSuccess()) {
								System.out.println("Connected to : ip = "+ properties.getServerIp()+", port = "+properties.getServerPort());
							} else {
								System.err.println("Fail to connected to : ip = "+ properties.getServerIp()+", port = "+properties.getServerPort());
							}
						}
					});
	
	
					future.channel().closeFuture().sync();
					System.out.println("Disconnect to : ip = "+ properties.getServerIp()+", port = "+properties.getServerPort());
										
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} finally {
					// Shut down the event loop to terminate all threads.
					clientEventGroup.shutdownGracefully();
				}
			}
		});
	}


	



}
