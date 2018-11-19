package com.znd.bus.server.defaults;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.CopyOnWriteArrayList;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelConfig;
import com.znd.bus.channel.ChannelMessage;
import com.znd.bus.channel.ChannelRegistry;
import com.znd.bus.channel.ChannelType;
import com.znd.bus.channel.Listener;
import com.znd.bus.log.BufferLogger;
import com.znd.bus.log.BufferLoggerFactory;
import com.znd.bus.server.AdapterService;
import com.znd.bus.server.BusException;
import com.znd.bus.server.BusService;
import com.znd.bus.server.Topic;
import com.znd.bus.server.VerbEnum;
import com.znd.bus.server.VerbTypeEnum;
import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.HeaderType;
import com.znd.bus.server.message.MessageBase;
import com.znd.bus.server.message.ReplyCodeEnum;
import com.znd.bus.server.message.ReplyType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;
import com.znd.ei.Utils;

public class DefaultBusService extends BusService {
	private final Logger logger = LoggerFactory.getLogger(DefaultBusService.class);
	private BufferLogger bufferLogger = BufferLoggerFactory.getLogger(DefaultBusService.class);
	
	private ChannelRegistry channelRegistry;
	private final Map<VerbEnum, VerbTypeEnum> verbTypeMap =  new HashMap<>();
	//private final Map<String, ResponseMessageType> syncResultMap = new HashMap<>();
	private final Map<String, RequestInfo> requestInfoMap = new HashMap<>();
	
	private final Map<String, AdapterService> adapterMap = new HashMap<>();
	
	
	
	/*
	 * <topic-name, adatper>， 总线输出消息处理适配器
	 */
	private final Map<String, List<AdapterService>> outAdapters = new HashMap<>();
	

	public class RequestInfo {
		public CountDownLatch latch;
		public String replyAddress;
		public String messageID;
		public ResponseMessageType result;
		
		public RequestInfo(CountDownLatch latch, String replyAddress, String messageID) {
			this.latch = latch;
			this.replyAddress = replyAddress;		
			this.messageID = messageID;
		}
	}
	
	public DefaultBusService(ChannelRegistry channelRegistry) {
		
		this.channelRegistry = channelRegistry;
		
		verbTypeMap.put(VerbEnum.get, VerbTypeEnum.Request);
		
		verbTypeMap.put(VerbEnum.reply, VerbTypeEnum.Response);
		
		verbTypeMap.put(VerbEnum.create, VerbTypeEnum.Tansaction);
		verbTypeMap.put(VerbEnum.change, VerbTypeEnum.Tansaction);
		verbTypeMap.put(VerbEnum.delete, VerbTypeEnum.Tansaction);
		verbTypeMap.put(VerbEnum.close, VerbTypeEnum.Tansaction);
		verbTypeMap.put(VerbEnum.cancel, VerbTypeEnum.Tansaction);
		verbTypeMap.put(VerbEnum.execute, VerbTypeEnum.Tansaction);
		
		verbTypeMap.put(VerbEnum.created, VerbTypeEnum.Event);
		verbTypeMap.put(VerbEnum.changed, VerbTypeEnum.Event);
		verbTypeMap.put(VerbEnum.deleted, VerbTypeEnum.Event);
		verbTypeMap.put(VerbEnum.closed, VerbTypeEnum.Event);
		verbTypeMap.put(VerbEnum.canceled, VerbTypeEnum.Event);
		verbTypeMap.put(VerbEnum.executed, VerbTypeEnum.Event);
	}
	

	
	private ResponseMessageType sendMessage(MessageBase msgBase) {
		HeaderType header = msgBase.getHeader();

		String channelName = Topic.formName(header.getVerb(), header.getNoun());
		Channel c = channelRegistry.getChannel(channelName);
		if (c == null) {
			ChannelConfig config = new ChannelConfig(channelName, ChannelType.SendOnly);
			c  = channelRegistry.addChannel(config);
		}
			
		ChannelMessage msg = new ChannelMessage(channelName, Utils.toJSon(msgBase));
		c.send(msg);
		
		ResponseMessageType r = new ResponseMessageType.Builder(
				new HeaderType.Builder(VerbEnum.reply, header.getNoun())
				.correlationID(header.getCorrelationID())
				.messageID(header.getMessageID())
				.build())
				.reply(new ReplyType.Builder().build()).build();
		r.setHeader(header);
		return r;
	}
	
	@Override
	public ResponseMessageType publish(EventMessageType event) {
		bufferLogger.debug("Bus receive event: {} .", DefaultBusService.toString(event));
		return sendMessage(event);
	}

