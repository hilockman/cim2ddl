package com.znd.ei.ads.acp;

import java.util.List;

import com.znd.ei.ads.adf.ListData;



public interface ListDataOperations extends IOOperations {

	<V> V lpop(String key) throws ACPException;

	<V> List<V> getAll(String key);
	
	<V> void pushAll(String key, List<V> values);
	
	<V> void push(String key, V value);

	int getSize(String key);
}
