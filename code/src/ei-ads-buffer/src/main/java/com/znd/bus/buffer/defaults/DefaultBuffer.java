package com.znd.bus.buffer.defaults;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;
import java.util.concurrent.atomic.AtomicInteger;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferContext;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.TableMeta;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.statement.Statement;
import com.znd.bus.statement.StatementHandler;

public class DefaultBuffer implements Buffer {
	private boolean autoCommit;
	private BufferConfig config;
	private final Logger logger = LoggerFactory.getLogger(DefaultBuffer.class);
	private final Executor executor;
	private final static AtomicInteger count = new AtomicInteger(0);
	private Integer id;
	
	public class RecordCache {
 
		private List<Object> records = new ArrayList<>();
		public RecordCache() {
			
			//this.tableMeta = tableMeta;
		}
		public void clear() {
			records.clear();
		}


		@SuppressWarnings({ "unchecked", "rawtypes" })
		public void addRecord(Object parameter) {
			records.addAll((Collection)parameter);
		}
	}

	private Map<MappedStatement, RecordCache> caches = new HashMap<>();

	
	public DefaultBuffer(BufferConfig config, BufferContext context, boolean b) {
		this.config = config;
		autoCommit = b;
		executor = new DefaultExecutor(context);
		id = count.getAndAdd(1);
		logger.info("Buffer opened : " + key());
	}

	private String key() {
		return config.getKey()+"["+id+"]";
	}
//	public BufferImp(BufferFactoryImp factory) {
//		this(factory, true);
//	}

	@Override
	public void close() {
		logger.info("Buffer closed : " + key());
	}

	@Override
	public <T> T selectOne(String statement, Object parameter) {
		List<T>  results = selectList(statement, parameter);
		if (results == null || results.isEmpty())
			return null;
		
		return results.get(0);
	}

	@Override
	public <E> List<E> selectList(String statement, Object parameter) {
		MappedStatement mappedStatement = config.getMappedStatement(statement);
		
		StatementHandler parameterHandler = config.newStatementHandler(executor, mappedStatement, parameter);		
		Statement ps = parameterHandler.newStatement();		
		parameterHandler.parepared(ps);		
		return executor.query(mappedStatement, ps);
	}

	@Override
	public <K, V> Map<K, V> selectMap(String statement, Object parameter,
			String mapKey) {
		// TODO Auto-generated method stub
		return null;
	}

//	private List<Object> formList(Object parameter)
//	{
//		if (parameter instanceof Collection ) {
//			List<Object> objects = new ArrayList<>();
//			objects.addAll((Collection)parameter);
//			return objects;
//		} else
//			return Arrays.asList(parameter);
//	}
	@Override
	public int insert(String statement, Object parameter) {	
		MappedStatement mappedStatement = config.getMappedStatement(statement);
		if (autoCommit) {
			insertRecords(mappedStatement, getParameters(wrapCollection(parameter)));
		} else {
			RecordCache cache = caches.get(mappedStatement);
			if (cache == null) {
				cache = new RecordCache();
				
				caches.put(mappedStatement, cache);
			}
		    cache.addRecord(getParameters(wrapCollection(parameter)));
		}
		return 0;
	}
	
  @SuppressWarnings({ "unchecked", "rawtypes" })
private Collection<Object> getParameters(Object parameter) {
    Collection<Object> parameters = null;
    if (parameter instanceof Collection) {
      parameters = (Collection) parameter;
    } else if (parameter instanceof Map) {
      Map parameterMap = (Map) parameter;
      if (parameterMap.containsKey("collection")) {
        parameters = (Collection) parameterMap.get("collection");
      } else if (parameterMap.containsKey("list")) {
        parameters = (List) parameterMap.get("list");
      } else if (parameterMap.containsKey("array")) {
        parameters = Arrays.asList((Object[]) parameterMap.get("array"));
      }
    }
    if (parameters == null) {
      parameters = new ArrayList<Object>();
      parameters.add(parameter);
    }
    return parameters;
  }

	  
	  private Object wrapCollection(final Object object) {
	   if (object instanceof Collection) {
	      Map<String, Object> map = new HashMap<String, Object>();
	      map.put("collection", object);
	      if (object instanceof List) {
	        map.put("list", object);
	      }
	      return map;
	    } else if (object != null && object.getClass().isArray()) {
	    	HashMap<String, Object> map = new HashMap<>();
	      map.put("array", object);
	      return map;
	    }
	    return object;
	  }
	  
	@Override
	public int update(String statement, Object parameter) {
		MappedStatement mappedStatement = config.getMappedStatement(statement);
		StatementHandler parameterHandler = config.newStatementHandler(executor, mappedStatement, getParameters(wrapCollection(parameter)));		
		Statement ps = parameterHandler.newStatement();		
		parameterHandler.parepared(ps);		
		return executor.update(mappedStatement, ps);
		
//		Collection<Object> parameters = getParameters(wrapCollection(parameter));
//		MappedStatement mappedStatement = config.getMappedStatement(statement);

	}

	@Override
	public int delete(String statement, Object parameter) {
		
		
		MappedStatement mappedStatement = config.getMappedStatement(statement);
		
		StatementHandler parameterHandler = config.newStatementHandler(executor, mappedStatement, parameter);		
		Statement ps = parameterHandler.newStatement();		
		parameterHandler.parepared(ps);		
		return executor.delete(mappedStatement, ps);
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
	


	
//	private TableMeta  findTableMeta(String tableName) {
//		TableMeta tableMeta = config.getTableMeta(tableName);
//		if (tableMeta == null) {
//			tableMeta = context.createTableMeta(tableName);		
//		}
//		
//		return tableMeta;
//	}
	@Override
	public int delete(String statement) {
		return delete(statement, null);
	}

	@Override
	public void commit() {

		if (!caches.isEmpty()) {
			try {
				
				Set<Entry<MappedStatement, RecordCache>> entrySet = caches.entrySet();
				for (Entry<MappedStatement, RecordCache> e : entrySet) {
					insertRecords(e.getKey(), e.getValue().records);
				}

			} finally {
				clearCaches();
			}
		}
	}

	private void clearCaches() {
		caches.clear();
	}

//	private RTableOperation getTableOperation(TableMeta tableMeta){
//
//		try {
//			RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
//			return bufferOps.getTableOperation(tableMeta.getName());
//		} catch (RedissonDBException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//			throw new RuntimeException("Find no talbe :"+tableMeta.getKey());
//		}
//	}
//	

	
	
	private void insertRecords(MappedStatement mappedStatement, Collection<Object> objects) 
	{		
		StatementHandler parameterHandler = config.newStatementHandler(executor, mappedStatement, objects);		
		Statement ps = parameterHandler.newStatement();		
		parameterHandler.parepared(ps);		
		executor.insert(mappedStatement, ps);
	}


	@Override
	public List<TableMeta> tables() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public BufferConfig getConfig() {
		return config;
	}




}
