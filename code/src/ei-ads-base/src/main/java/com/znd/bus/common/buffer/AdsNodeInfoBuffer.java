package com.znd.bus.common.buffer;

import com.znd.bus.common.model.AdsNodeInfo;
import com.znd.bus.operations.Operations;

public interface AdsNodeInfoBuffer extends Operations<AdsNodeInfo> {

	AdsNodeInfo getNodeByUrl(String url);
	AdsNodeInfo getNodeByName(String name);

}
