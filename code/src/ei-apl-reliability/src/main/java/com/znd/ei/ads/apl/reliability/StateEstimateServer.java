package com.znd.ei.ads.apl.reliability;

import io.netty.bootstrap.Bootstrap;
import io.netty.bootstrap.ServerBootstrap;
import io.netty.channel.Channel;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelFutureListener;
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
import io.netty.util.CharsetUtil;

import java.util.concurrent.CountDownLatch;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.znd.ei.ads.apl.reliability.bean.RequestDataReady;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
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
	private Channel responseChannel;
	private Channel requestChannel;
	private Bootstrap clientBootStrap;
	
	@PostConstruct
	public void init() {
		new Thread(new Runnable() {

			@Override
			public void run() {
				if (AppUtil.checkAppIsRunning("GCStateEstimateServer")) {
					logger.info("***********StateEstimateServer is running ****************");

				} else {

					String path = baseDir + "/GCStateEstimateServer";
					logger.info("***********StateEstimateServer start****************"+path);
					appExec = AppUtil.execBuilder(path);
					appExec.exec();
				}

			}
		}).start();
		
		


	}



	private void start(ReliabilityCaseBuffer buffer, PRAdequacySetting setting, CountDownLatch latch) throws InterruptedException {
		EventLoopGroup bossGroup = new NioEventLoopGroup(); // (1)
		EventLoopGroup workerGroup = new NioEventLoopGroup();
		StateEstimateServer server = this;
		
		try {
			localBootstrap = new ServerBootstrap();
			localBootstrap
					.group(bossGroup, workerGroup)
					// 4
					.channel(NioServerSocketChannel.class)
					.childHandler(new ChannelInitializer<SocketChannel>() { // 7
								@Override
								public void initChannel(SocketChannel ch)
										throws Exception {
									ch.pipeline().addLast("encoder",
											new StringEncoder(CharsetUtil.UTF_8));
									ch.pipeline().addLast("decoder",
											new StringDecoder(CharsetUtil.UTF_8));
									latch.await();
									ch.pipeline().addLast(new StateEstimateResponseHandler(buffer, server));
								}
							});
			
			
			ChannelFuture f = localBootstrap.bind(properties.getListenPort()).sync(); // 8
			logger.info(StateEstimateServer.class.getName()
					+ " started and listen on " + f.channel().localAddress());
			responseChannel = f.channel();
			f.channel().closeFuture().sync(); // 9
		} finally {
			bossGroup.shutdownGracefully().sync(); // 10
			workerGroup.shutdownGracefully().sync(); // 10
		}

	}

	@PreDestroy
	public void destory() {
		new Thread(
				() -> {
					if (appExec != null) {
						appExec.terminate();
						logger.info("***********StateEstimateServer exit****************");
					}

					responseChannel.close();
				}).start();

	}



	public StateEstimateResult execute(FState state) {

		return null;
	}


	@Override
	public void exec(ReliabilityCaseBuffer buffer, PRAdequacySetting setting) {

		CountDownLatch latch = new CountDownLatch(1);
		new Thread(new Runnable() {
			
			@Override
			public void run() {
				try {
					start(buffer, setting, latch);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}).start();
		
		

		
		new Thread(new Runnable() {
			
			@Override
			public void run() {
							
				RequestDataReady ready = new RequestDataReady();
				ready.setValue(properties.getServerThread());
				ready.getContent().setPRAdequacySetting(setting);
				
				EventLoopGroup group = new NioEventLoopGroup();	
				try {
					clientBootStrap = new Bootstrap();
					clientBootStrap.group(group)
		             .channel(NioSocketChannel.class)
		             .option(ChannelOption.TCP_NODELAY, true)
		             .handler(new ChannelInitializer<SocketChannel>() {
		                 @Override
		                 public void initChannel(SocketChannel ch) throws Exception {
		                     ChannelPipeline p = ch.pipeline();
		                	 p.addLast("framer", new DelimiterBasedFrameDecoder(8192, Delimiters.lineDelimiter()));
		                     p.addLast("decoder", new StringDecoder());
		                     p.addLast("encoder", new StringEncoder());
		                     p.addLast(new StateEstimateRequestHandler(ready));
		                 }
		             });
					
					
//					.group(group)
//					        .channel(NioSocketChannel.class)
//							.option(ChannelOption.TCP_NODELAY, true);
//					clientBootStrap.handler(new ChannelInitializer<SocketChannel>() {
//						@Override
//						public void initChannel(SocketChannel ch) throws Exception {
////							ch.pipeline().addLast("encoder",
////									new StringEncoder(CharsetUtil.UTF_8));
////							ch.pipeline().addLast("decoder",
////									new StringDecoder(CharsetUtil.UTF_8));
//							ch.pipeline().addLast(new StateEstimateRequestHandler(ready));
//						}
//					});
					
					// Start the client.
					
					ChannelFuture future = clientBootStrap.connect("127.0.0.1", 8950).sync();
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
	
					// Wait until the connection is closed.
					requestChannel = future.channel();					
					latch.countDown();
					
					future.channel().closeFuture().sync();
					System.out.println("与EstimateServer的链接关闭了。");
					
					responseChannel.close().sync();
					System.out.println("监听端口已关闭。");
					
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} finally {
					// Shut down the event loop to terminate all threads.
					group.shutdownGracefully();
				}
			}
		}).start();
		
	}


	public Channel getRequestChannel() {
		return requestChannel;
	}
}
