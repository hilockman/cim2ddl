package com.ei.ads.config;

import java.util.concurrent.ExecutorService;

import com.znd.ei.ads.vo.NodeInfo;

public class ClientConfig {
	private int heartbeat = 1000;

	
	private ExecutorService threadPool;
	
	
	private NodeInfo nodeInfo;
	
	public int getHeartbeat() {
		return heartbeat;
	}

	public void setHeartbeat(int heartbeat) {
		this.heartbeat = heartbeat;
	}

	public ExecutorService getThreadPool() {
		return threadPool;
	}

	public void setThreadPool(ExecutorService threadPool) {
		this.threadPool = threadPool;
	}

	public NodeInfo getNodeInfo() {
		return nodeInfo;
	}

	public void setNodeInfo(NodeInfo nodeInfo) {
		this.nodeInfo = nodeInfo;
	}
}
