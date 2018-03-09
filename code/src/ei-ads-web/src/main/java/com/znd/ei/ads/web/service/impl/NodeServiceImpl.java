package com.znd.ei.ads.web.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ei.ads.web.mapper.NodeMapper;
import com.znd.ei.ads.web.service.NodeService;
import com.znd.ei.ads.web.vo.NodeInfo;
@Service
public class NodeServiceImpl implements NodeService {
	@Autowired
	NodeMapper mapper;
	
	@Override
	public List<NodeInfo> all() {
		return mapper.all();
	}

	@Override
	public NodeInfo getByName(String name) {
		return mapper.getByName(name);
	}

	@Override
	public void save(NodeInfo info) {
		mapper.save(info);
	}

	@Override
	public NodeInfo getByUrl(String url) {
		return mapper.getByUrl(url);
	}

	@Override
	public void deleteById(Integer nodeId) {
		mapper.deleteById(nodeId);
	}

	@Override
	public NodeInfo getById(Integer nodeId) {
		return mapper.getById(nodeId);
	}

	@Override
	public void update(NodeInfo node) {
		mapper.update(node);
	}

}
