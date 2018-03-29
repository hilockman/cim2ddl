package com.ei.ads.mappper;

import com.znd.buffer.common.model.AdsNode;

public interface AdsNodeMapper {
	AdsNode getNodeByUrl(String url);

	void insert(AdsNode node);

	void update(AdsNode node);
}
