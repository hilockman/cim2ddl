package com.znd.ei.ads.apl.reliability;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;

import java.nio.charset.Charset;

import com.znd.ei.Utils;
import com.znd.ei.ads.apl.reliability.bean.RequestDataReady;

public class StateEstimateRequestHandler  extends ChannelInboundHandlerAdapter {
	

	private ByteBuf buffer;
	public StateEstimateRequestHandler(RequestDataReady ready) {

		buffer = Unpooled.copiedBuffer(
				Utils.toJSon(ready), Charset.defaultCharset()); 

	}
	@Override
	public void channelActive(ChannelHandlerContext ctx) throws Exception {
		
	
		ctx.writeAndFlush(buffer);
	}
	
    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) {
       System.out.println("Received message :"+msg);
    }

   @Override
    public void channelReadComplete(ChannelHandlerContext ctx) {
      // ctx.flush();
    }
	
    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {         // Close the connection when an exception is raised.
         cause.printStackTrace();
        ctx.close();
     }	
}
