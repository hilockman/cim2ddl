package com.znd.reliability.server.impl;

import io.netty.bootstrap.Bootstrap;
import io.netty.bootstrap.ServerBootstrap;
import io.netty.buffer.ByteBuf;
import io.netty.buffer.Unpooled;
import io.netty.channel.Channel;
import io.netty.channel.ChannelFuture;
import io.netty.channel.ChannelFutureListener;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelInboundHandlerAdapter;
import io.netty.channel.ChannelInitializer;
import io.netty.channel.ChannelOption;
import io.netty.channel.ChannelPipeline;
import io.netty.channel.EventLoopGroup;
import io.netty.channel.nio.NioEventLoopGroup;
import io.netty.channel.socket.SocketChannel;
import io.netty.channel.socket.nio.NioServerSocketChannel;
import io.netty.channel.socket.nio.NioSocketChannel;
import io.netty.handler.codec.DelimiterBasedFrameDecoder;
import io.netty.handler.codec.Delimiters;
import io.netty.handler.codec.string.StringDecoder;
import io.netty.handler.codec.string.StringEncoder;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.nio.charset.Charset;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;
import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.ads.model.PRAdequacySetting;
import com.znd.bus.task.TaskQueue;
import com.znd.ei.Utils;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;
import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.mapper.FStateMIslandMapper;
import com.znd.reliability.mapper.FStateMapper;
import com.znd.reliability.mapper.FStateOvlAdMapper;
import com.znd.reliability.mapper.FStateOvlDevMapper;
import com.znd.reliability.model.Commands;
import com.znd.reliability.model.RequestDataReady;
import com.znd.reliability.model.RequestEstimate;
import com.znd.reliability.model.RequestJobFinished;
import com.znd.reliability.model.ResponseEstimate;
import com.znd.reliability.model.ResponseEstimate.Content;
import com.znd.reliability.server.ProxyServer;


public class ReliabilityProxyServer implements ProxyServer {
	
	private static final Logger logger = LoggerFactory
			.getLogger(ReliabilityProxyServer.class);

	
	private ReliabilityProperties properties;
	
	private FStateMapper fstateMapper;
	
	private FStateOvlAdMapper fstateOvlAdMapper;
	
	private FStateOvlDevMapper fstateOvlDevMapper;
	
	private FStateMIslandMapper fstateMIsland;
	
	private PRAdequacySetting setting;
	
	private String modelName;
	
	private TaskQueue<RequestEstimate> taskList;
	
	private long taskSize;
	
	/**
	 * 处理返回消息
	 * @author wangh
	 *
	 */
	public abstract class StateEstimateResponseHandler extends ChannelInboundHandlerAdapter {


		
		private Semaphore availableWorkers;
		private ReliabilityProxyServer server;
		private AtomicInteger currentTaskIndex;
		//private AtomicBoolean stopFlag;
		

	    public StateEstimateResponseHandler(AtomicInteger currentTaskIndex, ReliabilityProxyServer server,
				Semaphore availableWorkers) {
		
			this.availableWorkers = availableWorkers;
			this.server = server;
			this.currentTaskIndex = currentTaskIndex;


		}
	      
	    public abstract void closeParent();
	    
	    private void saveResult(ResponseEstimate result) {
	    	  	
    		Content c = result.getContent();
    		List<FState> fstates = c.getFState();
    		if (fstates != null && !fstates.isEmpty()) {
    			fstateMapper.insertList(fstates);
    		}
    		
    		List<FStateMIsland> islands = c.getFStateMIsland();
    		if (islands != null && !islands.isEmpty()) {
    			fstateMIsland.insertList(islands);
    		}
    		
    		 List<FStateOvlAd> ovlAds = c.getFStateOvlAd();
    		if (ovlAds != null && !ovlAds.isEmpty()) {
    			fstateOvlAdMapper.insertList(ovlAds);
    		}
    		
    		List<FStateOvlDev> ovlDevs = c.getFStateOvlDev();
    		if (ovlDevs != null && !ovlDevs.isEmpty()) {
    			fstateOvlDevMapper.insertList(ovlDevs);
    		}
    		
	    }
		@Override
	    public void channelRead(ChannelHandlerContext ctx, Object msg) { 
			String content = msg.toString();
			System.out.println("Rec from "+ctx.channel().remoteAddress()+"->Server :"+ content.length()+" size.");
			//System.out.println("Rec from "+ctx.channel().remoteAddress()+"->Server :"+ content);
			
	    	server.saveLog("Server response:\n" + content);
	    	
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
	    		
	    		saveResult(result);
	    		
	    		taskList.increaseGood();
	    		
//	    		synchronized(resultMap) {
//	    			resultMap.set(state.getFStateID(), result);
//	    		} 		 		
	    	} else if (content.contains(Commands.JOB_FINISHED)) {
	    		System.out.println("Received message : "+content);
				ctx.close();
	    	} else { //
	    		System.err.println("Unknown command:"+msg.toString());
	    		return;
	    	}

	    	
	    	RequestEstimate task = null;
			
