package com.znd.ei.ads.apl.reliability;

import io.netty.bootstrap.Bootstrap;
import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelFutureListener;
import io.netty.channel.ChannelOption;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.nio.NioSocketChannel;

import java.net.InetSocketAddress;
import java.nio.charset.Charset;

import com.znd.ei.Utils;
import com.znd.ei.ads.apl.reliability.bean.RequestDataReady;
import com.znd.ei.ads.config.PRAdequacySetting;

public class StateEstimateClient {
	private ReliabilityCaseBuffer buffer;
	private PRAdequacySetting setting;
	private Bootstrap clientBootStrap;
	private StateEstimateReadyHandler responseHandler;
	private StateEstimateServer server;
	private StateEstimateProperties properties;
	
	public StateEstimateClient(StateEstimateServer server, ReliabilityCaseBuffer buffer, PRAdequacySetting setting)
	{
		this.buffer = buffer;
		this.setting = setting;
		this.server = server;
		
		responseHandler = new StateEstimateReadyHandler(buffer, server);
	}
	
	/**
	 * 连接计算服务
	 * @param ip
	 * @param port
	 */
	public void connect(String ip, Integer port) {
		EventLoopGroup group = new NioEventLoopGroup();
		try {
			clientBootStrap = new Bootstrap();
			clientBootStrap.group(group).channel(NioSocketChannel.class)
					.option(ChannelOption.TCP_NODELAY, true);

			// Start the client.
			InetSocketAddress addr = new InetSocketAddress(ip, port);
			clientBootStrap.remoteAddress(addr);

			ChannelFuture future = clientBootStrap.connect().sync();

			future.addListener(new ChannelFutureListener() { // 2
				@Override
				public void operationComplete(ChannelFuture future) {
					if (future.isSuccess()) { // 3

						server.getInPipline().addLast(
								new StateEstimateReadyHandler(buffer, server));
						
						RequestDataReady ready = new RequestDataReady();
						ready.setValue(properties.getServerThread());
						ready.getContent().setPRAdequacySetting(setting);

						// dataReady(future.channel(), ready);

						ByteBuf buffer = Unpooled.copiedBuffer(
								Utils.toJSon(setting), Charset.defaultCharset()); // 4

						future.channel().writeAndFlush(buffer);

						server.setOutChannel(future.channel());
						
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
	
	public void close() {
		
	}
}
