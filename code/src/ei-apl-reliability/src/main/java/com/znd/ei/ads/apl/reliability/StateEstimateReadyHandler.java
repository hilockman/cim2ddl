package com.znd.ei.ads.apl.reliability;

import java.util.concurrent.Semaphore;

import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.apl.reliability.bean.Commands;
import com.znd.ei.ads.apl.reliability.bean.RequestEstimate;
import com.znd.ei.ads.apl.reliability.bean.ResponseEstimate;
import com.znd.ei.memdb.reliabilty.domain.FState;

import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;

/**
 * 处理返回消息
 * @author wangh
 *
 */
public class StateEstimateReadyHandler extends ChannelInboundHandlerAdapter {

	private final Semaphore semaphore ;
	//private final ReentrantLock lock;   
	private ListData<FState> taskList;
	MapData<String, ResponseEstimate> resultMap;
	public StateEstimateReadyHandler(ReliabilityCaseBuffer buffer, StateEstimateServer server) {    
        taskList = buffer.getList(ReliabilityCaseBuffer.ESTIMATE_TASK_LIST);
        resultMap = buffer.getMap(ReliabilityCaseBuffer.ESTIMATE_RESULT_MAP);
        semaphore = new Semaphore(server.getProperties().getServerThread(), true);
	}

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) { 
    	System.out.println(ctx.channel().remoteAddress()+"->Server :"+ msg.toString());
    	String content = msg.toString();
    	if (content.contains(Commands.DATA_READY)) {

    	} else if (content.contains(Commands.STATE_ESTIMATE)){
    		
    		ResponseEstimate result = Utils.toObject(content, ResponseEstimate.class);
    		FState state = result.getContent().getFState();
    		resultMap.set(String.valueOf(state.getStateNum()), result);
    		semaphore.release();
    	} else { //
    		System.out.println("Unknown command:"+msg.toString());
    		return;
    	}
    	
		FState task = null;
		try { 
			while (semaphore.tryAcquire()) {
				//发送下一次计算任务
				task = taskList.lpop();
				if (task != null) {
					RequestEstimate request = new RequestEstimate();
					
					request.getContent().setFState(task);
					String responseMsg = Utils.toJSon(request);
					ByteBuf buf = Unpooled.copiedBuffer(responseMsg.getBytes());
					ctx.writeAndFlush(buf);
				}
			}
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

    }
    


    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {
        // Close the connection when an exception is raised.
        cause.printStackTrace();
        ctx.close();
    }

	@Override
	public void channelActive(ChannelHandlerContext ctx) throws Exception {
		super.channelActive(ctx);
	}


}
