package com.znd.ads.service.impl;

import java.util.Date;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.mapper.NodeMapper;
import com.znd.ads.model.po.AdsNode;
import com.znd.ads.service.NodeService;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.common.buffer.AdsNodeInfoBuffer;
import com.znd.bus.common.model.AdsNodeInfo;
@Service
public class NodeServiceImpl implements NodeService {
//	@Autowired
//	NodeMapper mapper;
	
//	@Autowired 
//	private Buffer defaultBuffer;
	
	@Autowired
	AdsNodeInfoBuffer adsNodeMapper;
	
	@Override
	public List getAll() {

		List<AdsNodeInfo> nodes1 = adsNodeMapper.findAll();
		if (nodes1 == null)
			return null;
		
		try {
		
			for (AdsNodeInfo node1 : nodes1) {
				long elapsed = 0;
				elapsed = new Date().getTime() - node1.getLastUpdate().getTime();
				node1.setStatus(elapsed < 5000 ? 1: 0);
		   };
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(0);
		}

		
		return nodes1;
//		List<AdsNode> nodes =  mapper.all();
//		
//		Iterator<AdsNode> it = nodes.iterator();
//		
//		Map<String, AdsNode> nodeMap = new HashMap<>();
//		while (it.hasNext()) {
//			AdsNode node = it.next();
//			nodeMap.put(node.getUrl(), node);
//		}
//		
//		List<AdsNode> nodes1 = adsNodeMapper.findAll();
//		List<AdsNode> allNodes = new ArrayList<>();
//		nodes1.forEach((node1)->{
//			if (nodeMap.containsKey(node1.getUrl())) {
//				AdsNode node = nodeMap.get(node1.getUrl());
//				node.setJobCount(node1.getJobCount());
//				long elapsed = 0;
//				elapsed = new Date().getTime() - node1.getLastUpdate().getTime();
//				node.setStatus(elapsed < 5000 ? 1: 0);
//				node.setLastUpdate(node1.getLastUpdate());
//				node.setTaskCount(node1.getTaskCount());				
//			} else {
//				allNodes.add(node1);
//			}
//		});
//		
//		allNodes.addAll(nodes);
//		
//		return allNodes;
	}

//	@Override
//	public AdsNode getByName(String name) {
//		return mapper.getByName(name);
//	}
	
	@Override
	public AdsNodeInfo getByName(String name) {
//		return adsNodeMapper.getByName(name);
		return adsNodeMapper.getNodeByName(name);
	}
	

//	@Override
//	public void save(AdsNode info) {
//		mapper.save(info);
//	}

	@Override
	public AdsNodeInfo getByUrl(String url) {
//		return mapper.getByUrl(url);
		return adsNodeMapper.getNodeByUrl(url);
	}

//	@Override
//	public void deleteById(String nodeId) {
//		mapper.deleteById(nodeId);
//	}

	@Override
	public AdsNodeInfo getById(String nodeId) {
//		return mapper.getById(nodeId);
		return adsNodeMapper.findById(nodeId);
	}

//	@Override
//	public void update(AdsNode node) {
//		mapper.updateNodeInfo(node);
//	}

}
