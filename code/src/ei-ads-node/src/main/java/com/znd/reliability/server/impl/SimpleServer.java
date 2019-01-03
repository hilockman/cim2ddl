package com.znd.reliability.server.impl;

import java.util.Date;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;
import java.util.concurrent.Semaphore;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

import org.redisson.api.RCountDownLatch;
import org.redisson.api.RTopic;
import org.redisson.api.RedissonClient;
import org.redisson.api.listener.MessageListener;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.ads.model.dto.PRAdequacySetting;
import com.znd.apl.ReliabilityApl.JobUpdater;
import com.znd.bus.task.AQueue;
import com.znd.ei.Utils;
import com.znd.exception.AplException;
import com.znd.reliability.config.ReliabilityProperties;
import com.znd.reliability.model.Commands;
import com.znd.reliability.model.RequestDataReady;
import com.znd.reliability.model.RequestEstimate;
import com.znd.reliability.model.RequestJobFinished;
import com.znd.reliability.model.ResponseEstimate;
import com.znd.reliability.server.PrBufferServer;
import com.znd.reliability.server.ReliabilityProxyServer;

public class SimpleServer implements ReliabilityProxyServer {
	private static final Logger logger = LoggerFactory
			.getLogger(SimpleServer.class);

	private AQueue<RequestEstimate> taskList;
	private ReliabilityProperties properties;
	private PrBufferServer bufferServer;
	private PRAdequacySetting setting;
//	private Channel requestChannel;
//	private Channel responseChannel;
	private RTopic<String> requestTopic;
	private RTopic<String> responseTopic;
	
	private RTopic<String> startTopic;
	
	private RTopic<String> replyTopic;

	private AtomicInteger sendCount = new AtomicInteger(0);
	private AtomicInteger receiveCount = new AtomicInteger(0);
	
	private Semaphore availableWorkers;
	
	private AtomicBoolean sendQuit = new AtomicBoolean(false);
	private CountDownLatch quit = new CountDownLatch(1);
	
//	private Integer taskSize;
	
	private ExecutorService threadPool = Utils.threadPool();
	
	//private BlockingQueue<String> sendTasks = new ArrayBlockingQueue<>(8); 
	private BlockingQueue<String> sendTasks = new LinkedBlockingQueue<>();
	//private BlockingQueue<ResponseEstimate> resultList = new LinkedBlockingQueue<>();


	public SimpleServer(ReliabilityProperties properties,
			AQueue<RequestEstimate> taskList, PrBufferServer bufferServer,
			PRAdequacySetting setting, RedissonClient localClient) {
//		this.taskSize = taskList.size();
		this.availableWorkers = new Semaphore(properties.getServerThread(), true);
		logger.info("server thread: "+properties.getServerThread());
		this.taskList = taskList;
		this.properties = properties;
		this.bufferServer = bufferServer;
		this.setting = setting;	
		requestTopic = localClient.getTopic("stateEstimateTopic", new org.redisson.client.codec.StringCodec());
		responseTopic = localClient.getTopic("stateEstimateResponseTopic", new org.redisson.client.codec.StringCodec());
		responseTopic.addListener(new MessageListener<String>() {

			@Override
			public void onMessage(String channel, String msg) {
				//threadPool.execute(()->{response(msg);});
				//response(msg);
				processResult(msg);				
		
			}
			
		});
		

		
		startTopic = localClient.getTopic("startStateEstimateTopic", new org.redisson.client.codec.StringCodec());
		replyTopic = localClient.getTopic("replyStateEstimateTopic", new org.redisson.client.codec.StringCodec());
		
		replyTopic.addListener(new MessageListener<String>() {

			@Override
			public void onMessage(String channel, String msg) {
				
				if (msg.contains(Commands.DATA_READY)){
					dataReady();
				} else if (msg.contains(Commands.JOB_FINISHED)) {
					jobFinnished();
				} else {
					processError(msg);
				}
				
			}

			
		});


	}
	
	private void jobFinnished()
	{
		System.out.println("Job finished.");
		
	}
	
