package com.znd.ei.ads.bus.buffer;

import com.znd.ei.ads.bus.config.BufferConfig;



public interface BufferFactory {
	Buffer openSession();
	Buffer openSession(boolean autoCommit);
	BufferConfig config();
	void destory();
}
