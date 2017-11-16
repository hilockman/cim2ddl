package com.znd.ei.ads.apl.reliability;

public interface MessageListener<T> {

	Class<T> getMessageClass();
	void onMessage(T message);
}
