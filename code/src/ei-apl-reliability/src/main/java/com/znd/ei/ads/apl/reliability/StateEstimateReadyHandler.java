package com.znd.ei.ads.apl.reliability;

import io.netty.buffer.ByteBuf;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;

/**
 * 处理返回消息
 * @author wangh
 *
 */
public class StateEstimateReadyHandler extends ChannelInboundHandlerAdapter {


	private StateEstimateServer server;

	public StateEstimateReadyHandler(StateEstimateServer server) {
        this.server = server;
	}

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) { 
    	System.out.println(ctx.channel().remoteAddress()+"->Server :"+ msg.toString());
    	msg.toString();
        //ctx.write(msg); // (1)
       // ctx.flush(); // (2)
    }
    


    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {
        // Close the connection when an exception is raised.
        cause.printStackTrace();
        ctx.close();
    }

	@Override
	public void channelActive(ChannelHandlerContext ctx) throws Exception {
		ctx.channel();
		super.channelActive(ctx);
	}

}
