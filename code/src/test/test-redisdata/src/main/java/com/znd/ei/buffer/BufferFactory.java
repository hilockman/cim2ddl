package com.znd.ei.buffer;



public interface BufferFactory {
	Buffer openSession();
	Buffer openSession(boolean autoCommit);
	void destory();
}
