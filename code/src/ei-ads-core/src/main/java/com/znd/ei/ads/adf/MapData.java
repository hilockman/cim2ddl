package com.znd.ei.ads.adf;

import java.util.Map;

import com.znd.ei.ads.acp.MapDataOperations;

public class MapData<K,V> extends DataItem {

	public MapData(String key) {
		setKey(key);
	}
	public Map<K, V> getAll() {
		return getOps().getAll(getKey());
	}

	public void putAll(Map<K, V> content) {
		getOps().putAll(getKey(), content);	
	}


	
	private MapDataOperations getOps() {
		return (MapDataOperations)operations;
	}
	public V get(K key) {
		return getOps().get(getKey(), key);

	}
	
	public void set(K key, V value) {
		getOps().put(getKey(), key, value);
	}

	@Override
	public boolean isEmpty() {
		return getOps().isEmpty(getKey());
	}

	public Long size() {
		return getOps().getSize(getKey());
	}

	@Override
	public void clear() {
	}

	@Override
	public boolean canClear() {
		return true;
	}

	@SuppressWarnings("unchecked")
	public void remove(K key) {
		getOps().remove(getKey(), key);
	}
}
