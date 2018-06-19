package com.znd.bus.common.model;

import java.util.Date;

import com.znd.bus.annotation.Index;


public class ModelFile {
	@Index
	private String id;
	
	@Index
	private String modelId;
	
	
	private String name;
	
	
	private String type;
	
	
	private String content;
	
	
	private Date lastUpdate;
	
	private String desc;


	public String getId() {
		return id;
	}


	public void setId(String id) {
		this.id = id;
	}


	public String getModelId() {
		return modelId;
	}


	public void setModelId(String modelId) {
		this.modelId = modelId;
	}


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


	public String getContent() {
		return content;
	}


	public void setContent(String content) {
		this.content = content;
	}


	@Override
	public String toString() {
		return "ModelFile [id=" + id + ", modelName=" + modelId + ", name="
				+ name + ", type=" + type + ", content=" + content + "]";
	}


	public Date getLastUpdate() {
		return lastUpdate;
	}


	public void setLastUpdate(Date lastUpdate) {
		this.lastUpdate = lastUpdate;
	}


	public String getDesc() {
		return desc;
	}


	public void setDesc(String desc) {
		this.desc = desc;
	}
}
