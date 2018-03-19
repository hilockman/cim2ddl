package com.znd.ei.ads.bus.buffer;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferBuilder;
import com.ZhongND.RedisDataBus.Api.RBufferOperation;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RTableBuilder;
import com.ZhongND.RedisDataBus.Api.RTableOperation;
import com.ZhongND.RedisDataBus.Enum.RedisTableColumnType;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.ei.ads.bus.binding.BindingException;
import com.znd.ei.ads.bus.buffer.defaults.DefaultBufferFactory;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.ColumnMeta;
import com.znd.ei.ads.bus.config.TableMeta;

public class BufferFactoryBuilder {

	public static final String DEFAULT_APPNAME = "pr";
	public static final String DEFAULT_BUFFERNAME = "CommonBuffer";
	private final Logger logger = LoggerFactory.getLogger(BufferFactoryBuilder.class);

	public static BufferConfig getDefaultConfig() {
		BufferConfig config = new BufferConfig();
		config.setAppName(DEFAULT_APPNAME);
		config.setName(DEFAULT_BUFFERNAME);
		return config;
	}

	private static final HashMap<String, RedisTableColumnType> typeMap = new HashMap<>();
	private static final HashMap<RedisTableColumnType, String> inverseTypeMap = new HashMap<>();


	public static final String INT = "int";
	public static final String BOOLEAN = "boolean";
	public static final String STRING = "string";
	public static final String DOUBLE = "double";
	public static final String BYTE = "byte";
	public static final String FLOAT = "float";
	public static final String LONG = "long";
	public static final String SHORT = "short";
	public static final String DATE = "date";
	public static final String TIME = "time";
	static {		
		typeMap.put(INT, RedisTableColumnType.RedisTableColumnType_int);
		typeMap.put(BOOLEAN, RedisTableColumnType.RedisTableColumnType_boolean);
		typeMap.put(STRING, RedisTableColumnType.RedisTableColumnType_String);
		typeMap.put(DOUBLE, RedisTableColumnType.RedisTableColumnType_double);
		typeMap.put(BYTE, RedisTableColumnType.RedisTableColumnType_byte);
		typeMap.put(FLOAT, RedisTableColumnType.RedisTableColumnType_float);
		typeMap.put(LONG, RedisTableColumnType.RedisTableColumnType_long);
		typeMap.put(SHORT, RedisTableColumnType.RedisTableColumnType_short);
		typeMap.put(DATE, RedisTableColumnType.RedisTableColumnType_long);
		typeMap.put(TIME, RedisTableColumnType.RedisTableColumnType_long);
	
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_int, INT);
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_boolean, BOOLEAN);
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_String, STRING);
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_double, DOUBLE);
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_byte, BYTE);
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_float, FLOAT);
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_long, LONG);
		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_short, SHORT);
	}
	
	
	public static RedisTableColumnType toType(String type) {
		return typeMap.get(type);
	}
	
	
	public static  String toType(RedisTableColumnType type) {
		return inverseTypeMap.get(type);
	}
	
	private void makeTable(RBufferBuilder bufferBuilder, TableMeta tableDefine)
			throws RedissonDBException {
		if (bufferBuilder.checkIsExists(tableDefine.getName()))
			return;	
		
		RTableBuilder tableBuilder = bufferBuilder.getTableBuilder(tableDefine
				.getName());
		

		
		for (ColumnMeta c : tableDefine.getColumns()) {

			
			tableBuilder.setColumn(c.getName(), typeMap.get(c.getType()),
					c.isIndexable());
		}

		logger.info("Table created: {}, clumn size = {}.",
				tableDefine.getName(), tableDefine.getColumnSize());
	}

