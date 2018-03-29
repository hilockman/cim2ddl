package com.znd.ads.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.mapper.NodeMapper;
import com.znd.ads.service.NodeService;
import com.znd.buffer.common.model.AdsNode;
@Service
public class NodeServiceImpl implements NodeService {
	@Autowired
	NodeMapper mapper;
	
	@Override
	public List<AdsNode> all() {
		return mapper.all();
	}

	@Override
	public AdsNode getByName(String name) {
		return mapper.getByName(name);
	}

	@Override
	public void save(AdsNode info) {
		mapper.save(info);
	}

	@Override
	public AdsNode getByUrl(String url) {
		return mapper.getByUrl(url);
	}

	@Override
	public void deleteById(Integer nodeId) {
		mapper.deleteById(nodeId);
	}

	@Override
	public AdsNode getById(Integer nodeId) {
		return mapper.getById(nodeId);
	}

	@Override
	public void update(AdsNode node) {
		mapper.updateNodeInfo(node);
	}

}
