package com.znd.ei.ads.adf;

import com.znd.ei.ads.acp.ObjectRefDataOperations;


public class ObjectRefData<T> extends DataItem {

	//private String content;
	

	private ObjectRefDataOperations getOps() {
		return (ObjectRefDataOperations)operations;
	}
	
	public T getContent() {
		return getOps().get(getKey());
	}

	public void setContent(T content) {
		getOps().set(getKey(), content);
	}
	


	@Override
	public boolean isEmpty() {
		return getOps().isEmpty(getKey());
	}

	@Override
	public void clear() {
		//content = null;
	}

	@Override
	public boolean canClear() {
		return true;
	}
}