	private void processError(String msg) {
		System.err.println("Receive error : "+msg);
	}
	private void processResult(String msg) {
		if (msg.contains(Commands.STATE_ESTIMATE)) {
			threadPool.execute(()->{
					availableWorkers.release();
//					taskList.decreaseLeft();
					ResponseEstimate result = Utils.toObject(msg, ResponseEstimate.class);
		    		if (result == null) {
		    			System.err.println("Fail to parse result");
		    			return;
		    		} else {
		    			
		    			//System.out.println("Received result : "+msg);
						bufferServer.saveResult(result);
						receiveCount.incrementAndGet();

//		    			System.out.println("Received result : currentTaskIndex "+receiveCount.getAndIncrement()+", sum = "+ taskSize+", result : "+bufferServer.getResultSize());
		    		}						
			});			
		} else if (msg.contains(Commands.DATA_READY)){
			dataReady();
		} else if (msg.contains(Commands.JOB_FINISHED)) {
			jobFinnished();
		} else {
			processError(msg);
		}
		

	}
	private void dataReady() {
		//produce send task
		//get task from common buffer, put to send queue
		threadPool.execute(()->{
				//while(availableWorkers.tryAcquire(3, TimeUnit.MINUTES)) {
				while(true) {
					try {
						availableWorkers.acquire();
					} catch (Exception e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
						break;
					}
					RequestEstimate task = taskList.poll();				
					if (task != null) {
						//System.out.println("Send task : "+ index.incrementAndGet());
						//requestTopic.publish(Utils.toJSon(task));
						try {
    						sendTasks.put(Utils.toJSon(task));
						} catch (Throwable e) {
							e.printStackTrace();
							System.out.println("Fail to send task :" + e.getMessage());
						}
					} else {
						sendQuit.set(true);
						
						break;
					}
					
				}
			
		});
		
		//consume send task 
        //send task to client
		threadPool.execute(()->{
			try {
				//while(availableWorkers.tryAcquire(3, TimeUnit.MINUTES)) {
				while(true) {
					//availableWorkers.acquire();
					String task = sendTasks.poll();
					if (task != null) {
//						System.out.println("Send task : "+ task);
						requestTopic.publish(task);
						sendCount.incrementAndGet();
					} else if (sendQuit.get()){
						System.out.println("Task send thread quit.");
						quit.countDown();
						break;
					}
					
				}
			} catch (Throwable e) {
				e.printStackTrace();
				System.err.println("Fail to send task :" + e.getMessage());
			}
		
		});
		
		

		
//		//save result 
//		threadPool.execute(()->{
//				
//				while(true) {
//					ResponseEstimate result = resultList.poll();	
//					if (result != null) {
//						bufferServer.saveResult(result);
//						updater.decrease();
//						
//					} else {
//						if (sendQuit.get() && (sendCount.get() == receiveCount.get())) {
//							break;
//						}
//						try {
//							Thread.sleep(0);
//						} catch (InterruptedException e) {
//							e.printStackTrace();
//						}
//					}
//				}
//		
//		});
	}

	
	private void start() {
		RequestDataReady ready = new RequestDataReady();
		ready.setValue(String.valueOf(properties.getServerThread()));
		ready.getContent().setPRAdequacySetting(setting);
		
		String msg = Utils.toJSon(ready);
		logger.info("publish topic = {}, message={}", "startStateEstimateTopic",  msg);
		startTopic.publish(msg);
	}
	@Override
	public void exec() {
		
		
		try {

			Date start = new Date();
			long max_time_out = 15;
			TimeUnit unit = TimeUnit.MINUTES;
			
			start();

			
//			while (!taskList.isEmpty()) {
//				try {
//											
//					long elapsed = new Date().getTime() - start.getTime();
//					if (elapsed > max_time_out) {
//						throw new AplException("Task timeout : elapsed = "+elapsed);
//						
//					}
//					Thread.sleep(1000);					
//				} catch (InterruptedException e) {
//					e.printStackTrace();
//				}
//			}
			
			logger.info("Wait for task finished : timeout {}, unit {}", max_time_out, unit);
			quit.await(max_time_out, unit);
			while (sendCount.get() != receiveCount.get()) {
					try {									
						long elapsed = new Date().getTime() - start.getTime();
						if (elapsed > unit.toMillis(max_time_out)) {
						    throw new AplException("Task timeout : elapsed = "+elapsed);				
						}
					    Thread.sleep(1000);					
					} catch (InterruptedException e) {
					   e.printStackTrace();
					}
			}
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			RequestJobFinished request = new RequestJobFinished();
			String requesMsg = Utils.toJSon(request);
			logger.info("publish topic = {}, message={}", "startStateEstimateTopic",  requesMsg);	
			startTopic.publish(requesMsg);
			
			responseTopic.removeAllListeners();
			replyTopic.removeAllListeners();
		}
		
		//requestTopic.publish("stop");
	}	

}
