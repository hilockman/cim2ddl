package com.znd.ei.ads;

import com.znd.ei.ads.acp.ACPException;
/**
 * ads remote server interface
 * @author wangheng
 *
 */
public interface AdsServer {
	
	static final String ADS_GET_NODEINFOS = "adsget_NodeInfos";
	static final String ADS_REPLY_NODEINFOS = "adsreply_NodeInfos";

	String publish(String cc, String content) throws ACPException;
}
