package com.znd.client;

import com.znd.buffer.common.model.AdsNode;

public interface Client {
	AdsNode getNode();
	void start();
}
