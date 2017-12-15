package com.znd.ei.ads.apl.reliability;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;

import java.nio.charset.Charset;

public class StateEstimateRequestHandler  extends ChannelInboundHandlerAdapter {
	

	private ByteBuf buffer;
	public StateEstimateRequestHandler(String msg) {

		buffer = Unpooled.copiedBuffer(msg, Charset.defaultCharset()); 

	}
	@Override
	public void channelActive(ChannelHandlerContext ctx) throws Exception {
		
	
		ctx.writeAndFlush(buffer);
		ctx.close();
	}

    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {         // Close the connection when an exception is raised.
         cause.printStackTrace();
        ctx.close();
     }	
}
