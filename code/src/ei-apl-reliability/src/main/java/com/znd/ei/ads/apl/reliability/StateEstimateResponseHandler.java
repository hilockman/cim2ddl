package com.znd.ei.ads.apl.reliability;

import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;

import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
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
	private ListData<FState> taskList;
	private MapData<String, ResponseEstimate> resultMap;
	private int taskSize;
	private Semaphore semaphore;
	private StateEstimateServer server;
	private AtomicInteger currentTaskIndex;
	

    public StateEstimateResponseHandler(ListData<FState> taskList,
			MapData<String, ResponseEstimate> resultMap, Integer taskSize,
			AtomicInteger currentTaskIndex, StateEstimateServer server,
			Semaphore semaphore) {
		this.taskList = taskList;
		this.resultMap = resultMap;
		this.semaphore = semaphore;
		this.server = server;
		this.currentTaskIndex = currentTaskIndex;
		this.taskSize = taskSize;

	}
      
    public abstract void closeParent(Long delay, TimeUnit unit);
    
	@Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) { 
    	System.out.println("Rec from "+ctx.channel().remoteAddress()+"->Server :"+ msg.toString());
    	String content = msg.toString();
    	if (content.contains(Commands.DATA_READY)) {
    	} else if (content.contains(Commands.STATE_ESTIMATE)){
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
    		resultMap.set(String.valueOf(state.getFStateID()), result);
    		
    		//resultMap.set(String.valueOf(state.getStateNum()), result);
    		semaphore.release();
    		if (resultMap.size() == taskSize) {
    			System.out.println("Finishes State Estimate : taskSize ="+taskSize);
    			stopJob();
    			return;
    		}
    		
    		
    	} else if (content.contains(Commands.JOB_FINISHED)) {
    		System.out.println("Received message : "+content);
			ctx.close();
			closeParent(0l, TimeUnit.MINUTES);
    	} else { //
    		System.err.println("Unknown command:"+msg.toString());
    		return;
    	}
    	
		FState task = null;
		try { 
			while (semaphore.tryAcquire()) {
				//发送下一次计算任务
				synchronized(taskList) {
					task = taskList.lpop();
				}
				if (task != null) {
					RequestEstimate request = new RequestEstimate();
					
					request.getContent().getFState().add(task);
					String responseMsg = Utils.toJSon(request);
					
					//String responseMsg = fileToString(new File("D:\\GitHub\\cim2ddl\\documents\\交互\\4 response_estimate.json"));
					if (server != null)
						server.sendMessage(responseMsg);
				} else { //
					System.out.println("Task is finished :"+taskList.getKey());
					stopJob();
				}
			}
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
	
	private void stopJob() {
		RequestJobFinished request = new RequestJobFinished();
		String responseMsg = Utils.toJSon(request);
		if (server != null)
			server.sendMessage(responseMsg);
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
