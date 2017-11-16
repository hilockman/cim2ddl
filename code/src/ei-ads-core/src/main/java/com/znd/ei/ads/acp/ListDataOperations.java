package com.znd.ei.ads.acp;

import java.util.List;

import com.znd.ei.ads.adf.ListData;



public interface ListDataOperations<V> extends IOOperations<ListData<V>> {

	V lpop(String key) throws ACPException;

	List<V> getAll(String key);
	
	void pushAll(String key, List<V> values);
	
	void push(String key, V value);
}
