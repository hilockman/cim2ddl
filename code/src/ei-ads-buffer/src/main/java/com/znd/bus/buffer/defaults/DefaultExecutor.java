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
import com.znd.bus.exception.AdsException;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.ExecutionException;
import com.znd.bus.exception.StatementException;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.mapping.ResultSet;
import com.znd.bus.statement.DeleteStatement;
import com.znd.bus.statement.InsertStatement;
import com.znd.bus.statement.RowUpdateHandler;
import com.znd.bus.statement.SelectStatement;
import com.znd.bus.statement.Statement;

public class DefaultExecutor implements Executor {
	
	private final BufferContext context;
	
	private final static Byte wite_locker = new Byte("1");
	
	public DefaultExecutor(BufferContext context) {
		this.context = context;
	}
	private final Logger logger = LoggerFactory.getLogger(DefaultExecutor.class);

	@Override
	public <E> List<E> query(MappedStatement ms, Statement st) throws ExecutionException {
		SelectStatement ss = (SelectStatement)st;
		TableMeta tableMeta = ms.getTableMeta();		
		RTableOperation tableOps = getTableOperation(tableMeta);		
		Map<String, String> conditionMap  = ss.getConditionMap();
		
		try {
			return ms.handler(new ResultSet(ms.getColumnIndexMap(), tableOps.getRecord(conditionMap)));
			
		} catch (RedissonDBException | BindingException e) {
			throw new ExecutionException(e);
		}
	
	}
	
	<K, V> void print(Map<K, V> m) {
		
		for (Map.Entry<K, V> e : m.entrySet()) {
			K k = e.getKey();
			V v = e.getValue();
			System.out.println(String.format("(%s,%s)", (k != null ? k.toString(): "Nil"), (v != null? v.toString() : "Nil")));
		}
	}

	@Override
	public int update(MappedStatement ms, Statement st) throws ExecutionException {
		InsertStatement us = (InsertStatement) st;
		
		
		//final ParameterMapping[] keyProperties = ms.getNormalProperties();
		//final ParameterMapping[] conditionProperties = ms.getConditionProperties();
		
			
		TableMeta tableMeta = ms.getTableMeta();
		final RTableOperation tableOps = getTableOperation(tableMeta);
		
		if (us.count() > 0) {
			for (int i = 0; i < us.count(); i++) {
				try {
					us.update(i, new RowUpdateHandler() {
						
						@Override
						public void update(Map<Short, String> columns,
								Map<String, String> conditions) throws ExecutionException {
							try {
//							synchronized (wite_locker) {
//								System.out.println("columns=");
//								print(columns);
//								System.out.println("conditions=");
//								print(conditions);
									tableOps.setCells(columns, conditions);
//							}
									
								
								
							} catch (RedissonDBException e) {
								throw new ExecutionException(e.getMessage(), e);
							}
						}
					});
				} catch (StatementException e) {
					throw new ExecutionException(e);
				}		
			}
		}
		
		return 0;
 	
	}
	
	@Override
	public int delete(MappedStatement ms, Statement st) throws ExecutionException {
		DeleteStatement ds = (DeleteStatement) st;
		Map<String, String> conditionMap  = ds.getConditionMap();
		TableMeta tableMeta = ms.getTableMeta();
		
		RTableOperation tableOps = getTableOperation(tableMeta);
		try {
//			synchronized (wite_locker) {
				tableOps.delRecord(conditionMap);
//			}
			
		} catch (RedissonDBException e) {
			throw new RuntimeException(e);
		}
		return 0;
	}
	
	private RTableOperation getTableOperation(TableMeta tableMeta) throws ExecutionException{

		try {
			RMemDBBuilder memDBBuilder = context.getMemDBBuilder();
			RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
			return bufferOps.getTableOperation(tableMeta.getName());
		} catch (RedissonDBException e) {
			throw new ExecutionException("Find no talbe :"+tableMeta.getKey(), e);
		}
	}

	@Override
	public void insert(MappedStatement ms, Statement st) throws ExecutionException {
		TableMeta tableMeta = ms.getTableMeta();
		RTableOperation tableOps = getTableOperation(tableMeta);
		InsertStatement is = (InsertStatement)st;
		List<String[]> records = is.getRecords();
		Map<String, List<String>> indexRecords = is.getIndexRecords();
		try {
			if (records.isEmpty())
				return;
//			synchronized (wite_locker) {
			 tableOps.setRecord(records, indexRecords);
//			}
			logger.debug("Record(s) inserted int '{}': sum = " + records.size(), tableMeta.getName());
		} catch (RedissonDBException e) {
			e.printStackTrace();			
		}
	}

}
