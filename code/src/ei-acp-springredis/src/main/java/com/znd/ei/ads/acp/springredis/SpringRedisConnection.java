package com.znd.ei.ads.acp.springredis;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
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
import com.znd.ei.ads.acp.ObjectRefDataOperations;
import com.znd.ei.ads.acp.StringDataOperations;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.MemDBData;

public class SpringRedisConnection extends AbstractConnectionFactory {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(SpringRedisConnection.class);
	
	@Autowired
	StringRedisTemplate stringRedisTemplate;
	
	public class MapDataOperationsImp<V> extends MapDataOperations<String, V> {

		private HashOperations<String, String, V> operations;
		
		public MapDataOperationsImp() {
			operations = stringRedisTemplate.<String, V>opsForHash();
		}
		

		@Override
		public V get(String key, String mkey){
			return operations.get(key, mkey);
		}

		@Override
		public Long getSize(String key) {
			return operations.size(key);
		}

		@Override
		public void remove(String key, String... keys) {
			operations.delete(key, keys);
		}

		@Override
		public void put(String key, String key1, V value) {
			operations.put(key, key1, value);
		}

		@Override
		public Map<String, V> getAll(String key) {
				return operations.entries(key);
		}

		@Override
		public void putAll(String key, Map<String, V> content) {
			operations.putAll(key, content);
		}


		@Override
		public boolean isEmpty(String key) {
			// TODO Auto-generated method stub
			return false;
		}
	}


	public class ObjectRefDataOperationsImp extends ObjectRefDataOperations<String> {
		private ValueOperations<String, String> operations;
		public ObjectRefDataOperationsImp() {
			operations = stringRedisTemplate.opsForValue();
		}

		
		@Override
		public String get(String key) {
			return operations.get(key);
		}


		@Override
		public void set(String key, String value) {
			operations.set(key, value);
		}


		@Override
		public boolean isEmpty(String key) {
			return stringRedisTemplate.hasKey(key);
		}

	}

	public class StringDataOperationsImp extends StringDataOperations {

	

		@Override
		public boolean isEmpty(String key) {
			return key != null && !key.isEmpty();
		}

	}

	public class MemDBDataOperationsImp extends MemDBDataOperations {
		@Override
		public void upload(MemDBData db) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public void download(MemDBData db) {
			// TODO Auto-generated method stub
			
		}

		@Override
		public boolean isEmpty(String key) {
			// TODO Auto-generated method stub
			return false;
		}
	}


	
	class ListDataOperationsImp<V> extends ListDataOperations<V> {
		ListOperations<String, V> operation;
		public ListDataOperationsImp() {
			//operation = stringRedisTemplate.<String, V>opsForList();
		}

		@Override
		public V lpop(String key) throws ACPException {
			return operation.leftPop(key);
		}

		@Override
		public void close() throws ACPException {
		}
		@Override
		public List<V> getAll(String key) {
			return operation.range(key, 0, -1);
		}
		@Override
		public void pushAll(String key, List<V> values) {
			operation.leftPushAll(key, values);
		}
		@Override
		public boolean isEmpty(String key) {
			return stringRedisTemplate.hasKey(key);
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
	public ObjectRefDataOperations getObjectRefOperations() {
		return new ObjectRefDataOperationsImp();
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

	@Override
	public boolean hasKey(String key) {
		return stringRedisTemplate.hasKey(key);
	}



}
