package com.znd.ei.ads;

import com.znd.ei.Utils;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;

@Apl
public class InternalAdsApls {

	private AdsNode node;
	public InternalAdsApls() {
		node = AdsNode.create();
	}
	
	@AplFunction
	void getNodeInfos(@In(AdsServer.ADS_GET_NODEINFOS) StringData index, @Out(AdsServer.ADS_REPLY_NODEINFOS) MapData nodeMap) {
		nodeMap.setKey(index.getContent());
		nodeMap.set(node.getName(), Utils.toString(node));
	}
}
