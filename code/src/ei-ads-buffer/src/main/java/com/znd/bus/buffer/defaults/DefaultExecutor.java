package com.znd.bus.buffer.defaults;

import java.util.List;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Api.RBufferOperation;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RTableOperation;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.bus.buffer.BufferContext;
import com.znd.bus.config.TableMeta;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.mapping.ParameterMapping;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.DeleteStatement;
import com.znd.bus.statement.InsertStatement;
import com.znd.bus.statement.RowUpdateHandler;
import com.znd.bus.statement.SelectStatement;
import com.znd.bus.statement.Statement;

public class DefaultExecutor implements Executor {
	
	private final BufferContext context;
	public DefaultExecutor(BufferContext context) {
		this.context = context;
	}
	private final Logger logger = LoggerFactory.getLogger(DefaultExecutor.class);

	@Override
	public <E> List<E> query(MappedStatement ms, Statement st) {
		SelectStatement ss = (SelectStatement)st;
		TableMeta tableMeta = ms.getTableMeta();		
		RTableOperation tableOps = getTableOperation(tableMeta);		
		Map<String, String> conditionMap  = ss.getConditionMap();
		
		try {
			return ms.handler(new ResultSet(ms.getColumnIndexMap(), tableOps.getRecord(conditionMap)));
			
		} catch (RedissonDBException e) {
			throw new ExecutionException(e);
		}
	
	}

	@Override
	public int update(MappedStatement ms, Statement st) {
		InsertStatement us = (InsertStatement) st;
		
		
		//final ParameterMapping[] keyProperties = ms.getNormalProperties();
		//final ParameterMapping[] conditionProperties = ms.getConditionProperties();
		
			
		TableMeta tableMeta = ms.getTableMeta();
		final RTableOperation tableOps = getTableOperation(tableMeta);
		
		if (us.count() > 0) {
			for (int i = 0; i < us.count(); i++) {
				us.update(i, new RowUpdateHandler() {
					
					@Override
					public void update(Map<Short, String> columns,
							Map<String, String> conditions) {
						try {
							tableOps.setCells(columns, conditions);
						} catch (RedissonDBException e) {
							throw new ExecutionException(e.getMessage(), e);
						}
					}
				});		
			}
		}
		
		return 0;
 	
	}
	
//	@Override
//	public int update(MappedStatement ms, Statement st) {
//		UpdateStatement us = (UpdateStatement) st;
//		
//		List<String[]> records = us.getRecords();
//		
//		final ParameterMapping[] keyProperties = ms.getNormalProperties();
//		final ParameterMapping[] conditionProperties = ms.getConditionProperties();
//		
//			
//		TableMeta tableMeta = ms.getTableMeta();
//		RTableOperation tableOps = getTableOperation(tableMeta);
//		
// 	
//		for (Object object : parameters) {
//			MetaObject metaParam = config.newMetaObject(object);
//			Map<Short, String> valueMap = new HashMap<>();
//			Map<String, String> conditionMap = new HashMap<>();
//			
//			Statement ps = new UpdateStatement(valueMap, conditionMap);
//			for (ParameterMapping paramMapping : keyProperties) {
//			    Object value = metaParam.getValue(paramMapping.getProperty());
//			    TypeHandler handler = paramMapping.getTypeHandler();
//			    if (handler != null) {
//			    	handler.setParameter(ps, paramMapping.getDbColumnIndex(), value);
//
//			    }
//			}
//			
//			for (ParameterMapping paramMapping : conditionProperties) {
//			    Object value = metaParam.getValue(paramMapping.getProperty());
//			    TypeHandler handler = paramMapping.getTypeHandler();
//			    if (handler != null) {
//			    	handler.setParameter(ps, paramMapping.getProperty(), value);
//			    }
//			}
//			
//			try {
//				tableOps.setCells(valueMap, conditionMap);
//			} catch (RedissonDBException e) {
//				throw new BindingException(e.getMessage(), e);
//			}
//		}
//		return 0;
//	}

	@Override
	public int delete(MappedStatement ms, Statement st) {
		DeleteStatement ds = (DeleteStatement) st;
		Map<String, String> conditionMap  = ds.getConditionMap();
		TableMeta tableMeta = ms.getTableMeta();
		
		RTableOperation tableOps = getTableOperation(tableMeta);
		try {
			tableOps.delRecord(conditionMap);
		} catch (RedissonDBException e) {
			throw new RuntimeException(e);
		}
		return 0;
	}
	
	private RTableOperation getTableOperation(TableMeta tableMeta){

		try {
			RMemDBBuilder memDBBuilder = context.getMemDBBuilder();
			RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
			return bufferOps.getTableOperation(tableMeta.getName());
		} catch (RedissonDBException e) {
			throw new ExecutionException("Find no talbe :"+tableMeta.getKey(), e);
		}
	}

	@Override
	public void insert(MappedStatement ms, Statement st) {
		TableMeta tableMeta = ms.getTableMeta();
		RTableOperation tableOps = getTableOperation(tableMeta);
		InsertStatement is = (InsertStatement)st;
		List<String[]> records = is.getRecords();
		Map<String, List<String>> indexRecords = is.getIndexRecords();
		try {
			tableOps.setRecord(records, indexRecords);
			logger.debug("Record(s) inserted int '{}': sum = " + records.size(), tableMeta.getName());
		} catch (RedissonDBException e) {
			e.printStackTrace();			
		}
	}

}
