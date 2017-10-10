package com.znd.ei.ads.acp.springredis;

import java.util.Arrays;
import java.util.Set;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.data.redis.core.HashOperations;
import org.springframework.data.redis.core.ListOperations;
import org.springframework.data.redis.core.StringRedisTemplate;
import org.springframework.data.redis.core.ValueOperations;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.AbstractConnectionFactory;
import com.znd.ei.ads.acp.ListDataOperations;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.MemDBDataOperations;
import com.znd.ei.ads.acp.StringDataOperations;
import com.znd.ei.ads.acp.StringRefDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.adf.StringRefData;

public class SpringRedisConnection extends AbstractConnectionFactory {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(SpringRedisConnection.class);
	
	@Autowired
	StringRedisTemplate stringRedisTemplate;
	
	public class MapDataOperationsImp extends MapDataOperations {

		private HashOperations<String, String, String> operations;
		
		public MapDataOperationsImp() {
			operations = (HashOperations) stringRedisTemplate.opsForHash();
		}
		
		@Override
		public MapData read(MapData data) throws ACPException,
				UnsupportedOperation {
			data.setContent(operations.entries(data.getKey()));
			return data;
		}

		@Override
		public void write(MapData data) throws ACPException,
				UnsupportedOperation {
			operations.putAll(data.getKey(), data.getContent());
		}

		@Override
		public String get(String key, String mkey) throws ACPException,
				UnsupportedOperation {
			return operations.get(key, mkey);
		}
	}


	public class StringRefDataOperationsImp extends StringRefDataOperations {
		private ValueOperations<String, String> operations;
		public StringRefDataOperationsImp() {
			operations = stringRedisTemplate.opsForValue();
		}
		@Override
		public StringRefData read(StringRefData data) throws ACPException,
				UnsupportedOperation {			
			data.setContent(get(data.getKey()));
			return data;
		}

		@Override
		public void write(StringRefData data) throws ACPException,
				UnsupportedOperation {
			operations.set(data.getKey(), data.getContent());
		}
		
		@Override
		public String get(String key) {
			return operations.get(key);
		}

	}

	public class StringDataOperationsImp extends StringDataOperations {

		@Override
		public StringData read(StringData data) throws ACPException,
				UnsupportedOperation {
			return data;
		}

		@Override
		public void write(StringData data) throws ACPException,
				UnsupportedOperation {
		}

	}

	public class MemDBDataOperationsImp extends MemDBDataOperations {

		@Override
		public MemDBData read(MemDBData data) throws ACPException,
				UnsupportedOperation {
			// TODO Auto-generated method stub
			return null;
		}

		@Override
		public void write(MemDBData data) throws ACPException,
				UnsupportedOperation {
			// TODO Auto-generated method stub

		}

	}


	
	class ListDataOperationsImp extends ListDataOperations {
		ListOperations<String, String> operation;
		public ListDataOperationsImp() {
			operation = stringRedisTemplate.opsForList();
		}
		@Override
		public ListData read(ListData o) throws ACPException,
				UnsupportedOperation {
			
			o.setContent(operation.range(o.getKey(), 0, -1));
			return o;
		}

		@Override
		public void write(ListData o) throws ACPException, UnsupportedOperation {
			operation = stringRedisTemplate.opsForList();
			operation.rightPushAll(o.getKey(), o.getContent());
		}

		@Override
		public String lpop(String key) throws ACPException {
			return operation.leftPop(key);
		}

		@Override
		public void close() throws ACPException {
		}
		
	}
	
	@Override
	public MemDBDataOperations getMemDBDataOperations() {
		return new MemDBDataOperationsImp();
	}
	
	public void publishData(String contentCode, String key) throws ACPException {
		if (contentCode == null || contentCode.isEmpty()) {
			throw new ACPException("Null or empty contentCode");
		}
		String message = contentCode+":"+key;
		LOGGER.info("SendMessage:"+message);
		stringRedisTemplate.convertAndSend("chat", message);		
	}
	


	@Override
	public ListDataOperations getListDataOperations() {
		return new ListDataOperationsImp();
	}

	@Override
	public StringDataOperations getStringDataOperations() {
		return new StringDataOperationsImp();
	}

	@Override
	public StringRefDataOperations getStringRefOperations() {
		return new StringRefDataOperationsImp();
	}



	@Override
	public MapDataOperations getMapDataOperations() {
		return new MapDataOperationsImp();
	}
	
	@Override
	public void register(DataFieldStorage manager) {
		
	}

	@Override
	public void deleteKeys(String... keys) {
		stringRedisTemplate.delete(Arrays.asList(keys));
	}

	@Override
	public Set<String> findKeys(String pattern) {
		return stringRedisTemplate.keys(pattern);
	}



}
