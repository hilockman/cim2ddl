package com.znd.ei.buffer.defaults;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Api.RBufferOperation;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RTableOperation;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.ei.buffer.Buffer;
import com.znd.ei.buffer.BufferConfig;
import com.znd.ei.buffer.ColumnMeta;
import com.znd.ei.buffer.ParamerterHandler;
import com.znd.ei.buffer.TableMeta;

public class DefaultBuffer implements Buffer {
	private boolean autoCommit;
	private BufferConfig config;
	private RMemDBBuilder memDBBuilder;
	private final Logger logger = LoggerFactory.getLogger(DefaultBuffer.class);
	
	public class RecordCache {
		private TableMeta tableMeta;
		private List<Object> records = new ArrayList<>();

		public RecordCache(TableMeta tableMeta) {
			this.tableMeta = tableMeta;
		}
		public void clear() {
			records.clear();
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result
					+ ((tableMeta == null) ? 0 : tableMeta.hashCode());
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			RecordCache other = (RecordCache) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (tableMeta == null) {
				if (other.tableMeta != null)
					return false;
			} else if (!tableMeta.equals(other.tableMeta))
				return false;
			return true;
		}

		private DefaultBuffer getOuterType() {
			return DefaultBuffer.this;
		}

		public void addRecord(Object parameter) {
			records.add(parameter);
		}
	}

	private Map<TableMeta, RecordCache> caches = new HashMap<>();

	public DefaultBuffer(BufferConfig config, RMemDBBuilder memDBBuilder, boolean b) {
		this.config = config;
		this.memDBBuilder = memDBBuilder;
		autoCommit = b;
	}

//	public BufferImp(BufferFactoryImp factory) {
//		this(factory, true);
//	}

	@Override
	public void close() {
		// TODO Auto-generated method stub

	}

	@Override
	public <T> T selectOne(String statement, Object parameter) {
		List<T>  results = selectList(statement, parameter);
		if (results == null || results.isEmpty())
			return null;
		
		return results.get(0);
	}

	@SuppressWarnings("unchecked")
	@Override
	public <E> List<E> selectList(String statement, Object parameter) {
		TableMeta tableMeta = config.find(statement);
		if (tableMeta == null) {
			throw new RuntimeException(String.format("Fail to to parse  statemmate , find no table:'%s'. ", statement));
		}
		
		
		RTableOperation tableOps = getTableOperation(tableMeta);
		
		Map<String, String> conditionMap  = null;
		if (parameter == null)
			conditionMap = new HashMap<String, String>();
		else if (parameter instanceof Map<?, ?> ){
			conditionMap = (Map<String, String>)(parameter); 
		} else {
			throw new IllegalArgumentException("Illegal parameter type : "+parameter.getClass());
		}
		try {
			return  (List<E>) tableOps.getRecord(conditionMap);
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return null;
	}

	@Override
	public <K, V> Map<K, V> selectMap(String statement, Object parameter,
			String mapKey) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int insert(String statement, Object parameter) {
		TableMeta tableMeta = config.find(statement);
		if (tableMeta == null) {
			throw new RuntimeException(String.format("Fail to to parse  statemmate , find no table:'%s'. ", statement));
		}
		
		if (autoCommit) {
			commitRecords(tableMeta, new Object[] { parameter });
		} else {
			RecordCache cache = caches.get(tableMeta);
			if (cache == null) {
				cache = new RecordCache(tableMeta);
				
				caches.put(tableMeta, cache);
			}
		    cache.addRecord(parameter);
		}
		return 0;
	}

	@Override
	public int update(String statement, Object parameter) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int delete(String statement, Object parameter) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public <T> T selectOne(String statement) {
		return selectOne(statement, null);
	}

	@Override
	public <E> List<E> selectList(String statement) {
		return selectList(statement, null);
	}

	@Override
	public <K, V> Map<K, V> selectMap(String statement, String mapKey) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public int insert(String statement) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int update(String statement) {
		// TODO Auto-generated method stub
		return 0;
	}

	@Override
	public int delete(String statement) {
		TableMeta tableMeta = config.find(statement);
		if (tableMeta == null) {
			throw new RuntimeException(String.format("Fail to to parse  statemmate , find no table:'%s'. ", statement));
		}
		RTableOperation tableOps = getTableOperation(tableMeta);
		try {
			tableOps.delRecord(new HashMap<String,String>());
		} catch (RedissonDBException e) {
			throw new RuntimeException(e);
		}
		return 0;
	}

	@Override
	public void commit() {

		if (!caches.isEmpty()) {
			try {
				Set<Entry<TableMeta, RecordCache>> set = caches.entrySet();
				for (Entry<TableMeta, RecordCache> e : set) {
					RecordCache c = e.getValue();
					commitRecords(c.tableMeta, c.records.toArray(new Object[0]));
				}

			} finally {
				clearCaches();
			}
		}
	}

	private void clearCaches() {
		Set<Entry<TableMeta, RecordCache>> set = caches.entrySet();
		for (Entry<TableMeta, RecordCache> c : set) {
			c.getValue().clear();
		}

		caches.clear();

	}

	private RTableOperation getTableOperation(TableMeta tableMeta){

		try {
			RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
			return bufferOps.getTableOperation(tableMeta.getName());
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			throw new RuntimeException("Find no talbe :"+tableMeta.getKey());
		}
	}
	
	private void commitRecords(TableMeta tableMeta, Object[] objects) 
	{		
		RTableOperation tableOps = getTableOperation(tableMeta);
		
		ParamerterHandler recordBuilder = tableMeta.getRecordBuilder();
		List<String[]> records = new ArrayList<>();
		Map<String, List<String>> indexRecords = new HashMap<>();

		
		List<ColumnMeta> indexColumns = tableMeta.getIndexColumns();
		List< List<String> > columnValuesList = new ArrayList<>(); 
		for (ColumnMeta c : indexColumns) {
			List<String> l = new ArrayList<>();
			columnValuesList.add(l);
			indexRecords.put(c.getName(), l);
		}
		
		for (Object o : objects) {
			String[] values = recordBuilder.toArray(tableMeta, o);
			if (values.length != tableMeta.getColumnSize()) {
				throw new RuntimeException("Cloumn size is not match : "+ tableMeta.getName());
			}
			int j = 0;
			for (ColumnMeta c : indexColumns) {
				columnValuesList.get(j++).add(values[c.getIndex()]);
			}
			records.add(values);
		}

		try {
			tableOps.setRecord(records, indexRecords);
			logger.info("Record(s) inserted int '{}': sum = " + records.size(), tableMeta.getName());
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();			
		}
	}




}
