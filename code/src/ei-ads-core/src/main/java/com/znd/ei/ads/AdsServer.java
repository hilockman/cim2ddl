package com.znd.ei.ads;

/**
 * ads remote server interface
 * @author wangheng
 *
 */
public interface AdsServer {
	
	public static final String ADS_GET_SERVERINFOS = "adsget_ServerInfos";
	public static final String ADS_REPLY_SERVERINFOS = "adsreply_ServerInfos";
	public static final String ADS_SERVERINFOS = "ads:server-infos";

	String publish(String cc, String content);
}
