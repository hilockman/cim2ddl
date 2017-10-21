package com.znd.ei.ads.acp;

import java.util.Map;

import com.znd.ei.ads.adf.MapData;

public abstract class MapDataOperations<K, V> extends AbstractOperations<MapData<K,V>> {



	public abstract V get(String key, K mkey);

	public abstract Long getSize(String key) ;

	public abstract void remove(String key, K...keys) ;
	
	public abstract void put(String key, K hashKey, V value);

	public  abstract Map<K, V> getAll(String key);
	
	public abstract void putAll(String key, Map<K,V> content);

}
