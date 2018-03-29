package com.znd.ads.vo;

import java.util.Date;


public class AdsNode {

	private String id;
	private String name;
	private String url;
	private Date lastUpdate;
	private Integer status;
	private Integer taskCount;
	private Integer jobCount;
	
	
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


}