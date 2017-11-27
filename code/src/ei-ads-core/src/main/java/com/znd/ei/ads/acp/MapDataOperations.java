package com.znd.ei.ads.acp;

import java.util.Map;

public interface MapDataOperations extends IOOperations {

	<K, V> V get(String key, K mkey);

	Long getSize(String key) ;

	<K> void remove(String key, K...keys) ;
	
	<K, V> void put(String key, K hashKey, V value);

	<K, V> Map<K, V> getAll(String key);
	
	<K, V> void putAll(String key, Map<K,V> content);

}
