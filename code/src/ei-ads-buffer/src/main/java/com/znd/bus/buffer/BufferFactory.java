package com.znd.bus.buffer;

import com.znd.bus.config.BufferConfig;
import com.znd.bus.log.BufferLogger;
import com.znd.bus.task.CalcTaskList;



public interface BufferFactory {
	Buffer openSession();
	Buffer openSession(boolean autoCommit);
	BufferConfig config();
	void destory();
	<E> CalcTaskList<E> taskList(String taskName);
	BufferLogger logger();
}
