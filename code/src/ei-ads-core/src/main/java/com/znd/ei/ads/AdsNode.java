package com.znd.ei.ads;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.UUID;

public class AdsNode {
	private String name;
	private boolean status = false;

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	
	public static AdsNode create() {
		AdsNode node = new AdsNode();
		node.setName(getHostName() +":"+ UUID.randomUUID().toString());
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
    
    public static String getHostName() {
    	return getHostName(getInetAddress());
    }

	public boolean isStatus() {
		return status;
	}

	public void setStatus(boolean status) {
		this.status = status;
	}
}
