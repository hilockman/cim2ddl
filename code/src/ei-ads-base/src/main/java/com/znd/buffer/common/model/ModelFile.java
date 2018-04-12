package com.znd.buffer.common.model;

import com.znd.buffer.annotation.Index;

public class ModelFile {
	@Index
	private String id;
	
	@Index
	private String modelName;
	
	
	private String name;
	
	
	private String type;
	
	
	private String content;


	public String getId() {
		return id;
	}


	public void setId(String id) {
		this.id = id;
	}


	public String getModelName() {
		return modelName;
	}


	public void setModelName(String modelName) {
		this.modelName = modelName;
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
		return "ModelFile [id=" + id + ", modelName=" + modelName + ", name="
				+ name + ", type=" + type + ", content=" + content + "]";
	}
}
