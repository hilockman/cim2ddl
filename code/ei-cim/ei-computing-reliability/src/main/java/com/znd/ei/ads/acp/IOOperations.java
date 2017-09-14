package com.znd.ei.ads.acp;

public interface IOOperations<T> {
	T read(T o) throws ACPException;
	void write(T o)  throws ACPException;
	T create();
}
