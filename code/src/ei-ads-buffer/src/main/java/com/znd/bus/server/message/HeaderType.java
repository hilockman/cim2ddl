package com.znd.bus.server.message;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import com.znd.bus.server.VerbEnum;
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
	private String correlationId;
	private Boolean asyncReplyFlag = true;
	
	private List<Object> any = new ArrayList<>();
	
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
	public String getCorrelationId() {
		return correlationId;
	}
	public void setCorrelationId(String correlationId) {
		this.correlationId = correlationId;
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
}
