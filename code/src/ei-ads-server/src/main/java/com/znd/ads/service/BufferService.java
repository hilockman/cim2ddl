package com.znd.ads.service;

import java.util.List;

import com.znd.ads.model.CategoryInfo;
import com.znd.bus.common.model.CategoryTypeEnum;
import com.znd.bus.config.ColumnMeta;

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

	List<CategoryInfo> getTableNodes(String dbid, CategoryTypeEnum type);

	
//	void sendMessage(ChannelMessage message);

	
//	List getLogs();

	List<String[]> getRecords(String dbid, String tableid);

	List<ColumnMeta> getTableColumns(String dbid, String tableid);
	
	void removeRecords(String dbid, String tableid, String[] ids);

}
