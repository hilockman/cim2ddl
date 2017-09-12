package com.znd.ei.reliability.server;

import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.znd.ei.reliability.model.ComputingResult;

public interface TaskPublisher {
	ComputingResult run() throws RedissonDBException;
}
