package com.znd.ads.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.model.CategroyInfo;
import com.znd.ads.service.BufferService;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferFactory;
import com.znd.bus.channel.Message;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.TableMeta;
import com.znd.bus.log.LogMapper;

@Service
public class BufferServiceImpl implements BufferService {

	@Autowired
	private BufferConfig bufferConfig;
	
			
	@Autowired
	private LogMapper bufferLogMapper;
	
	
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
		List<TableMeta> tables = bufferConfig.getAllTableMetas();
		List<CategroyInfo> nodes = new ArrayList<>();
		for (TableMeta table : tables) {
			CategroyInfo node = new CategroyInfo();
			node.setId(table.getName());
			node.setName(table.getName());
			node.setAlias(table.getName());
			nodes.add(node);
		}
		return nodes;
	}

	@Override
	public void sendMessage(Message message) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public List getLogs() {
		// TODO Auto-generated method stub
		return null;
	}

}
