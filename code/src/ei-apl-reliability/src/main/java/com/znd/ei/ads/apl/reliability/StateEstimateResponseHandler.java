package com.znd.ei.ads.apl.reliability;

import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;

import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.apl.reliability.bean.Commands;
import com.znd.ei.ads.apl.reliability.bean.RequestEstimate;
import com.znd.ei.ads.apl.reliability.bean.RequestJobFinished;
import com.znd.ei.ads.apl.reliability.bean.ResponseEstimate;
import com.znd.ei.memdb.reliabilty.domain.FState;

/**
 * 处理返回消息
 * @author wangh
 *
 */
public abstract class StateEstimateResponseHandler extends ChannelInboundHandlerAdapter {

	//private final ReentrantLock lock;   
	private ListData<RequestEstimate> taskList;
	private MapData<String, ResponseEstimate> resultMap;
	private long taskSize;
	private Semaphore availableWorkers;
	private StateEstimateProxyServer server;
	private AtomicInteger currentTaskIndex;
	//private AtomicBoolean stopFlag;
	

    public StateEstimateResponseHandler(ListData<RequestEstimate> taskList,
			MapData<String, ResponseEstimate> resultMap, Integer taskSize,
			AtomicInteger currentTaskIndex, StateEstimateProxyServer server,
			Semaphore availableWorkers) {
		this.taskList = taskList;
		this.resultMap = resultMap;
		this.availableWorkers = availableWorkers;
		this.server = server;
		this.currentTaskIndex = currentTaskIndex;
		this.taskSize = (long) taskSize.intValue();
		//this.stopFlag = stopFlag;

	}
      
    public abstract void closeParent();
    
    
	@Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) { 
    	System.out.println("Rec from "+ctx.channel().remoteAddress()+"->Server :"+ msg.toString());
    	String content = msg.toString();
    //	server.saveLog("Server response:\n" + content);
    	
    	if (content.contains(Commands.DATA_READY)) {
    	} else if (content.contains(Commands.STATE_ESTIMATE)){
    		availableWorkers.release();
    		
    		int index = currentTaskIndex.get();
    		ResponseEstimate result = Utils.toObject(content, ResponseEstimate.class);
    		if (result == null) {
    			System.err.println("Fail to parse result");
    			ctx.close();
    			return;
    		} else {
    			System.out.println("Received result : currentTaskIndex "+index+", sum = "+ taskSize);
    			index = currentTaskIndex.incrementAndGet();
    		}
    		
    		FState state = result.getContent().getFState().get(0);  		  		
    		synchronized(resultMap) {
    			resultMap.set(String.valueOf(state.getFStateID()), result);
    		}
    		 		
    	} else if (content.contains(Commands.JOB_FINISHED)) {
    		System.out.println("Received message : "+content);
			ctx.close();
    	} else { //
    		System.err.println("Unknown command:"+msg.toString());
    		return;
    	}

    	
    	RequestEstimate task = null;
		try { 
			while (availableWorkers.tryAcquire()) {
				//发送下一次计算任务
				synchronized(taskList) {
					task = taskList.lpop();
				}
				if (task != null) {

					String requestMsg = Utils.toJSon(task);					
					if (server != null) {
						server.saveLog("Server request:\n" + requestMsg);
						server.simpleSendMessage(requestMsg, null);
					}
				} else {
					closeParent();
					break;
				}
			}
		} catch (ACPException e) {
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
