package com.znd.ei.ads.acp;

import java.util.List;



public interface ListDataOperations extends IOOperations {

	<V> V lpop(String key) throws ACPException;
	
	<V> V blpop(String key);

	<V> List<V> getAll(String key);
	
	<V> void pushAll(String key, List<V> values);
	
	<V> void push(String key, V value);

	<V> void bpush(String key, V value);
	
	int getSize(String key);
}
