package com.znd.ei.ads.web.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ei.ads.buffer.BufferConfig;
import com.znd.ei.ads.buffer.BufferFactory;
import com.znd.ei.ads.buffer.TableMeta;
import com.znd.ei.ads.web.model.NodeInfo;
import com.znd.ei.ads.web.service.BufferService;

@Service
public class BufferServiceImpl implements BufferService {

	@Autowired
	BufferFactory bufferFactory;
	
	@Autowired
	BufferConfig bufferConfig;
	
	@Override
	public List<NodeInfo> getDbNodes() {
		List<NodeInfo> items = new ArrayList<>();
		NodeInfo rootItem = new NodeInfo();
		rootItem.setId(bufferConfig.getId());
		rootItem.setName(bufferConfig.getName());
		rootItem.setAlias(bufferConfig.getAlias());
		rootItem.setType(NodeInfo.BUFFER);
		items.add(rootItem);
		return items;
	}

	@Override
	public List<NodeInfo> getTableNodes(String dbid) {
		TableMeta[] tables = bufferConfig.getTableMetas();
		List<NodeInfo> nodes = new ArrayList<>();
		for (int i = 0; i < tables.length; i++) {
			TableMeta table = tables[i];
			NodeInfo node = new NodeInfo();
			node.setId(table.getName());
			node.setName(table.getName());
			node.setAlias(table.getName());
			nodes.add(node);
		}
		return nodes;
	}

}
