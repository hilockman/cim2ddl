package com.znd.ei.ads;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.UUID;

public class AdsServerInfo {
	private String id;
	private String hostname;
	private String ip;
	private boolean status = true;


	
	
	public static AdsServerInfo create() {
		AdsServerInfo node = new AdsServerInfo();
		node.setId(UUID.randomUUID().toString());
		InetAddress address = getInetAddress();
		node.setHostname(getHostName(address));
		node.setIp(getHostIp(address));
		return node;
	}
    public static InetAddress getInetAddress(){  
    	  
        try{  
            return InetAddress.getLocalHost();  
        }catch(UnknownHostException e){  
            System.out.println("unknown host!");  
        }  
        return null;  
  
    }  
  
    public static String getHostIp(InetAddress netAddress){  
        if(null == netAddress){  
            return null;  
        }  
        String ip = netAddress.getHostAddress(); //get the ip address  
        return ip;  
    }  
  
    public static String getHostName(InetAddress netAddress){  
        if(null == netAddress){  
            return null;  
        }  
        String name = netAddress.getHostName(); //get the host address  
        return name;  
    }  
    


	public boolean isStatus() {
		return status;
	}

	public void setStatus(boolean status) {
		this.status = status;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getHostname() {
		return hostname;
	}
	public void setHostname(String hostname) {
		this.hostname = hostname;
	}
	public String getIp() {
		return ip;
	}
	public void setIp(String ip) {
		this.ip = ip;
	}
}
