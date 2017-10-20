package com.znd.ei.ads.acp;

public interface IOOperations<T> {
//	T read(T data) throws ACPException,UnsupportedOperation;
//	void write(T data)  throws ACPException, UnsupportedOperation;
	void close()  throws ACPException ;
}
