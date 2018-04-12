package com.znd.buffer.common.mapper;

import com.znd.buffer.common.model.AdsNode;

public interface AdsNodeMapper {
	AdsNode getNodeByUrl(String url);

	void insert(AdsNode node);

	void update(AdsNode node);
	
	void deleteById(String id);
}
