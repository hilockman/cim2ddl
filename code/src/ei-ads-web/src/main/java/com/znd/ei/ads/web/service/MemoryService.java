package com.znd.ei.ads.web.service;

import java.util.List;

import com.znd.ei.ads.web.model.NodeInfo;

public interface MemoryService {
	/**
	 * 提供所有buffer名称
	 */
	List<NodeInfo> getDbNodes();



	List<NodeInfo> getTableNodes(String dbid);
}
