package com.znd.ads.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.model.CategoryInfo;
import com.znd.ads.service.BufferService;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.channel.Channel;
import com.znd.bus.channel.ChannelMessage;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.TableMeta;
import com.znd.bus.log.LogBuffer;
import com.znd.bus.mapping.RawArrayBufferMapper;

@Service
public class BufferServiceImpl implements BufferService {

	@Autowired
	private BufferConfig bufferConfig;
				
	@Autowired
	private LogBuffer bufferLogMapper;
	
	@Autowired
	private Buffer defaultBuffer;
	
	@Autowired
	private Channel commonChannel;
	
	@Override
	public List<CategoryInfo> getDbNodes() {
		List<CategoryInfo> items = new ArrayList<>();
		CategoryInfo rootItem = new CategoryInfo();
		rootItem.setId(bufferConfig.getId());
		rootItem.setName(bufferConfig.getName());
		rootItem.setAlias(bufferConfig.getAlias());
		rootItem.setType(CategoryInfo.BUFFER);
		items.add(rootItem);
		return items;
	}

	@Override
	public List<CategoryInfo> getTableNodes(String dbid) {
		List<TableMeta> tables = bufferConfig.getAllTableMetas();
		List<CategoryInfo> nodes = new ArrayList<>();
		for (TableMeta table : tables) {
			CategoryInfo node = new CategoryInfo();
			node.setId(table.getName());
			node.setName(table.getName());
			node.setAlias(table.getName());
			
			nodes.add(node);
			
		}
		return nodes;
	}

	@Override
	public void sendMessage(ChannelMessage message) {
		commonChannel.send(message);
	}

	@Override
	public List getLogs() {
		return bufferLogMapper.findAll();
	}

	@Override
	public List getRecords(String dbid, String tableid) {
		RawArrayBufferMapper m = bufferConfig.getMapper(RawArrayBufferMapper.class, tableid, defaultBuffer);
		return m.getAll();
	}

	@Override
	public List getTableColumns(String dbid, String tableid) {
		TableMeta table = bufferConfig.getTableMeta(tableid);
		if (table != null)
			return table.getColumns();
		
		return null;
	}

}