//	private void rebuildTable(RMemDBBuilder memDBBuilder, List<TableMeta> changedTables) 
//			throws RedissonDBException {
//		// 创建bufferBuilder
//		RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();
//
//		for (TableMeta tableBuilder : changedTables) {
//			// 删除表
//			bufferBuilder.destory(tableBuilder.getName());
//			logger.info("Removed  RBufferTable:{}.", tableBuilder.getName());
//	
//			// 创建表
//			makeTable(bufferBuilder, tableBuilder);
//		}
//		
//		//commit
//		bufferBuilder.commit();
//	}
	public void removeBuffer(BufferFactory factory) throws RedissonDBException {
		DefaultBufferFactory imp = (DefaultBufferFactory) factory;
		factory.destory();
		removeBuffer(imp.getMemDBBuilder(), imp.getConfig().getKey());
	}
	
	private void removeBuffer(RMemDBBuilder memDBBuilder, String key)
			throws RedissonDBException {
		memDBBuilder.destory();
		logger.info("Buffer destoryed : {}", key);			
	}

	private void makeBuffer(BufferConfig config, RMemDBBuilder memDBBuilder,
			TableMeta[] tableBuilders) throws RedissonDBException {
		
		// 创建buffer
		RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();
		logger.info("Buffer created : {}.", config.getKey());
		try {
			if (tableBuilders != null && tableBuilders.length > 0){		
				// 创建表
				for (TableMeta tableBuilder : tableBuilders) {
					makeTable(bufferBuilder, tableBuilder);
				}
			}
		} finally {
			// commit
			bufferBuilder.commit();
			logger.info("Buffer committed : {}.", config.getKey());
		}
	}

	// 判断表示否改变
	private boolean isTableChanged(List<String> columnNames,
			TableMeta tableBuilder) {
		List<ColumnMeta> columns = tableBuilder.getColumns();
		Collections.sort(columns, (a, b) -> {
			return a.getName().compareTo(b.getName());
		});
		Collections.sort(columnNames);
		int i = 0, j = 0;
		for (; i < columns.size() && j < columnNames.size();) {

			int c = columns.get(i).getName().compareTo(columnNames.get(j));
			if (c == 0) {
				i++;
				j++;
				continue;
			} else if (c < 0) {
				return true;
			} else {
				return true;
			}

		}

		return i != j;
	}
	
	public static class MemDbContext {
		private DFService service;
		private RMemDBApi memDBApi;
		private RMemDBBuilder memDBBuilder;
		public MemDbContext(DFService service, RMemDBApi memDBApi, RMemDBBuilder memDBBuilder) {
			this.service = service;
			this.memDBApi = memDBApi;
			this.memDBBuilder = memDBBuilder;
		}
		
		public static class Builder {
			private MemDbContext context;
			public Builder(BufferConfig config) throws RedissonDBException {
				try {
					DFService service = ServiceFactory.getService();
	
					RMemDBApi memDBApi = service.connect(config.getAppName());
	
					RMemDBBuilder memDBBuilder = memDBApi
							.getRMemDBBuilder(config.getName());				
					context = new MemDbContext(service, memDBApi, memDBBuilder);									
				} catch (RedissonDBException e) {
					throw new BindingException(e.getMessage(), e);
				}
			}
			
			public MemDbContext build() {
				return context;
			}
			
		}

		public DFService getService() {
			return service;
		}

		public RMemDBApi getMemDBApi() {
			return memDBApi;
		}

		public RMemDBBuilder getMemDBBuilder() {
			return memDBBuilder;
		}
	}


	
	public BufferFactory build(BufferConfig config){	
		try {
			config.build();
			
			MemDbContext context = new MemDbContext.Builder(config).build();
			DFService service = context.getService();

			RMemDBBuilder memDBBuilder = context.getMemDBBuilder();
			TableMeta[] tableMetas = config.getTableMetas();
			boolean available = memDBBuilder.checkAvailability();
			if (config.getCreateFlag() == BufferConfig.FALSE && !available) {
				throw new RuntimeException("Fail to find buffer : "+config.getName());
			}
						
			if (config.getCreateFlag() == BufferConfig.UPDATE) { //更新buffer
				boolean createFlag = false;
				// check buffer define changed or not ?
				if (available) {
					if (tableMetas != null && tableMetas.length > 0) {
						RBufferOperation bufferOperation = memDBBuilder
								.getBufferOperation();
						
						List<TableMeta> changedTables = new ArrayList<>();
						List<String> tableNames = (bufferOperation != null) ? bufferOperation
								.getTableNameArray() : new ArrayList<>();
						for (TableMeta tableMeta : tableMetas) {
							
							
							if (tableNames.indexOf(tableMeta.getName()) < 0) {
								changedTables.add(tableMeta);
								continue;
							}
															
							RTableOperation ops = bufferOperation.getTableOperation(tableMeta.getName());
							List<String> columnNames = ops.getColumnNameArray();
							if (isTableChanged(columnNames, tableMeta)) {
								changedTables.add(tableMeta);
								
							}
						}
						
						if (!changedTables.isEmpty()) {
							logger.info("Buffer config changed, will be removed : {}. ", config.getKey());
							// remove buffer
							removeBuffer(memDBBuilder, config.getKey());
							createFlag = true;
						}
					}
					
					
					if (createFlag) {
						logger.info("Buffer will be created : {}. ", config.getKey());
						// make buffer
						makeBuffer(config, memDBBuilder, tableMetas);
					}
				}
			} else if (config.getCreateFlag() == BufferConfig.CREATE) {
				if (available){
					// remove buffer
					logger.info("Buffer config will be removed : {}. ", config.getKey());
					removeBuffer(memDBBuilder, config.getKey());
				}
				
				// make buffer
				logger.info("Buffer will be created : {}. ", config.getKey());
				makeBuffer(config, memDBBuilder, tableMetas);
			} else { //从数据库中加载表信息
				if (available) {
					
				}
			}
			
	
			return new DefaultBufferFactory(config, service, memDBBuilder);
		
		} catch (RedissonDBException e) { //低层redisdatabus出错
			throw new RuntimeException(e);
		} finally {
			logger.info("Succeed to build buffer : "+config.getKey());
		}
	}

//	private void clearBuffer(RMemDBBuilder memDBBuilder, String appName,
//			String name) throws RedissonDBException {
//		memDBBuilder.destory();
//		logger.info("Buffer destoryed : {}.{}", appName, name);
//
//	}



//	public void clearBuffer(BufferConfig config) throws RedissonDBException {
//		DFService service = ServiceFactory.getService();
//		RMemDBApi memDBApi = service.connect(config.getAppName());
//		RMemDBBuilder memDBBuilder = memDBApi
//				.getRMemDBBuilder(config.getName());
//		clearBuffer(memDBBuilder, config.getAppName(), config.getName());
//	}

	public void removeTable(BufferFactory factory, String name) throws RedissonDBException {
		((DefaultBufferFactory)factory).getMemDBBuilder().getBufferBuilder().destory(name); 
		logger.info("Table removed : {} .", name);
	}

}
