package com.znd.bus.buffer;

import java.util.ArrayList;
import java.util.Collections;
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
import com.ZhongND.RedisDataBus.Object.RedisColumnContent;
import com.znd.bus.binding.BindingException;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.BufferConfigException;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.config.TableMeta;

public  class BufferContext {
	
	private final Logger logger = LoggerFactory.getLogger(BufferContext.class);
	
	private final String name;
	private final DFService service;
	private final RMemDBApi memDBApi;
	private final RMemDBBuilder memDBBuilder;
	private RBufferOperation bufferOperation;
	
	
//	private static final Map<String, RedisTableColumnType> typeMap = new HashMap<>();
//	private static final Map<Class<?>, DataType> class2TypeMap = new HashMap<>();
//	private static final HashMap<RedisTableColumnType, String> inverseTypeMap = new HashMap<>();


//	public static final String INT = "int";
//	public static final String BOOLEAN = "boolean";
//	public static final String STRING = "string";
//	public static final String DOUBLE = "double";
//	public static final String BYTE = "byte";
//	public static final String FLOAT = "float";
//	public static final String LONG = "long";
//	public static final String SHORT = "short";
//	public static final String DATE = "date";
//	public static final String TIME = "time";
//	public static final String ENUM = "enum";
//	
//	
	
//	static {		
//		
//		DataType[] values = DataType.values();
//		for (DataType e : values) {
//			typeMap.put(e.name().toLowerCase(), RedisTableColumnType.RedisTableColumnType_String);
//		}
//		
//		
//		class2TypeMap.put(String.class, DataType.STRING);
//		class2TypeMap.put(Integer.class, DataType.INT);
//		class2TypeMap.put(int.class, DataType.INT);
//		class2TypeMap.put(Boolean.class, DataType.BOOLEAN);
//		class2TypeMap.put(boolean.class, DataType.BOOLEAN);
//		class2TypeMap.put(Double.class, DataType.DOUBLE);
//		class2TypeMap.put(double.class, DataType.DOUBLE);
//		class2TypeMap.put(Float.class, DataType.FLOAT);
//		class2TypeMap.put(float.class, DataType.FLOAT);
//		class2TypeMap.put(Short.class, DataType.SHORT);
//		class2TypeMap.put(short.class, DataType.SHORT);
//		class2TypeMap.put(Byte.class, DataType.BYTE);
//		class2TypeMap.put(Byte[].class, DataType.STRING);
//		class2TypeMap.put(byte[].class, DataType.STRING);
//		class2TypeMap.put(char[].class, DataType.STRING);
//		
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_int, INT);
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_boolean, BOOLEAN);
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_String, STRING);
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_double, DOUBLE);
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_byte, BYTE);
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_float, FLOAT);
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_long, LONG);
////		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_short, SHORT);
//	}
//	
//	
//	public static RedisTableColumnType toType(String type) {
//		return typeMap.get(type.toLowerCase());
//	}
//	
//	public static RedisTableColumnType toType(DataType type) {
//		return typeMap.get(type.name().toLowerCase());
//	}
//	
//	
//	public static DataType toType(Class<?> clazz) {
//		return class2TypeMap.get(clazz);
//	}
//	public static  String toType(RedisTableColumnType type) {
//		return inverseTypeMap.get(type);
//	}

	
	public BufferContext(String name, DFService service, RMemDBApi memDBApi, RMemDBBuilder memDBBuilder) {
		this.name = name;
		this.service = service;
		this.memDBApi = memDBApi;
		this.memDBBuilder = memDBBuilder;
	}
	
	public static class Builder {
		private BufferContext context;
		private final BufferConfig config;
		public Builder(BufferConfig config) {
			this.config = config;

		}
		
		public BufferContext build() {					
			try {
				
				DFService service = ServiceFactory.getService();
				RMemDBApi memDBApi = service.connect(config.getAppName());

				RMemDBBuilder memDBBuilder = memDBApi
						.getRMemDBBuilder(config.getName());	
				
				context = new BufferContext(config.getName(), service, memDBApi, memDBBuilder);									
			} catch (Throwable e) {
				throw new BufferConfigException(e.getMessage(), e);
			}

			
			return context;
		}
		
	}
	
	public void initOperation()
	{
		if (bufferOperation != null)
			return;
		
		//get buffer
		try {
			bufferOperation = memDBBuilder.getBufferOperation();
			logger.info("Succeed to get buffer operation : {}.", name);		
		} catch (RedissonDBException e) {
			throw new BufferException("Fail to get buffer operation.", e);
		}	
	}
	
	/**
	 * check buffer is available or not.
	 */
	public boolean checkAvailable() {
		try {
			return memDBBuilder.checkAvailability();			
		} catch (RedissonDBException e) {
			throw new BufferException("Fail to check availability.", e);
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
	
	public void updateTableMeta(TableMeta tableMeta)
	{
		try {			
			String tableName = tableMeta.getName();
			RTableOperation tableOps = bufferOperation.getTableOperation(tableName);
			if (tableOps == null) {
				throw new BindingException("Fail to get table operations : "+tableName);
			}

				
			List<String> columnNames = tableOps.getColumnNameArray();
			for (ColumnMeta column : tableMeta.getColumns()) {
				column.setIndex(-1);
			}
			int i = 0;
			for (String columnName : columnNames) {
				ColumnMeta columnMeta = tableMeta.findColumn(columnName);
				if (columnMeta == null) {
					columnMeta = new ColumnMeta();
					tableMeta.getColumns().add(columnMeta);
				}
				RedisColumnContent colDefine = tableOps.getColumnDefine(columnName);
				colDefine.getIndexType();
				columnMeta.setIndexable(colDefine.getIndexType());
				columnMeta.setName(columnName);
				//columnMeta.setType(BufferFactoryBuilder.toType(colDefine.getType()));
				columnMeta.setDbIndex(tableOps.getColumnIndex(columnName));
				columnMeta.setIndex(i++);
			}
			tableMeta.formIndexColumn();

		} catch (RedissonDBException e) {
			throw new BindingException(e.getMessage(), e);
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
	
	/**
	 * 判断buffer定义师傅有变化
	 * @param config
	 * @return
	 */
	
	public boolean isBufferDefineChanged(BufferConfig config) {
		List<TableMeta> changedTables = new ArrayList<>();
		List<String> tableNames;
		try {
			tableNames = (bufferOperation != null) ? bufferOperation
					.getTableNameArray() : new ArrayList<>();
			TableMeta[] tableMetas = config.getTableMetas();
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
			
			if (!changedTables.isEmpty()) 
				return true;	
		
		} catch (RedissonDBException e) {
			throw new BindingException(e.getMessage(), e);
		}
			
		return false;
	}

	public String getName() {
		return name;
	}
	
	private  void loadColumnMetas(TableMeta tableMeta, RBufferOperation bufferOps) throws RedissonDBException {	
		RTableOperation tableOps = bufferOps.getTableOperation(tableMeta.getName());
		List<String> colNames = tableOps.getColumnNameArray();
		for (int i = 0; i < colNames.size(); i++) {
			RedisColumnContent content = tableOps.getColumnDefine(colNames.get(i));
			ColumnMeta col = new ColumnMeta();
			col.setName(content.getStrFieldName());
			col.setIndexable(content.getIndexType());
			//col.setType(BufferFactoryBuilder.toType(content.getType()));
			tableMeta.getIndexColumns().add(col);		
		}
		tableMeta.formIndexColumn();
	}
	
	public TableMeta  createTableMeta(String tableName) {

			try {
				RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
				List<String> tables = bufferOps.getTableNameArray();
				Collections.sort(tables);
				int index = Collections.binarySearch(tables, tableName);
				if (index == -1) {
					throw new RuntimeException(String.format("Find no table:'%s', in buffer : %s", tableName, this.name));
				}
				TableMeta tableMeta = new TableMeta();
				tableMeta.setName(tableName);
				
				loadColumnMetas(tableMeta, bufferOps);			
		        return tableMeta;				
			} catch (RedissonDBException e) {
				e.printStackTrace();
				throw new RuntimeException(e);
			}			
		
	}
	
	public RTableOperation getTableOperation(TableMeta tableMeta){

		try {
			RBufferOperation bufferOps = memDBBuilder.getBufferOperation();
			return bufferOps.getTableOperation(tableMeta.getName());
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			throw new RuntimeException("Find no talbe :"+tableMeta.getKey());
		}
	}

	public void close() {
		service.disConnect();
	}
	
	
	public void removeTable(String name) throws RedissonDBException {
		memDBBuilder.getBufferBuilder().destory(name); 
		logger.info("Table removed : {} .", name);
	}

	public void removeBuffer() throws RedissonDBException {
		close();
		removeBuffer(memDBBuilder, name);
	}
	
	private void removeBuffer(RMemDBBuilder memDBBuilder, String key)
			throws RedissonDBException {
		memDBBuilder.destory();
		logger.info("Buffer destoryed : {}", key);			
	}

	public void makeBuffer(TableMeta[] tableBuilders) throws RedissonDBException {
		
		// 创建buffer
		RBufferBuilder bufferBuilder = memDBBuilder.getBufferBuilder();
		logger.info("Succeed to create buffer : {}.", name);
				
		try {
			
			//create system table : log, task
			
			if (tableBuilders != null && tableBuilders.length > 0){		
				// 创建表
				for (TableMeta tableBuilder : tableBuilders) {
					makeTable(bufferBuilder, tableBuilder);
				}
			}
			
		} finally {
			// commit buffer
			bufferBuilder.commit();
			logger.info("Succeed to commit buffer: {}.", name);
			
			initOperation();
		}
	}

	public void makeTable(RBufferBuilder bufferBuilder, TableMeta tableDefine)
			throws RedissonDBException {
		if (bufferBuilder.checkIsExists(tableDefine.getName()))
			return;	
		
		RTableBuilder tableBuilder = bufferBuilder.getTableBuilder(tableDefine
				.getName());
		
//		for (ColumnMeta c : tableDefine.getColumns()) {
//			tableBuilder.setColumn(c.getName(), typeMap.get(c.getType()), c.isIndexable());
//		}

		for (ColumnMeta c : tableDefine.getColumns()) {
			try {
			tableBuilder.setColumn(c.getName(), RedisTableColumnType.RedisTableColumnType_String, c.isIndexable());
			} catch (RedissonDBException e) {
				throw new BufferException("Fail to create colum : "+c.getName()+" for table :"+tableDefine.getName(), e);
			}
		}
		
		logger.info("Table created: {}, clumn size = {}.",
				tableDefine.getName(), tableDefine.getColumnSize());
	}
}