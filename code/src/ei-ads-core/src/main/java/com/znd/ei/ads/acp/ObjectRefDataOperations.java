package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.ObjectRefData;

public abstract class ObjectRefDataOperations<T> extends AbstractOperations<ObjectRefData<T>> {

	public abstract T get(String key);
	
	public abstract void set(String key, T value);

}
