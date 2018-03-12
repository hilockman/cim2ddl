package com.znd.ei.ads.service;

import java.util.List;

import com.znd.ei.ads.model.CategroyInfo;

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
	List<CategroyInfo> getDbNodes();

	List<CategroyInfo> getTableNodes(String dbid);



}
