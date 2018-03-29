package com.znd.bus.task;

import com.znd.bus.annotation.Index;

public class CalcJob {
	@Index
	private String id;
	
	@Index
	private String name;
	
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
}
