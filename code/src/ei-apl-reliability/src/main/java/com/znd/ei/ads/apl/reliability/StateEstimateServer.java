package com.znd.ei.ads.apl.reliability;

import java.net.InetSocketAddress;
import java.nio.charset.Charset;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

import com.znd.ei.Utils;
import com.znd.ei.ads.apl.reliability.bean.RequestDataReady;
import com.znd.ei.ads.apl.reliability.bean.StateEstimateResult;
import com.znd.ei.ads.apl.reliability.server.StateEstimateRemoteServer;
import com.znd.ei.ads.config.PRAdequacySetting;
import com.znd.ei.memdb.reliabilty.domain.FState;

import io.netty.bootstrap.Bootstrap;
import io.netty.bootstrap.ServerBootstrap;
import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
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
	private ChannelPipeline inPipline;
	private Channel inChannel;
	private Channel outChannel;
	private Bootstrap clientBootStrap;
	
	@PostConstruct
	public void init() {
		new Thread(new Runnable() {

			@Override
			public void run() {
				if (AppUtil.checkAppIsRunning("GCStateEstimateServer")) {
					logger.info("***********StateEstimateServer is running ****************");
				} else {
					logger.info("***********StateEstimateServer start****************");
					appExec = AppUtil.execBuilder(baseDir
							+ "/GCStateEstimateServer");
					appExec.exec();
				}
				try {
					start();
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		}).start();

	}



	private void start() throws InterruptedException {
		EventLoopGroup bossGroup = new NioEventLoopGroup(); // (1)
		EventLoopGroup workerGroup = new NioEventLoopGroup();

		// NioEventLoopGroup group = new NioEventLoopGroup(); // 3
		StateEstimateServer server = this;
		try {
			localBootstrap = new ServerBootstrap();
			localBootstrap
					.group(bossGroup, workerGroup)
					// 4
					.channel(NioServerSocketChannel.class)
					// 5
					.localAddress(
							new InetSocketAddress(properties.getListenPort())) // 6
					.childHandler(new ChannelInitializer<SocketChannel>() { // 7
								@Override
								public void initChannel(SocketChannel ch)
										throws Exception {
									
								}
							});

			ChannelFuture f = localBootstrap.bind().sync(); // 8
			logger.info(StateEstimateServer.class.getName()
					+ " started and listen on " + f.channel().localAddress());

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

				}).start();

	}



	public StateEstimateResult execute(FState state) {

		return null;
	}


	@Override
	public void exec(ReliabilityCaseBuffer buffer, PRAdequacySetting setting) {

		StateEstimateServer server = this;
		EventLoopGroup group = new NioEventLoopGroup();
		try {
			clientBootStrap = new Bootstrap();
			clientBootStrap.group(group).channel(NioSocketChannel.class)
					.option(ChannelOption.TCP_NODELAY, true);

			// Start the client.
			InetSocketAddress addr = new InetSocketAddress(
					properties.getServerIp(), properties.getServerPort());
			clientBootStrap.remoteAddress(addr);

			ChannelFuture future = clientBootStrap.connect().sync();

			future.addListener(new ChannelFutureListener() { // 2
				@Override
				public void operationComplete(ChannelFuture future) {
					if (future.isSuccess()) { // 3

						inPipline.addLast(
								new StateEstimateReadyHandler(buffer, server));
						
						RequestDataReady ready = new RequestDataReady();
						ready.setValue(properties.getServerThread());
						ready.getContent().setPRAdequacySetting(setting);

						// dataReady(future.channel(), ready);

						ByteBuf buffer = Unpooled.copiedBuffer(
								Utils.toJSon(setting), Charset.defaultCharset()); // 4

						future.channel().writeAndFlush(buffer);

						setOutChannel(future.channel());
					} else {
						Throwable cause = future.cause();
						cause.printStackTrace();
					}
				}
			});

			// Wait until the connection is closed.
			future.channel().closeFuture().sync();

		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			// Shut down the event loop to terminate all threads.
			group.shutdownGracefully();
		}

	}

	public void setOutChannel(Channel channel) {
		this.outChannel = channel;
	}



	@Override
	public void stop() {
		if (outChannel != null) {
			outChannel.close();
		}
	}



	public Channel getInChannel() {
		return inChannel;
	}



	public void setInChannel(Channel inChannel) {
		this.inChannel = inChannel;
	}



	public ChannelPipeline getInPipline() {
		return inPipline;
	}



	public void setInPipline(ChannelPipeline inPipline) {
		this.inPipline = inPipline;
	}

}
