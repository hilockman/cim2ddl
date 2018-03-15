package com.ei.ads.mappper;

import com.znd.ei.ads.vo.AdsNode;

public interface AdsNodeMapper {
	AdsNode getNodeByUrl(String url);

	void insert(AdsNode node);

	void update(AdsNode node);
}
