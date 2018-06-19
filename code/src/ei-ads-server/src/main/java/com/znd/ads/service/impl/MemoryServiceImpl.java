package com.znd.ads.service.impl;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.model.CategoryInfo;
import com.znd.ads.service.MemoryService;
import com.znd.ei.memdb.DbEntryOperations;
import com.znd.ei.memdb.MetaTable;

@Service
public class MemoryServiceImpl implements MemoryService {

	@Autowired
	DbEntryOperations[] dbOps;
	
	@Override
	public List<CategoryInfo> getDbNodes() {
		List<CategoryInfo> names = new ArrayList<>();
		for (int i = 0; i < dbOps.length; i++) {
			CategoryInfo item = new CategoryInfo();
			item.setId(dbOps[i].getId());
			item.setName(dbOps[i].getName());
			item.setAlias(dbOps[i].getDescription());
			item.setType(CategoryInfo.MEMORY);
			names.add(item);
		}
		return names;
		
	}

	@Override
	public List<CategoryInfo> getTableNodes(String dbid) {
		List<CategoryInfo> nodes = new ArrayList<>();
		for (DbEntryOperations db: dbOps) {
			if (!db.getId().equalsIgnoreCase(dbid))
				continue;
			
			List<MetaTable> tables = db.getTables();
			for (MetaTable table: tables) {
				CategoryInfo node = new CategoryInfo();
				node.setAlias(table.getDescription());
				node.setId(table.getName());
				node.setName(table.getName());
				nodes.add(node);
			}
		}
		return nodes;
	}

}
