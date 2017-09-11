package com.znd.ei.adf.apl;

import com.znd.ei.adf.acp.impl.RedisDB;
import com.znd.ei.adf.acp.impl.RedisDBFactory;
import com.znd.ei.adf.annotations.Application;

@Application(outputCC="created_BPAModel", outputData=RedisDBFactory.class)
public class BPAModelUploader extends AppTemplate<RedisDB> {

	public void upload() {
		RedisDB db = new RedisDB();
		flushData(db);
	}


	
}
