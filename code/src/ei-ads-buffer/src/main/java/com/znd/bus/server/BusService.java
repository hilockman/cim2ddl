package com.znd.bus.server;


import com.znd.bus.exception.AdsException;
import com.znd.bus.exception.MessageException;
import com.znd.bus.exception.RegistException;
import com.znd.bus.server.message.ErrorLevelEnum;
import com.znd.bus.server.message.ErrorType;
import com.znd.bus.server.message.EventMessageType;
import com.znd.bus.server.message.HeaderType;
import com.znd.bus.server.message.MessageBase;
import com.znd.bus.server.message.PayloadType;
import com.znd.bus.server.message.ReplyCodeEnum;
import com.znd.bus.server.message.ReplyType;
import com.znd.bus.server.message.RequestMessageType;
import com.znd.bus.server.message.ResponseMessageType;
import com.znd.ei.Utils;

public abstract class BusService implements ServiceInterface {
	public static ErrorType error(String code, ErrorLevelEnum level, String format, Object...args) {
		ErrorType e = new ErrorType();
		e.setCode(code);
		e.setDetails(String.format(format, args));
		e.setLevel(level);
		return e;
	}
		
	public static ErrorType error(int code, ErrorLevelEnum level, String format, Object...args) {
		ErrorType e = new ErrorType();
		e.setCode(String.valueOf(code));
		e.setDetails(String.format(format, args));
		e.setLevel(level);
		return e;
	}	
	
	public static ErrorType fatal(int code, String format, Object...args) {
		return error(code, ErrorLevelEnum.FATAL, format, args);
	}
	
	public static ErrorType info(int code, String format, Object...args) {
		return error(code, ErrorLevelEnum.INFORM, format, args);
	}
	
	public static ErrorType warning(int code, String format, Object...args) {
		return error(code, ErrorLevelEnum.WARNING, format, args);
	}
	
	public static ErrorType catastrophic(int code, String format, Object...args) {
		return error(code, ErrorLevelEnum.CATASTROPHIC, format, args);
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
	
	public void registAdapter(AdapterService adapter, AdapterInfo info) throws AdsException {
		registAdapter(adapter, info.getName(), info.getTopics().toArray(new Topic.TopicEnd[0]));
	}
	
	public abstract  AdapterService registAdapter(AdapterService adapter, String name, Topic.TopicEnd...topics ) throws AdsException;
	
	public ResponseMessageType publish(VerbEnum verb, String noun, String content) {
		return publish(verb, noun, false, content);
	}
	
	public ResponseMessageType publish(VerbEnum verb, String noun, String content, Boolean compressed) {
		String c = content;
		return publish(verb, noun, compressed, new Object[]{c});
	}
		
	public ResponseMessageType publish(VerbEnum verb, String noun, Object...objects) {
		return publish(verb, noun, false, objects);
	}
	
	public ResponseMessageType publish(VerbEnum verb, String noun, Boolean compressed, Object...objects) {

		EventMessageType message = (EventMessageType) new EventMessageType.Builder(
				new HeaderType.Builder(verb, noun)
				.build()
				)
                 .payload(
                		 new PayloadType.Builder()
                		 .compressed(compressed)
                		 .any(objects)
                		 .build())
                 .build();
		
		return publish(message);
	}	
	
	public ResponseMessageType request(VerbEnum verb, String noun, String content) {
		return request(verb, noun, true, false, content);
	}
	
	public ResponseMessageType request(VerbEnum verb, String noun, String content, Boolean compressed) {
		String c = content;
		return request(verb, noun, true, compressed, new Object[]{c});
	}
	
	
	public ResponseMessageType syncRequest(VerbEnum verb, String noun, String content) {
		return request(verb, noun, false, false, content);
	}
	
	public ResponseMessageType syncRequest(VerbEnum verb, String noun, String content, Boolean compressed) {
		String c = content;
		return request(verb, noun, false, compressed, new Object[]{c});
	}	 
	
	public ResponseMessageType request(VerbEnum verb, String noun, Boolean isAsync, Boolean compressed, Object...objects) {
		RequestMessageType message = (RequestMessageType) new ResponseMessageType.Builder(
									new HeaderType.Builder(verb, noun)
									.asyncReplyFlag(isAsync)
									.build()
									)
		                             .payload(
		                            		 new PayloadType.Builder()
		                            		 .compressed(compressed)
		                            		 .any(objects)
		                            		 .build())
		                             .build();
		return request(message);
	}
	
	public ReplyType createReply(ReplyCodeEnum result, ErrorType ... errors) {
		return new ReplyType.Builder().result(result).errors(errors).build();

	}
	
	public ResponseMessageType reply(VerbEnum verb, String noun, String correlateID, ReplyCodeEnum code, ErrorType ... errors) {
		return reply(verb, noun, correlateID, createReply(code, errors), false);
	}

	public ResponseMessageType reply(VerbEnum verb, String noun, String correlateID, ReplyType reply, Boolean compressed, Object...objects) {

		ResponseMessageType message = (ResponseMessageType) new ResponseMessageType.Builder(
				new HeaderType.Builder(verb, noun).correlationID(correlateID)
				.build()
				)
                 .payload(
                		 new PayloadType.Builder()
                		 .compressed(compressed)
                		 .any(objects)
                		 .build())
                 .build();
		
		return response(message);
	}
}
