package com.znd.bus.common.buffer;

import com.znd.bus.common.MapperInterface;
import com.znd.bus.common.model.AdsNodeInfo;

public interface AdsNodeInfoBuffer extends MapperInterface<AdsNodeInfo> {

	AdsNodeInfo getNodeByUrl(String url);

}
