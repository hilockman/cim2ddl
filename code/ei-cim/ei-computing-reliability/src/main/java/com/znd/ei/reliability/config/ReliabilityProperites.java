package com.znd.ei.reliability.config;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.boot.context.properties.EnableConfigurationProperties;

@ConfigurationProperties("reliability")
@EnableConfigurationProperties(ReliabilityProperites.class)
public class ReliabilityProperites {

	private Lock busyLock = new ReentrantLock();    //注意这个地方
	
	private String messageType="Reliability";

	public String getMessageType() {
		return messageType;
	}

	public void setMessageType(String messageType) {
		this.messageType = messageType;
	}

	public Lock getBusyLock() {
		return busyLock;
	}

	public void setBusyLock(Lock busyLock) {
		this.busyLock = busyLock;
	}


}
