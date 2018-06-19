package com.znd.ads.model.po;

import java.util.Date;

import org.apache.ibatis.type.Alias;

import com.znd.bus.annotation.Index;

@Alias("model_source")
public class ModelSource {

	@Index
	private String id;
	
	@Index
	private String name;
	
	private String type;
	
	private String desc;
	
	private Date lastUpdate;
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getType() {
		return type;
	}
	public void setType(String type) {
		this.type = type;
	}
	public String getDesc() {
		return desc;
	}
	public void setDesc(String desc) {
		this.desc = desc;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public Date getLastUpdate() {
		return lastUpdate;
	}
	public void setLastUpdate(Date lastUpdate) {
		this.lastUpdate = lastUpdate;
	}
}
