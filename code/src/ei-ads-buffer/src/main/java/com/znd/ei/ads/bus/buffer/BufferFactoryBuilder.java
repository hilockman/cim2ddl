package com.znd.ei.ads.bus.buffer;

import java.util.HashMap;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Enum.RedisTableColumnType;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.ei.ads.bus.buffer.defaults.DefaultBufferFactory;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.BufferContext;
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

	
	public BufferFactory build(BufferConfig config){	
		try {
			
			
			BufferContext context = config.getBufferContext();

			TableMeta[] tableMetas = config.getTableMetas();
						
			if (config.getCreateFlag() == "update") { //更新buffer
				boolean createFlag = false;			
				if (tableMetas != null && tableMetas.length > 0) {
					
					if (context.isBufferDefineChanged(config)) {// check buffer define changed or not ?
						logger.info("Buffer config changed, will be removed : {}. ", config.getKey());
						// remove buffer
						context.removeBuffer();
						createFlag = true;
					}
				}
									
				if (createFlag) {
					logger.info("Buffer will be created : {}. ", config.getKey());
					// make buffer
					context.makeBuffer(tableMetas);
				}
				
			} else if (config.getCreateFlag() == "create") {
				// remove buffer
				logger.info("Buffer config will be removed : {}. ", config.getKey());
				context.removeBuffer();
				
				// make buffer
				logger.info("Buffer will be created : {}. ", config.getKey());
				context.makeBuffer(tableMetas);
			}
			
			for (TableMeta tableMeta : tableMetas) {
				context.updateTableMeta(tableMeta);
			}
			
			config.build();
			return new DefaultBufferFactory(config);
		
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


}
