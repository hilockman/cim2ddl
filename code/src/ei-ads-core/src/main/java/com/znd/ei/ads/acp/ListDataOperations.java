package com.znd.ei.ads.acp;

import java.util.List;

import com.znd.ei.ads.adf.ListData;



public abstract class ListDataOperations<V> extends AbstractOperations<ListData<V>> {

	public abstract V lpop(String key) throws ACPException;

	public abstract List<V> getAll(String key);
	
	public abstract void pushAll(String key, List<V> values);

}
