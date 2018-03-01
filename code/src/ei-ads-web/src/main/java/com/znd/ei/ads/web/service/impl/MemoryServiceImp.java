package com.znd.ei.ads.web.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ei.ads.web.model.NodeInfo;
import com.znd.ei.ads.web.service.MemoryService;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MetaTable;

@Service
public class MemoryServiceImp implements MemoryService {

	@Autowired
	DbEntryOperations[] dbOps;
	
	@Override
	public List<NodeInfo> getDbNodes() {
		List<NodeInfo> names = new ArrayList<>();
		for (int i = 0; i < dbOps.length; i++) {
			NodeInfo item = new NodeInfo();
			item.setId(dbOps[i].getId());
			item.setName(dbOps[i].getName());
			item.setAlias(dbOps[i].getDescription());
			item.setType(NodeInfo.MEMORY);
			names.add(item);
		}
		return names;
		
	}

	@Override
	public List<NodeInfo> getTableNodes(String dbid) {
		List<NodeInfo> nodes = new ArrayList<>();
		for (DbEntryOperations db: dbOps) {
			if (!db.getId().equalsIgnoreCase(dbid))
				continue;
			
			List<MetaTable> tables = db.getTables();
			for (MetaTable table: tables) {
				NodeInfo node = new NodeInfo();
				node.setAlias(table.getDescription());
				node.setId(table.getName());
				node.setName(table.getName());
				nodes.add(node);
			}
		}
		return nodes;
	}

}
