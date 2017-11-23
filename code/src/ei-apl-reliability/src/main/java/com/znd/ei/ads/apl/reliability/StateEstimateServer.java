package com.znd.ei.ads.apl.reliability;

import io.netty.bootstrap.Bootstrap;
import io.netty.bootstrap.ServerBootstrap;
import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelFutureListener;
import io.netty.channel.ChannelInitializer;
import io.netty.channel.ChannelOption;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioServerSocketChannel;
import io.netty.channel.socket.nio.NioSocketChannel;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.nio.charset.Charset;

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
			ServerBootstrap b = new ServerBootstrap();
			b.group(bossGroup, workerGroup)
					// 4
					.channel(NioServerSocketChannel.class)
					// 5
					.localAddress(
							new InetSocketAddress(properties.getListenPort())) // 6
					.childHandler(new ChannelInitializer<SocketChannel>() { // 7
								@Override
								public void initChannel(SocketChannel ch)
										throws Exception {
									ch.pipeline().addLast(
											new StateEstimateReadyHandler(
													server));
								}
							});

			ChannelFuture f = b.bind().sync(); // 8
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

	public StateEstimateResult execute(FState state) {

		return null;
	}

	@Override
	public void exec(PRAdequacySetting setting) {

		EventLoopGroup group = new NioEventLoopGroup();
		try {
			Bootstrap b = new Bootstrap();
			b.group(group).channel(NioSocketChannel.class)
					.option(ChannelOption.TCP_NODELAY, true);

			// Start the client.
			InetSocketAddress addr = new InetSocketAddress(
					properties.getServerIp(), properties.getServerPort());
			b.remoteAddress(addr);
			ChannelFuture future = b.connect().sync();

			future.addListener(new ChannelFutureListener() { // 2
				@Override
				public void operationComplete(ChannelFuture future) {
					if (future.isSuccess()) { // 3
						DataReady ready = new DataReady();
						ready.setValue(properties.getServerThread());
						ready.getContent().setPRAdequacySetting(setting);

						// dataReady(future.channel(), ready);

						ByteBuf buffer = Unpooled.copiedBuffer(
								Utils.toJSon(setting), Charset.defaultCharset()); // 4

						future.channel().writeAndFlush(buffer);

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
}
