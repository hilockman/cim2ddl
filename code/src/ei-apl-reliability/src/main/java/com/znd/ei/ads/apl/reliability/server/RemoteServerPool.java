package com.znd.ei.ads.apl.reliability.server;

public interface RemoteServerPool<T> {

	T getNoBusyServer();

	void destory();
	


}