	@Override
	public ResponseMessageType request(RequestMessageType request) {
		bufferLogger.debug("Bus receive request: {} .", DefaultBusService.toString(request));
		HeaderType header = request.getHeader();
    	RequestInfo info = null;
		if (header.getMessageID() == null || header.getMessageID().isEmpty()) {
			header.setMessageID(Utils.randomKey());
		}
		String key = header.getMessageID();
		
		
		if (header.isSync()) { //同步处理
			if (header.getReplyAddress() == null || header.getReplyAddress().isEmpty()) {
				return new ResponseMessageType.Builder(
						new HeaderType.Builder(VerbEnum.reply, header.getNoun())
						.correlationID(header.getCorrelationID())
						.build()
					).reply(
						new ReplyType.Builder().result(ReplyCodeEnum.FAILD)
						.errors(fatal(404, "Missing reply target."))
						.build()
					).build();
			}
			

			
			info = new RequestInfo(new CountDownLatch(1), null, header.getMessageID());
			
		} else { //异步处理，记录replyAddress
			info = new RequestInfo(null, header.getReplyAddress(), header.getMessageID());
		}	
		
		requestInfoMap.put(key, info);
		
		ResponseMessageType r = sendMessage(request);
		if (!header.isSync())
			return r;

		try {
			bufferLogger.debug("Wait for : correlationId = {}, timeout = {} ms .",  header.getMessageID(), TimeUnit.MINUTES.toMillis(10));
			info.latch.await(10, TimeUnit.MINUTES);		

			
			if (info.result == null) {

				bufferLogger.error("Find no result in sync result map : {} .", header.getCorrelationID());
				return new ResponseMessageType.Builder(
							new HeaderType.Builder(VerbEnum.reply, header.getNoun())
							.correlationID(header.getCorrelationID())
							.build()
						).reply(
							new ReplyType.Builder().result(ReplyCodeEnum.FAILD)
							.errors(fatal(404, "Find no result in sync result map."))
							.build()
						).build();
				
			} else {
				ResponseMessageType response = info.result;
				bufferLogger.info("Bus send sync response: %s .", DefaultBusService.toString(response));

				
				return info.result;
			}
			
		} catch (InterruptedException e) {
			e.printStackTrace();
			logger.error("Request time out : correlationId = {}", header.getCorrelationID());
			return new ResponseMessageType.Builder(
						new HeaderType.Builder(VerbEnum.reply, header.getNoun())
						.correlationID(header.getCorrelationID())
						.build()
					).reply(
						new ReplyType.Builder().result(ReplyCodeEnum.FAILD)
						.errors(fatal(408, "Request time out : correlationId = %s", header.getCorrelationID()))
						.build()
					).build();
		}
		

	}

	@Override
	public ResponseMessageType response(ResponseMessageType response) {
		bufferLogger.debug("Bus receive async response: {} .", DefaultBusService.toString(response));
		//先查看本地等待信息的请求者
		HeaderType header = response.getHeader();
		String messageId = header.getMessageID();
		if (messageId == null || messageId.isEmpty()) {
			return new ResponseMessageType.Builder(
					new HeaderType.Builder(VerbEnum.reply, header.getNoun())
					.correlationID(header.getCorrelationID()).messageID(header.getMessageID())
					.build()
				).reply(
					new ReplyType.Builder().result(ReplyCodeEnum.FAILD)
					.errors(fatal(400, "Response missing messageId", header.getCorrelationID()))
					.build()
				).build();
		}
		return sendMessage(response);
		
		
		
//		final RequestInfo info = requestInfoMap.remove(messageId);
//		if (info != null) { //本地直接处理响应
//			final AdapterService adapter = adapterMap.get(info.replyAddress);
//				
//			new Thread(()->{localProcessRequest(response, info, adapter);} ).start();;
//			
//			return new ResponseMessageType.Builder(
//					new HeaderType.Builder(VerbEnum.reply, header.getNoun())
//					.correlationID(header.getCorrelationID())
//					.build()
//				).reply(
//					new ReplyType.Builder().result(ReplyCodeEnum.OK)
//					.build()
//				).build();
//		} else {//网络处理响应
//		  return sendMessage(response);
//		}
	}

	
	private void localProcessRequest(final ResponseMessageType response,final RequestInfo info,final AdapterService adapter) {
		new Thread(()->{
			
				if (response.getHeader().isSync()) { //同步处理																
					info.result = response;
					info.latch.countDown();												
				}
				else { //异步处理
					if (info.replyAddress != null && info.replyAddress.equalsIgnoreCase(adapter.getToken())) {
						bufferLogger.info("Bus send async response: {} .", DefaultBusService.toString(response));
						adapter.response(response);
					}
				}
		}).start();
	}
	