			while (availableWorkers.tryAcquire()) {
				//发送下一次计算任务
				synchronized(taskList) {
					task = taskList.poll();
					
				}
				if (task != null) {

					String requestMsg = Utils.toJSon(task);					
					if (server != null) {
						server.saveLog("Client request:\n" + requestMsg);
						//server.simpleSendMessage(requestMsg);
						server.sendMessage(requestMsg);
					}
				} else {
					closeParent();
					break;
				}
				
				try {
					Thread.sleep(0);
				} catch (InterruptedException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
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
	

	

	
	public ReliabilityProxyServer(ReliabilityProperties properties,
			String modelName, 
			TaskQueue<RequestEstimate> taskList,
			FStateMapper fstateMapper,
			FStateOvlAdMapper fstateOvlAdMapper, 
			FStateOvlDevMapper fstateOvlDevMapper,
			FStateMIslandMapper fstateMIsland,
			PRAdequacySetting setting) {
		this.modelName = modelName;
		this.taskList = taskList;
		this.properties = properties;
		this.fstateMapper = fstateMapper;
		this.fstateOvlAdMapper = fstateOvlAdMapper;
		this.fstateOvlDevMapper = fstateOvlDevMapper;
		this.setting = setting;	
	}

	public ReliabilityProperties getProperties() {
		return properties;
	}


	public void setProperties(ReliabilityProperties properties) {
		this.properties = properties;
	}


	private ServerBootstrap localBootstrap;
	//private Channel responseChannel;

	private Bootstrap clientBootStrap;
	
	
	
	//private  ExecutorService threadPool = Executors.newCachedThreadPool();

	private Charset defaultCharset = Charset.forName("GBK");
	
//	private void stopJob() {
//		RequestJobFinished request = new RequestJobFinished();
//		String responseMsg = Utils.toJSon(request);
//		simpleSendMessage(responseMsg, null);
//	}
    
	
	/**
	 * 开始监听来自StateEstimate计算服务的消息
	 * @param buffer
	 * @param setting
	 * @param latch
	 * @param semaphore
	 * @throws InterruptedException
	 */
	private ChannelFuture startListen(
			) throws InterruptedException {
		Semaphore availableWorkers = new Semaphore(properties.getServerThread(), true);

		// Start the client.
		NioEventLoopGroup clientEventGroup = startClient();
				
		EventLoopGroup bossGroup = new NioEventLoopGroup(); // (1)
		EventLoopGroup workerGroup = new NioEventLoopGroup();	
		ReliabilityProxyServer server = this;
	
        taskSize =  taskList.size();
        AtomicBoolean closedFlag = new AtomicBoolean(false);      
        AtomicInteger currentTaskIndex = new AtomicInteger(0);
        
         ChannelInitializer<SocketChannel> chanelInit = new ChannelInitializer<SocketChannel>() { // 7
			@Override
			public void initChannel(SocketChannel ch)
					throws Exception {
		        ch.pipeline().addLast("framer", new DelimiterBasedFrameDecoder(8192, Delimiters.lineDelimiter()));
		        ch.pipeline().addLast("decoder", new StringDecoder(defaultCharset));
		        ch.pipeline().addLast("encoder", new StringEncoder(defaultCharset));		
		        StateEstimateResponseHandler handler = new StateEstimateResponseHandler(
						currentTaskIndex, 
						server, 
						availableWorkers) {
					
					@Override
					public void closeParent() {
						if (closedFlag.getAndSet(true))
							return;
															

				        Timer timer = new Timer(true);
				        
				        TimerTask task = new TimerTask() {												
								@Override
								public void run() {
							    	//判断任务是否完成
//									long resultSize = 0l;
//									taskList.goodCount();
//									synchronized(resultMap) {
//										resultSize = resultMap.size();
//									}
									
									if (taskList.goodCount() == taskSize) {
										System.out.println("Task is finished :"+modelName);
										RequestJobFinished request = new RequestJobFinished();
										String responseMsg = Utils.toJSon(request);
										simpleSendMessage(responseMsg);
										try {
											bossGroup.shutdownGracefully().sync();
											workerGroup.shutdownGracefully().sync();
											if (clientEventGroup != null)
											  clientEventGroup.shutdownGracefully().sync();
										} catch (InterruptedException e) {
											// TODO Auto-generated catch block
											e.printStackTrace();
										}									
										
										//serverFinishedLatch.countDown();
										timer.cancel();
									}
									
								}
							};
							
						
						timer.schedule(task, 0, 1000l);
					}
				};		        
				ch.pipeline().addLast(handler);
			}
		};
        
		localBootstrap = new ServerBootstrap();
		localBootstrap
				.group(bossGroup, workerGroup)
				// 4
				.channel(NioServerSocketChannel.class)
				.childHandler(chanelInit);
		
		
		ChannelFuture f = localBootstrap.bind(properties.getListenPort()).sync(); // 8
		logger.info(ReliabilityProxyServer.class.getName()
				+ " started and listen on " + f.channel().localAddress());
		//listenStartLatch.countDown();
		//responseChannel = f.channel();
		
		return f.channel().closeFuture();
	}
	
	/**
	 * 启动客服端，为发送后评估任务做准备 
	 * @return
	 */
	private NioEventLoopGroup startClient() {
	
		NioEventLoopGroup clientEventGroup = new NioEventLoopGroup();
	
		clientBootStrap = new Bootstrap();
		clientBootStrap.group(clientEventGroup)
         .channel(NioSocketChannel.class)
         .option(ChannelOption.TCP_NODELAY, true)
         .handler(new ChannelInitializer<SocketChannel>() {

             @Override
             public void initChannel(SocketChannel ch) throws Exception {
                 ChannelPipeline p = ch.pipeline();
            	 p.addLast("framer", new DelimiterBasedFrameDecoder(8192, Delimiters.lineDelimiter()));
                 p.addLast("decoder", new StringDecoder(defaultCharset));
                 p.addLast("encoder", new StringEncoder(defaultCharset));                    
//		                     p.addLast(new StateEstimateRequestHandler(msg));
             }
         });	
		return clientEventGroup;
	}


	@Override
	public void exec() {
		
	//client
	   	setting.setMultiThread(properties.getServerThread());
	   	saveLog("PRAdequacySetting = \n"+Utils.toJSon(setting));

		ChannelFuture future = null;
		try {
			future = startListen();			
		} catch (InterruptedException e1) {
			e1.printStackTrace();
			return ;
		}		
		
  	 
		RequestDataReady ready = new RequestDataReady();
		ready.setValue(String.valueOf(properties.getServerThread()));
		ready.getContent().setPRAdequacySetting(setting);
		
		String msg = Utils.toJSon(ready);
		sendMessage(msg);
		System.out.println("Wait for listen finished ...");
		try {
			future.sync(); // 9

			System.out.println("Listen chanel finished .");
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		
	}


	public void simpleSendMessage(String msg) {

		
		Socket ouputSocket = null;							
		//synchronized(sendFlag) {
		int reconnectCount = 0;
			while (ouputSocket == null) {

				reconnectCount++;
				try {
					ouputSocket = new Socket(properties.getServerIp(), properties.getServerPort());
					System.out.println(String.format(
							"Connected to server : ip:%s, port:%d",
							properties.getServerIp(), properties.getServerPort()));

				} catch (IOException e1) {
					System.err.println("Fail to connect to server, "+properties.getServerIp()+":"+properties.getServerPort());
					if (reconnectCount > 3) {
						System.err.println("Fail to reconnect to server, after try "+ reconnectCount);
						return;
					}
					try {
						Thread.sleep(2000);
					} catch (InterruptedException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}								
		//}
		System.out.println("Send data : size = " + msg.length());		
		try {
			BufferedWriter bw = new BufferedWriter(
					new OutputStreamWriter(
							ouputSocket.getOutputStream()));
			bw.write(msg);
			bw.flush();
			bw.close();
			ouputSocket.close();
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			//e1.printStackTrace();
			System.out.println("Fail to send data, prepare to send data again:"+ e1.getMessage());			
		}
	}

	public void sendMessage(String msg) {

		try {
			
			//connect to server
			ChannelFuture future = clientBootStrap.connect(properties.getServerIp(), properties.getServerPort()).sync();		
			future.addListener(new ChannelFutureListener() {
				
				@Override
				public void operationComplete(ChannelFuture future) throws Exception {
					if (future.isSuccess()) {
						//System.out.println("Connected to : ip = "+ properties.getServerIp()+", port = "+properties.getServerPort()+", send messag size = "+msg.length());
						
						Channel c = future.channel();
						
						ByteBuf buffer = Unpooled.copiedBuffer(msg, Charset.defaultCharset());							
						c.writeAndFlush(buffer);
						c.close();
					} else {
						System.err.println("Fail to connected to : ip = "+ properties.getServerIp()+", port = "+properties.getServerPort());
					}
				}
			});


			future.channel().closeFuture().sync();
			//System.out.println("Disconnect to : ip = "+ properties.getServerIp()+", port = "+properties.getServerPort());
								
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
	}


	
	private BufferedWriter bw;
	
	public void saveLog(String content) {
		if (bw == null) {
			try {
				File dir = new File(properties.getCachedDir());
				if (!dir.exists()) {
					dir.mkdirs();
				}
			OutputStreamWriter osw = new OutputStreamWriter(
					    new FileOutputStream(properties.getCachedDir()+"/estimateserver.log"), "UTF-8");
				bw = new BufferedWriter(osw);
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
						
		}

		try {
			bw.write(content+"\n");
			bw.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}



}
