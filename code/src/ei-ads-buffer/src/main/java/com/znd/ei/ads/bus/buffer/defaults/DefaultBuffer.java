package com.znd.ei.ads.bus.buffer.defaults;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
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
import com.ZhongND.RedisDataBus.Object.RedisColumnContent;
import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.ColumnMeta;
import com.znd.ei.ads.bus.config.MetaObject;
import com.znd.ei.ads.bus.config.TableMeta;
import com.znd.ei.ads.bus.mapping.MappedStatement;
import com.znd.ei.ads.bus.mapping.ParameterHandler;
import com.znd.ei.ads.bus.mapping.ResultSet;

public class DefaultBuffer implements Buffer {
	private boolean autoCommit;
	private BufferConfig config;
	private RMemDBBuilder memDBBuilder;
	private final Logger logger = LoggerFactory.getLogger(DefaultBuffer.class);
	
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
			if (parameter instanceof Collection)
				records.addAll((Collection)parameter);
			else
				records.add(parameter);
		}
	}

	private Map<MappedStatement, RecordCache> caches = new HashMap<>();

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
		
		MappedStatement mappedStatement = config.getMappedStatement(statement);
		
		
		TableMeta tableMeta = findTableMeta(statement);
				
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
			return mappedStatement.handler(new ResultSet(tableOps.getRecord(conditionMap)));
			
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
		MappedStatement mappedStatement = config.getMappedStatement(statement);
		if (autoCommit) {
			if (parameter instanceof Collection ) {
				List<Object> objects = new ArrayList<>();
				objects.addAll((Collection)parameter);
				commitRecords(mappedStatement, objects);
			} else
				commitRecords(mappedStatement, Arrays.asList(parameter));
		} else {
			RecordCache cache = caches.get(mappedStatement);
			if (cache == null) {
				cache = new RecordCache();
				
				caches.put(mappedStatement, cache);
			}
		    cache.addRecord(parameter);
		}
		return 0;
	}
	
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
		Collection<Object> parameters = getParameters(wrapCollection(parameter));
		MappedStatement mappedStatement = config.getMappedStatement(statement);
		final String[] keyProperties = mappedStatement.getKeyProperties();
		ResultSet rs = new ResultSet();
		
		for (Object object : parameters) {
			MetaObject metaParam = config.newMetaObject(object);
			
			int i = 0;
			for (; i < keyProperties.length; i++ ) {
				
			}
		}
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
	
	private  void loadColumnMetas(TableMeta tableMeta, RBufferOperation bufferOps) throws RedissonDBException {	
		RTableOperation tableOps = bufferOps.getTableOperation(tableMeta.getName());
		List<String> colNames = tableOps.getColumnNameArray();
		for (int i = 0; i < colNames.size(); i++) {
			RedisColumnContent content = tableOps.getColumnDefine(colNames.get(i));
			ColumnMeta col = new ColumnMeta();
			col.setName(content.getStrFieldName());
			col.setIndexable(content.getIndexType());
			col.setType(BufferFactoryBuilder.toType(content.getType()));
			tableMeta.getIndexColumns().add(col);		
		}
		tableMeta.formIndexColumn();
	}

	
	private TableMeta  findTableMeta(String tableName) {
		TableMeta tableMeta = config.getTableMeta(tableName);
		if (tableMeta == null) {
			try {
				RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
				List<String> tables = bufferOps.getTableNameArray();
				Collections.sort(tables);
				int index = Collections.binarySearch(tables, tableName);
				if (index == -1) {
					throw new RuntimeException(String.format("Find no table:'%s', in buffer : %s", tableName, config.getKey()));
				}
				tableMeta  = new TableMeta();
				tableMeta.setName(tableName);
				
				loadColumnMetas(tableMeta, bufferOps);			
				config.add(tableMeta);
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new RuntimeException(e);
			}			
		}
		
		return tableMeta;
	}
	@Override
	public int delete(String statement) {
		TableMeta tableMeta = findTableMeta(statement);
		
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
				
				Set<Entry<MappedStatement, RecordCache>> entrySet = caches.entrySet();
				for (Entry<MappedStatement, RecordCache> e : entrySet) {
					commitRecords(e.getKey(), e.getValue().records);
				}

			} finally {
				clearCaches();
			}
		}
	}

	private void clearCaches() {
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
	
	private void commitRecords(MappedStatement mappedStatement, List<Object> objects) 
	{		
		TableMeta tableMeta = mappedStatement.getTableMeta();
		RTableOperation tableOps = getTableOperation(tableMeta);
		
		ParameterHandler parameterHandler = mappedStatement.getParameterHandler();
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
			String[] values = parameterHandler.toArrayValues(o);
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
