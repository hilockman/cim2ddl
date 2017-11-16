package com.znd.ei.ads.acp;

import java.util.Map;

import com.znd.ei.ads.adf.MapData;

public interface MapDataOperations<K, V> extends IOOperations<MapData<K,V>> {

	V get(String key, K mkey);

	Long getSize(String key) ;

	void remove(String key, K...keys) ;
	
	void put(String key, K hashKey, V value);

	Map<K, V> getAll(String key);
	
	void putAll(String key, Map<K,V> content);

}
