package com.znd.ei.ads.apl.reliability;

import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;

import com.znd.ei.ads.apl.reliability.bean.DataReady;

public class StateEstimateReadyHandler extends ChannelInboundHandlerAdapter {

	private DataReady setting;
	public StateEstimateReadyHandler(DataReady setting) {
         this.setting = setting;
	}

    @Override
    public void channelActive(ChannelHandlerContext ctx) {
        ctx.writeAndFlush(setting);
    }

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) {
        ctx.write(msg);
    }

    @Override
    public void channelReadComplete(ChannelHandlerContext ctx) {
       ctx.flush();
    }

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {
        // Close the connection when an exception is raised.
        cause.printStackTrace();
        ctx.close();
    }

}
