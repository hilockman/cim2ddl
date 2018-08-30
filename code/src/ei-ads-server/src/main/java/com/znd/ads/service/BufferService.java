package com.znd.ads.service;

import java.util.List;

import com.znd.ads.model.CategoryInfo;
import com.znd.bus.channel.ChannelMessage;

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
	List<CategoryInfo> getDbNodes();

	List<CategoryInfo> getTableNodes(String dbid);

	
	void sendMessage(ChannelMessage message);

	
	List getLogs();

	List getRecords(String dbid, String tableid);

	List getTableColumns(String dbid, String tableid);

}
