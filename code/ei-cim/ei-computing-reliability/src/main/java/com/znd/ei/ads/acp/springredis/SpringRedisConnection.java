package com.znd.ei.ads.acp.springredis;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.ListOperations;
import org.springframework.data.redis.core.StringRedisTemplate;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.ListDataOperations;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.MemDBDataOperations;
import com.znd.ei.ads.acp.StringDataOperations;
import com.znd.ei.ads.acp.StringRefDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.ListData;

public class SpringRedisConnection implements ConnectionFactory{

	@Autowired
	StringRedisTemplate template;
	
	class ListDataOperationsImp extends ListDataOperations {
		ListOperations<String, String> operation;
		@Override
		public ListData read(ListData o) throws ACPException,
				UnsupportedOperation {
			operation = template.opsForList();
			o.setOperation(this);
			return o;
		}

		@Override
		public void write(ListData o) throws ACPException, UnsupportedOperation {
			operation = template.opsForList();
			operation.leftPushAll(o.getKey(), o.getContent());
		}

		@Override
		public String lpop(String key) throws ACPException {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void close() throws ACPException {
			// TODO Auto-generated method stub
			
		}
		
	}
	
	@Override
	public MemDBDataOperations getMemDBDataOperations() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public ListDataOperations getListOperations() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public StringDataOperations getStringDataOperations() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public StringRefDataOperations getStringRefOperations() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void register(DataFieldStorage manager) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public MapDataOperations getMapDataOperations() {
		// TODO Auto-generated method stub
		return null;
	}

}
