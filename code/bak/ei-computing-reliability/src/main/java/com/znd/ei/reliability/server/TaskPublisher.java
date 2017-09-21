package com.znd.ei.reliability.server;

import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.znd.ei.ads.acp.ACPResult;

public interface TaskPublisher {
	ACPResult run() throws RedissonDBException;
}