	public static String toString(MessageBase message) {
		return (message.getHeader() != null? Utils.toJSon(message.getHeader()) : message.toString());
	}

	@Override
	public AdapterService registAdapter(AdapterService adapter, String name,
			Topic.TopicEnd... topics) {
		
		adapter.setToken(Utils.randomKey());
		adapter.setName(name);
		adapter.setBusService(this);
		adapterMap.put(adapter.getToken(), adapter);
		
		bufferLogger.info("Succeed to regist adapter :{}", name);
		
		List<Topic.TopicEnd> allTopics = new ArrayList<>();
		for (final Topic.TopicEnd end : topics) {
			allTopics.add(end);
			final VerbTypeEnum verbType = verbTypeMap.get(end.getTopic().getVerb());
			switch (verbType) {
			case Request:
			case Tansaction: //对发送请求和事务的适配器，增加reply上传权限。
				if (end.isIn()) //
					allTopics.add(Topic.out(VerbEnum.reply, end.getTopic().getNoun()));
				else {//对响应请求和事务的适配器，增加reply上传的权限
					allTopics.add(Topic.in(VerbEnum.reply, end.getTopic().getNoun()));
				}
				break;
			default:
				break;				
			}
		}
		
		for (final Topic.TopicEnd end : allTopics) {
			if (!verbTypeMap.containsKey(end.getVerb())) {
				throw new BusException("Unknow verb type of the topic : verb = " + end.getVerb());
			}
			
			if (end.isIn())
				continue;
					
			String topicName = end.getTopic().getName();
			List<AdapterService>  adapters = outAdapters.get(topicName);
			if (adapters == null) {
				adapters = new CopyOnWriteArrayList<>();
			}
			
			if (adapters.indexOf(adapter) < 0) {
				adapters.add(adapter);
			}
						
			final VerbTypeEnum verbType = verbTypeMap.get(end.getVerb());
			ChannelType channelType = ChannelType.Share;
			switch (verbType) {
			case Event:
			case Response://事件和响应默认为广播的方式，(TODO,优化响应)
				channelType = ChannelType.StandAlone;
				break;
			default:
				break;				
			}
			
			final String channelName = end.getTopic().getName();
			Channel c =  channelRegistry.getChannel(channelName);
			if (c == null) {
				ChannelConfig config = new ChannelConfig(channelName, channelType);
				c = channelRegistry.addChannel(config);
			}
			
			c.register(new Listener() {
				
				@Override
				public void receive(ChannelMessage message) {
					String code = message.getCode();
					if (code.compareTo(channelName) != 0) {
						bufferLogger.error("Message code doesn't match  channel : code = {}, channel = {}", code, channelName);
						return;
					}

					switch (verbType) {
						case Event:
						{
							EventMessageType event = Utils.toObject(message.getContent(), EventMessageType.class);
							adapter.publish(event);
						} break;
						case Request:
						case Tansaction:
						{
							final RequestMessageType r = Utils.toObject(message.getContent(), RequestMessageType.class);
							//HeaderType header = r.getHeader();
							bufferLogger.info("Bus send request: {} .", DefaultBusService.toString(r));
							ResponseMessageType res = adapter.request(r);
							//sendMessage(res);//还需把响应结果发送到总线
							
							String messageId = r.getHeader().getMessageID();
							
							if (r.getHeader().isSync()) { //同步
								final RequestInfo info = requestInfoMap.remove(messageId);	
								if (info != null) { //本地直接处理响应
									bufferLogger.info("Bus receive sync response: {} .", DefaultBusService.toString(r));
									final AdapterService adapter = adapterMap.get(info.replyAddress);
									localProcessRequest(res, info, adapter);								
								} else {//网络处理响应
								  sendMessage(r);
								}
							} else {
								//适配器负责通过response接口发送消息
							}
							
//							//同步请求消息还需把响应结果发送到总线
//							if (header != null && (header.getAsyncReplyFlag() == null || !header.getAsyncReplyFlag())) { //同步消息处理
//								response(res);
//							} else {//异步消息处理
//								
//							}
						} break;
						case Response: 
						{
							ResponseMessageType r = Utils.toObject(message.getContent(), ResponseMessageType.class);
							HeaderType header = r.getHeader();
							RequestInfo info = requestInfoMap.remove(header.getMessageID());	
							if (info != null) {
								
								localProcessRequest(r, info, adapter);
						    }																			
						} break;
						default:
							break;
					}
				 }
			  });
			
			bufferLogger.info("Succeed to bind adapter :{}, topic end: {} , channel : {},{}", name, end, channelName, channelType);
		}
		
		
		return adapter;
	}

}

