package com.znd.ei.ads.apl;

import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.impl.RedisDB;
import com.znd.ei.ads.acp.impl.RedisDBFactory;
import com.znd.ei.ads.annotations.Apl;
import com.znd.ei.ads.annotations.AplFunction;

@Apl(outputCC="created_BPAModel", outputData=RedisDBFactory.class)
public class BPAModelUploader extends AppTemplate<RedisDB> {

	@Autowired
	private ConnectionFactory connectionFactory;
	
	@AplFunction
	public void upload() {		
		DBOperations operations = connectionFactory.getDBOperations();
		RedisDB db = new RedisDB();
		flushData(db);
	}


	
}
