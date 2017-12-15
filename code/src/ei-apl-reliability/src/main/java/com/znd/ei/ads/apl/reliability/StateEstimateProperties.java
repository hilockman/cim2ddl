package com.znd.ei.ads.apl.reliability;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties(prefix = "state-estimate")
public class StateEstimateProperties {
	private Integer listenPort;
	
	private Integer serverPort;
	
	private String serverIp;
	
	private String serverId;

	private Integer serverThread;
	
	private Long readyResponseTimeOut;
	
	
	private String cachedDir;
	
	private String appDir;

	public Integer getListenPort() {
		return listenPort;
	}

	public void setListenPort(Integer listenPort) {
		this.listenPort = listenPort;
	}

	public Integer getServerPort() {
		return serverPort;
	}

	public void setServerPort(Integer serverPort) {
		this.serverPort = serverPort;
	}

	public String getServerIp() {
		return serverIp;
	}

	public void setServerIp(String serverIp) {
		this.serverIp = serverIp;
	}

	public Integer getServerThread() {
		return serverThread;
	}

	public void setServerThread(Integer serverThread) {
		this.serverThread = serverThread;
	}

	public Long getReadyResponseTimeOut() {
		return readyResponseTimeOut;
	}

	public void setReadyResponseTimeOut(Long readyResponseTimeOut) {
		this.readyResponseTimeOut = readyResponseTimeOut;
	}

	public String getCachedDir() {
		return cachedDir;
	}

	public void setCachedDir(String cachedDir) {
		this.cachedDir = cachedDir;
	}

	public String getServerId() {
		return serverId;
	}

	public void setServerId(String serverId) {
		this.serverId = serverId;
	}

	public String getAppDir() {
		return appDir;
	}

	public void setAppDir(String appDir) {
		this.appDir = appDir;
	}
}
