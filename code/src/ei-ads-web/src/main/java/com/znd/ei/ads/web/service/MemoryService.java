package com.znd.ei.ads.web.service;

import java.util.List;

import com.znd.ei.ads.web.model.CategroyInfo;

public interface MemoryService {
	/**
	 * 提供所有buffer名称
	 */
	List<CategroyInfo> getDbNodes();



	List<CategroyInfo> getTableNodes(String dbid);
}
