package com.znd.ei.ads.buffer.factory;

import com.znd.ei.ads.buffer.Buffer;



public interface BufferFactory {
	Buffer openSession();
	Buffer openSession(boolean autoCommit);
	void destory();
}
