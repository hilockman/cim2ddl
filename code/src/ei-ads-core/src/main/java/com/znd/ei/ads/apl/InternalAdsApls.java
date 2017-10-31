package com.znd.ei.ads.apl;

import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.apl.annotations.AplController;

@AplController
public class InternalAdsApls {

	@Autowired
	private ConnectionFactory connection;
	
//	private AdsServerInfo node;
	public InternalAdsApls() {
		//node = AdsServerInfo.create();
	}
//	
//	@AplFunction
//	public void getNodeInfos(@In(AdsServer.ADS_GET_SERVERINFOS) StringData index, @Out(AdsServer.ADS_REPLY_SERVERINFOS) MapData nodeMap) {
//		nodeMap.setKey(index.getContent());
//		nodeMap.set(node.getName(), Utils.toString(node));
//	}
	

}
