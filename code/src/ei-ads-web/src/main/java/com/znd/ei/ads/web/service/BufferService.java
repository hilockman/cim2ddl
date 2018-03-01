package com.znd.ei.ads.web.service;

import java.util.List;

import com.znd.ei.ads.web.model.NodeInfo;

/**
 * buffer服务
 * @author wangheng
 * @date 2018年2月28日
 * @time 下午2:26:33
 * @type_name BufferService
 */
public interface BufferService {

	/**
	 * 提供所有buffer名称
	 */
	List<NodeInfo> getDbNodes();

	List<NodeInfo> getTableNodes(String dbid);



}
