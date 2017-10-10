package com.znd.ei.ads.acp;

import java.util.Set;

import com.znd.ei.ads.adf.DataFieldStorage;

public interface ConnectionFactory {
	MemDBDataOperations getMemDBDataOperations();
	
	ListDataOperations getListDataOperations();

	//BusOperations getBusOperations();
	
	StringDataOperations getStringDataOperations();
	
	StringRefDataOperations getStringRefOperations();
	
	void register(DataFieldStorage manager);
	
	MapDataOperations getMapDataOperations();
	
	/**
	 * 发送消息
	 * @param contentCode
	 * @param key
	 * @throws ACPException
	 */
	void publishData(String contentCode, String key) throws ACPException;
	


	/**
	 * 发送消息和数据
	 * @param contentCode
	 * @param key
	 * @param content
	 * @param singleton , true 表示接收者唯一, false 表示接收者不唯一
	 * @throws ACPException
	 */
	void publishData(String contentCode, String key, String content, boolean singleton) throws ACPException;
	
	/**
	 * 发送消息和数据
	 * @param contentCode
	 * @param key
	 * @param content
	 * @throws ACPException
	 */
	void publishData(String contentCode, String key, String content) throws ACPException;

	
	/**
	 * 删除keys
	 * @param arge
	 */
	void deleteKeys(String... keys);
	
	/**
	 * 查找keys
	 * @param pattern
	 * @return
	 */
	Set<String> findKeys(String pattern);
}
