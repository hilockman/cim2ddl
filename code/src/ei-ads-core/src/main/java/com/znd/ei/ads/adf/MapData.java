package com.znd.ei.ads.adf;

import java.util.Map;

import com.znd.ei.ads.acp.MapDataOperations;

public class MapData<K,V> extends DataItem<MapData<K,V>> {
	//private MapDataOperations<K,V> operation;

	//private Map<String, String> content = new HashMap<String, String>();

	public Map<K, V> getAll() {
		return getOps().getAll(getKey());
	}

	public void putAll(Map<K, V> content) {
		getOps().putAll(getKey(), content);	
	}

//	public MapDataOperations getOperation() {
//		return operation;
//	}
//
//	public void setOperation(MapDataOperations operation) {
//		this.operation = operation;
//	}
	
	@SuppressWarnings("unchecked")
	private MapDataOperations<K,V> getOps() {
		return (MapDataOperations<K,V>)operations;
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
//		if (content != null)
//			content.clear();
//		
//		content = null;
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
