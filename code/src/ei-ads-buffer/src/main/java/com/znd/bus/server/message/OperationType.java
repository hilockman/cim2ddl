package com.znd.bus.server.message;

/**
 * 操作类
 * @author wangheng
 * @date 2018年9月7日
 * @time 下午2:07:13
 * @type_name OperationType
 */
public class OperationType {

    protected String operationId;
    protected String noun;
    protected String verb;
	public String getOperationId() {
		return operationId;
	}
	public void setOperationId(String operationId) {
		this.operationId = operationId;
	}
	public String getNoun() {
		return noun;
	}
	public void setNoun(String noun) {
		this.noun = noun;
	}
	public String getVerb() {		return verb;
	}
	public void setVerb(String verb) {
		this.verb = verb;
	}
}
