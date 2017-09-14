package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.RedisDBData;


public abstract class DBOperations  extends AbstractOperations<RedisDBData> {

	public DBOperations() {
		super(RedisDBData.class);
	}

}
