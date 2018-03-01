package com.znd.ei.ads.buffer;



public interface BufferFactory {
	Buffer openSession();
	Buffer openSession(boolean autoCommit);
	void destory();
}
