package com.znd.ei.ads.acp;

public abstract class AbstractOperations<T> implements IOOperations<T> {
	
	public void close()  throws ACPException {
		
	}
	
	public abstract boolean isEmpty(String key);
	
}
