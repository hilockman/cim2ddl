package com.znd.ads.service;

import java.util.List;

import com.znd.ads.model.CategroyInfo;
import com.znd.bus.channel.Message;

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

	
	void sendMessage(Message message);

	
	List getLogs();

}
