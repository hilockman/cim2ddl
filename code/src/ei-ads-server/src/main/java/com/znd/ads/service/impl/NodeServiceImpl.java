package com.znd.ads.service.impl;

import java.util.Iterator;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.mapper.NodeMapper;
import com.znd.ads.service.NodeService;
import com.znd.buffer.common.mapper.AdsNodeMapper;
import com.znd.buffer.common.model.AdsNode;
import com.znd.bus.buffer.Buffer;
@Service
public class NodeServiceImpl implements NodeService {
	@Autowired
	NodeMapper mapper;
	
	@Autowired 
	private Buffer defaultBuffer;
	
	@Autowired
	AdsNodeMapper adsNodeMapper;
	
	@Override
	public List<AdsNode> all() {
		List<AdsNode> nodes =  mapper.all();
		
		Iterator<AdsNode> it = nodes.iterator();
		
		while (it.hasNext()) {
			AdsNode node = it.next();
			AdsNode node1 = adsNodeMapper.getNodeByUrl(node.getUrl());
			if (node1 != null) {
				node.setJobCount(node1.getJobCount());
				node.setLastUpdate(node1.getLastUpdate());
				node.setStatus(node1.getStatus());
				node.setTaskCount(node1.getTaskCount());
			}
		}
		return nodes;
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
