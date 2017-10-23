package com.znd.ei.ads.acp;

import java.util.Set;

import com.znd.ei.ads.AdsServer;
import com.znd.ei.ads.adf.DataFieldStorage;

public interface ConnectionFactory {
	MemDBDataOperations getMemDBDataOperations();
	
	<V> ListDataOperations<V> getListDataOperations();

	//BusOperations getBusOperations();
	
	StringDataOperations getStringDataOperations();
	
	<V> ObjectRefDataOperations<V> getObjectRefOperations();
	
	void register(DataFieldStorage manager);
	
	<K, V> MapDataOperations<K, V> getMapDataOperations();
	
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
	
	/**
	 * key exist or not
	 * @param key
	 * @return
	 */
	boolean hasKey(String key);
	
	
    /**
     * Get remote service object for remote invocations.
     * <p>
     * This method is a shortcut for
     * <pre>
     *     get(remoteInterface, RemoteInvocationOptions.defaults())
     * </pre>
     *
     * @see RemoteInvocationOptions#defaults()
     * @see #get(Class, RemoteInvocationOptions)
     *
     * @param <T> type of remote service
     * @param remoteInterface - remote service interface
     * @return remote service instance
     */
	<T> T getService(Class<T> remoteInterface) ;
	   
	/**
	 * get ads server
	 * @return
	 */
	AdsServer getServer() ;
	
	
	<T> void registerService(Class<T> remoteInterface, T serviceImp);
	
}
