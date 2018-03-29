package com.znd.ei.ads.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.TableMeta;
import com.znd.ei.ads.model.CategroyInfo;
import com.znd.ei.ads.service.BufferService;

@Service
public class BufferServiceImpl implements BufferService {

	@Autowired
	BufferFactory bufferFactory;
	
	@Autowired
	BufferConfig bufferConfig;
	
	@Override
	public List<CategroyInfo> getDbNodes() {
		List<CategroyInfo> items = new ArrayList<>();
		CategroyInfo rootItem = new CategroyInfo();
		rootItem.setId(bufferConfig.getId());
		rootItem.setName(bufferConfig.getName());
		rootItem.setAlias(bufferConfig.getAlias());
		rootItem.setType(CategroyInfo.BUFFER);
		items.add(rootItem);
		return items;
	}

	@Override
	public List<CategroyInfo> getTableNodes(String dbid) {
		TableMeta[] tables = bufferConfig.getTableMetas();
		List<CategroyInfo> nodes = new ArrayList<>();
		for (int i = 0; i < tables.length; i++) {
			TableMeta table = tables[i];
			CategroyInfo node = new CategroyInfo();
			node.setId(table.getName());
			node.setName(table.getName());
			node.setAlias(table.getName());
			nodes.add(node);
		}
		return nodes;
	}

}
