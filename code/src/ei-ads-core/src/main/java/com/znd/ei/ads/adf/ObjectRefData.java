package com.znd.ei.ads.adf;

import com.znd.ei.ads.acp.ObjectRefDataOperations;


public class ObjectRefData<T> extends DataItem<ObjectRefData<T>> {

	//private String content;
	

	private ObjectRefDataOperations<T> getOps() {
		return (ObjectRefDataOperations<T>)operations;
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
