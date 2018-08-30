package com.znd.bus.server.impl;

import java.util.Date;
import java.util.HashMap;
import java.util.Map;
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
import com.znd.bus.server.AdapterInfo;
import com.znd.bus.server.AdapterService;
import com.znd.bus.server.BusException;
import com.znd.bus.server.BusService;
import com.znd.bus.server.Topic;
import com.znd.bus.server.VerbEnum;
import com.znd.bus.server.VerbTypeEnum;
import com.znd.bus.server.message.ErrorLevelEnum;
import com.znd.bus.server.message.ErrorType;
import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.HeaderType;
import com.znd.bus.server.message.MessageBase;
import com.znd.bus.server.message.ReplyType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;
import com.znd.ei.Utils;

public class BusServiceImpl implements BusService {

	private final Logger logger = LoggerFactory.getLogger(BusService.class);
	private ChannelRegistry channelRegistry;
	private final Map<VerbEnum, VerbTypeEnum> verbTypeMap =  new HashMap<>();
	private final Map<String, ResponseMessageType> syncResultMap = new HashMap<>();
	private final Map<String, CountDownLatch> syncFlagMap = new HashMap<>();
	
	public BusServiceImpl(ChannelRegistry channelRegistry) {
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
	
	public static ErrorType error(String code, ErrorLevelEnum level, String format, Object...args) {
		ErrorType e = new ErrorType();
		e.setCode(code);
		e.setDetails(String.format(format, args));
		e.setLevel(level);
		return e;
	}
	
	public static ErrorType fatal(String code, String format, Object...args) {
		return error(code, ErrorLevelEnum.FATAL, format, args);
	}
	
	public static ErrorType info(String code, String format, Object...args) {
		return error(code, ErrorLevelEnum.INFORM, format, args);
	}
	
	public static ErrorType warning(String code, String format, Object...args) {
		return error(code, ErrorLevelEnum.WARNING, format, args);
	}
	
	public static ErrorType catastrophic(String code, String format, Object...args) {
		return error(code, ErrorLevelEnum.CATASTROPHIC, format, args);
	}
	
	public static ErrorType noHeaderError(MessageBase msgBase) {
		return fatal("412", "Find no header in message : %s", Utils.toJSon(msgBase));
	}
	
	private ResponseMessageType sendMessage(MessageBase msgBase) {
		HeaderType header = msgBase.getHeader();
		ResponseMessageType r = new ResponseMessageType();
		ReplyType reply = new ReplyType();
		if (header == null) {
			reply.getErrors().add(noHeaderError(msgBase));
			r.setReply(reply);
			return r;
		}
		
		if (header.getVerb() == null || header.getNoun() == null) {
			reply.getErrors().add(fatal("412", "Fail to find verb or noun : noun = %s, verb = %s", header.getVerb(), header.getNoun()));
		}
		
		String channelName = Topic.formName(header.getVerb(), header.getNoun());
		Channel c = channelRegistry.getChannel(channelName);
		if (c == null) {
			ChannelConfig config = new ChannelConfig(channelName, ChannelType.SendOnly);
			c  = channelRegistry.addChannel(config);
		}
		
		if (header.getCorrelationId() == null || header.getCorrelationId().isEmpty()) {
			header.setCorrelationId(Utils.randomKey());
		}
		
		if (header.getTimestamp() == null) {
			header.setTimestamp(new Date());
		} 
		
		ChannelMessage msg = new ChannelMessage(channelName, Utils.toJSon(msgBase));
		c.send(msg);
		
		
		r.setHeader(header);
		return r;
	}
	
	@Override
	public ResponseMessageType publish(EventMessageType event) {
		return sendMessage(event);
	}

	@Override
	public ResponseMessageType request(RequestMessageType request) {
		HeaderType header = request.getHeader();
		ResponseMessageType r = new ResponseMessageType();
		
		if (header == null) {
			ReplyType reply = new ReplyType();		
			reply.getErrors().add(noHeaderError(request));
			r.setReply(reply);
			return r;
		}
		
		CountDownLatch latch = null;
		String key = Utils.randomKey();
		
		if (header.getCorrelationId() == null || header.getCorrelationId().isEmpty()) {
			header.setCorrelationId(key);
			if (header.getAsyncReplyFlag() == null || !header.getAsyncReplyFlag()) {
				latch = new CountDownLatch(1);
				syncFlagMap.put(key, latch);
			}
		}		

		r = sendMessage(request);
		if (latch != null) {
			try {
				latch.await(5, TimeUnit.MINUTES);
				
			} catch (InterruptedException e) {
				e.printStackTrace();
				logger.error("Request time out : correlationId = {}", header.getCorrelationId());
				ReplyType reply = new ReplyType();
				reply.getErrors().add(fatal("502", "Request time out : correlationId = %s", header.getCorrelationId()));
				r.setReply(reply);				
				return r;
			}
			
			if (!syncResultMap.containsKey(key)) {
				ReplyType reply = new ReplyType();
				reply.getErrors().add(fatal("404", "Find no result in sync result map."));
				r.setReply(reply);
			} else {
				r = syncResultMap.get(key);
			}
		}
		
		return r;
	}

	@Override
	public ResponseMessageType response(ResponseMessageType response) {
		return sendMessage(response);
	}

	@Override
	public void registAdapter(AdapterService adapter, AdapterInfo info) {
		registAdapter(adapter, info.getName(), info.getTopics().toArray(new Topic[0]));
	}

	@Override
	public void registAdapter(AdapterService adapter, String name,
			Topic... topics) {
		for (final Topic topic : topics) {
			if (!verbTypeMap.containsKey(topic.getVerb())) {
				throw new BusException("Unknow verb type of the topic : verb = " + topic.getVerb());
			}
			
			final VerbTypeEnum verbType = verbTypeMap.get(topic.getVerb());
			ChannelType channelType = ChannelType.Share;
			switch (verbType) {
			case Event:
				channelType = ChannelType.StandAlone;
				break;
			default:
				break;				
			}
			
			final String channelName = topic.getName();
			ChannelConfig config = new ChannelConfig(channelName, channelType);
			Channel c = channelRegistry.addChannel(config);
			c.register(new Listener() {
				
				@Override
				public void receive(ChannelMessage message) {
					String code = message.getCode();
					if (code.compareTo(channelName) != 0) {
						logger.error("Code doesn't match  channel : code = {}, channel = {}", code, channelName);
					}
					//Topic topic =  Topic.parse(code);
					switch (verbType) {
					case Event:
					{
						EventMessageType event = Utils.toObject(message.getContent(), EventMessageType.class);
						adapter.publish(event);
					}
					break;
					case Request:
					{
						RequestMessageType r = Utils.toObject(message.getContent(), RequestMessageType.class);
						adapter.request(r);
					}
					break;
					case Response: 
					{
						ResponseMessageType r = Utils.toObject(message.getContent(), ResponseMessageType.class);
						HeaderType header = r.getHeader();
						if (header != null && (header.getAsyncReplyFlag() == null || !header.getAsyncReplyFlag())) {
							if (syncFlagMap.containsKey(header.getCorrelationId())) {
								syncResultMap.put(header.getCorrelationId(), r);
								CountDownLatch latch = syncFlagMap.get(header.getCorrelationId());
								latch.countDown();
								
								return;
							}
						}
						adapter.response(r);					
						
					}
					break;
					default:
						break;
					}
				}
			});
		}
	}
}

