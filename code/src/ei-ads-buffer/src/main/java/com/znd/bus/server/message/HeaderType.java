package com.znd.bus.server.message;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import com.znd.bus.server.NounEnum;
import com.znd.bus.server.VerbEnum;
import com.znd.ei.Utils;
/**
 * 消息头
 * @author wangheng
 * @date 2018年8月27日
 * @time 下午5:10:18
 * @type_name Header
 */
public class HeaderType {

	private VerbEnum verb;
	private String noun;
	private Date timestamp;
	private String messageID;
	private String correlationID;
	private Boolean asyncReplyFlag = true;
	private String replyAddress;
	
	private List<Object> any = new ArrayList<>();
	
	
	public static class Builder {
		private VerbEnum verb;
		private String noun;
		private Date timestamp = new Date();
		private String correlationID = Utils.randomKey();
		private Boolean asyncReplyFlag = true;		
		private List<Object> any = new ArrayList<>();
		private String replyAddress;
		private String messageID;
		
		public Builder(VerbEnum verb, String noun) {
			this.verb = verb;
			this.noun = noun;
		}
		
		public Builder(VerbEnum verb, NounEnum noun) {
			this.verb = verb;
			this.noun = noun.name();
		}
		
		public Builder timestamp(Date time) {
			this.timestamp = time;
			return this;
		}
		
		public Builder correlationID(String id) {
			this.correlationID = id;
			return this;
		}
	
	
		public Builder asyncReplyFlag(Boolean flag) {
			this.asyncReplyFlag = flag;
			return this;
		}
		
		public Builder replyAddress(String address) {
			this.replyAddress = address;
			return this;
		}
		
		
		public Builder messageID(String id) {
			this.messageID = id;
			return this;
		}
		
		
		public Builder any(List<Object> any) {
			this.any  = any;
			return this;
		}
		
		
		
		public HeaderType build() {
			
			return new HeaderType(this);
		}	
	}
	
	private HeaderType(Builder b) {
		this.verb = b.verb;
		this.noun = b.noun;
		this.timestamp = b.timestamp;
		this.messageID = b.messageID;
		this.correlationID = b.correlationID;
		this.asyncReplyFlag = b.asyncReplyFlag;
		this.replyAddress = b.replyAddress;
		this.any = b.any;
	}
	
	public boolean isTopic(VerbEnum verb, NounEnum noun) {
		return (this.verb == verb && this.noun.compareTo(noun.name()) == 0);
	}
	public VerbEnum getVerb() {
		return verb;
	}
	public void setVerb(VerbEnum verb) {
		this.verb = verb;
	}
	public String getNoun() {
		return noun;
	}
	public void setNoun(String noun) {
		this.noun = noun;
	}
	public Date getTimestamp() {
		return timestamp;
	}
	public void setTimestamp(Date timestamp) {
		this.timestamp = timestamp;
	}
	public String getCorrelationID() {
		return correlationID;
	}
	public void setCorrelationID(String correlationID) {
		this.correlationID = correlationID;
	}

	public List<Object> getAny() {
		return any;
	}

	public void setAny(List<Object> any) {
		this.any = any;
	}
	
	public Boolean getAsyncReplyFlag() {
		return asyncReplyFlag;
	}
	public void setAsyncReplyFlag(Boolean asyncReplyFlag) {
		this.asyncReplyFlag = asyncReplyFlag;
	}

	public String getReplyAddress() {
		return replyAddress;
	}

	public void setReplyAddress(String replyAddress) {
		this.replyAddress = replyAddress;
	}

	public String getMessageID() {
		return messageID;
	}

	public void setMessageID(String messageID) {
		this.messageID = messageID;
	} 
	
	public boolean isSync() {
		return this.asyncReplyFlag != null && !this.asyncReplyFlag;
	}
	
	public HeaderType clone() {
		return new HeaderType.Builder(verb, noun)
				.messageID(messageID)
				.correlationID(correlationID)
				.any(any)
				.asyncReplyFlag(asyncReplyFlag)
				.replyAddress(replyAddress)
				.build();
	}
}
