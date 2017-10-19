package com.znd.ei.ads.apl;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ei.Utils;
import com.znd.ei.ads.AdsServer;
import com.znd.ei.ads.AdsServerInfo;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;

@Apl
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
