package com.znd.ads.service;

import java.util.List;

import com.znd.ads.model.CategoryInfo;

public interface MemoryService {
	/**
	 * 提供所有buffer名称
	 */
	List<CategoryInfo> getDbNodes();



	List<CategoryInfo> getTableNodes(String dbid);
}
