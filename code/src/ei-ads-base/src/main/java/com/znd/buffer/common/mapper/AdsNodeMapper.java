package com.znd.buffer.common.mapper;

import java.util.List;

import com.znd.buffer.common.model.AdsNode;

public interface AdsNodeMapper {
	List<AdsNode> findAll();
	
	AdsNode getNodeById(String id);
	
	AdsNode getNodeByUrl(String url);

	void insert(AdsNode node);

	void update(AdsNode node);
	
	void deleteById(String id);
}
