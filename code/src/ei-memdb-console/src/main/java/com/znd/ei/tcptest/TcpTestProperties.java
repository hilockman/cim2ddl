package com.znd.ei.tcptest;

import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.stereotype.Component;

@Component
@ConfigurationProperties("tcptest")
public class TcpTestProperties {
    private String serverIp;
    private Integer serverPort;
    private Integer serverWorkers;
    private Integer serverTimeOut;
    
    private String hostIp;
    private Integer hostPort;
	public String getServerIp() {
		return serverIp;
	}
	public void setServerIp(String serverIp) {
		this.serverIp = serverIp;
	}

	public String getHostIp() {
		return hostIp;
	}
	public void setHostIp(String hostIp) {
		this.hostIp = hostIp;
	}
	public Integer getServerPort() {
		return serverPort;
	}
	public void setServerPort(Integer serverPort) {
		this.serverPort = serverPort;
	}
	public Integer getHostPort() {
		return hostPort;
	}
	public void setHostPort(Integer hostPort) {
		this.hostPort = hostPort;
	}
	public Integer getServerWorkers() {
		return serverWorkers;
	}
	public void setServerWorkers(Integer serverWorkers) {
		this.serverWorkers = serverWorkers;
	}
	@Override
	public String toString() {
		return "TcpTestProperties [serverIp=" + serverIp + ", serverPort="
				+ serverPort + ", serverWorkers=" + serverWorkers + ", hostIp="
				+ hostIp + ", hostPort=" + hostPort + "]";
	}
	public Integer getServerTimeOut() {
		return serverTimeOut;
	}
	public void setServerTimeOut(Integer serverTimeOut) {
		this.serverTimeOut = serverTimeOut;
	}

}
