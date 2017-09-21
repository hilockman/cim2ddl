package com.znd.ei.ads.acp;

public interface IOOperations<T> {
	T read(T o) throws ACPException,UnsupportedOperation;
	void write(T o)  throws ACPException, UnsupportedOperation;
	T create();
	Class<T> getDataType();
}
