package com.znd.bus.common.model;

import java.util.Date;

import com.znd.bus.annotation.Index;

public class AdsNodeInfo {
	@Index
	private String id;
	
	@Index
	private String name;
	
	
	@Index
	private String url;
	private Date lastUpdate;
	private Integer status;
	private Integer taskCount;
	private Integer jobCount;
	private Double cpuRate;
	private Double memoryRate;
	//当前消息数（节点本次开始运行后，接收到的消息数目）
	private Integer curMsgCount = 0;
	//累积消息数（自节点创建后累积接收到的消息数目）
	private Integer accMsgCount = 0;
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public Date getLastUpdate() {
		return lastUpdate;
	}
	public void setLastUpdate(Date lastUpdate) {
		this.lastUpdate = lastUpdate;
	}
	public Integer getStatus() {
		return status;
	}
	public void setStatus(Integer status) {
		this.status = status;
	}
	public Integer getTaskCount() {
		return taskCount;
	}
	public void setTaskCount(Integer taskCount) {
		this.taskCount = taskCount;
	}
	public Integer getJobCount() {
		return jobCount;
	}
	public void setJobCount(Integer jobCount) {
		this.jobCount = jobCount;
	}
	public String getUrl() {
		return url;
	}
	public void setUrl(String url) {
		this.url = url;
	}
	public Double getCpuRate() {
		return cpuRate;
	}
	public void setCpuRate(Double cpuRate) {
		this.cpuRate = cpuRate;
	}
	public Double getMemoryRate() {
		return memoryRate;
	}
	public void setMemoryRate(Double memoryRate) {
		this.memoryRate = memoryRate;
	}
	public Integer getCurMsgCount() {
		return curMsgCount;
	}
	public void setCurMsgCount(Integer curMsgCount) {
		this.curMsgCount = curMsgCount;
	}
	public Integer getAccMsgCount() {
		return accMsgCount;
	}
	public void setAccMsgCount(Integer accMsgCount) {
		this.accMsgCount = accMsgCount;
	}

}
