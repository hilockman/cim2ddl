package com.znd.bus.channel;

public class ChannelConfig {
	private String name;
	private ChannelType type;
	
	public ChannelConfig() {
		this("common", ChannelType.SEND);
	}
	public ChannelConfig(String name, ChannelType type) {
		this.name = name; 
		this.type = type;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public ChannelType getType() {
		return type;
	}
	public void setType(ChannelType type) {
		this.type = type;
	}
	
}