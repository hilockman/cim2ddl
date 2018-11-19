package com.znd.bus.server;

import java.util.List;

public class AdapterInfo {

	private String name;
	private List<Topic.TopicEnd> topics;
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public List<Topic.TopicEnd> getTopics() {
		return topics;
	}
	
	public void setTopics(List<Topic.TopicEnd> topics) {
		this.topics = topics;
	}
}
