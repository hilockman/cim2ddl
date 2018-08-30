package com.znd.bus.server;

import java.util.List;

public class AdapterInfo {

	private String name;
	private List<Topic> topics;
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public List<Topic> getTopics() {
		return topics;
	}
	
	public void setTopics(List<Topic> topics) {
		this.topics = topics;
	}
}
