package com.znd.bus.buffer;

import com.znd.bus.buffer.defaults.DefaultBufferFactory;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.CreateFlag;

public class BufferFactoryBuilder {

	public static final String DEFAULT_APPNAME = "pr";
	public static final String DEFAULT_BUFFERNAME = "CommonBuffer";

	public static BufferConfig getDefaultConfig() {
		BufferConfig config = new BufferConfig();
		config.setAppName(DEFAULT_APPNAME);
		config.setName(DEFAULT_BUFFERNAME);
		return config;
	}

//	private static final HashMap<String, RedisTableColumnType> typeMap = new HashMap<>();
//	private static final HashMap<RedisTableColumnType, String> inverseTypeMap = new HashMap<>();
//
//
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
//	static {		
//		typeMap.put(INT, RedisTableColumnType.RedisTableColumnType_int);
//		typeMap.put(BOOLEAN, RedisTableColumnType.RedisTableColumnType_boolean);
//		typeMap.put(STRING, RedisTableColumnType.RedisTableColumnType_String);
//		typeMap.put(DOUBLE, RedisTableColumnType.RedisTableColumnType_double);
//		typeMap.put(BYTE, RedisTableColumnType.RedisTableColumnType_byte);
//		typeMap.put(FLOAT, RedisTableColumnType.RedisTableColumnType_float);
//		typeMap.put(LONG, RedisTableColumnType.RedisTableColumnType_long);
//		typeMap.put(SHORT, RedisTableColumnType.RedisTableColumnType_short);
//		typeMap.put(DATE, RedisTableColumnType.RedisTableColumnType_long);
//		typeMap.put(TIME, RedisTableColumnType.RedisTableColumnType_long);
//	
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_int, INT);
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_boolean, BOOLEAN);
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_String, STRING);
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_double, DOUBLE);
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_byte, BYTE);
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_float, FLOAT);
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_long, LONG);
//		inverseTypeMap.put(RedisTableColumnType.RedisTableColumnType_short, SHORT);
//	}
	
	
//	public static RedisTableColumnType toType(String type) {
//		return typeMap.get(type);
//	}
	
	
//	public static  String toType(RedisTableColumnType type) {
//		return inverseTypeMap.get(type);
//	}
	
	public BufferFactory build(BufferConfig config){	
		return new DefaultBufferFactory(config);		
	}

	

	public BufferFactory build(String name, CreateFlag createFlag, String typePackage, String mapperPackage, BufferConfig defaultConfig){
		BufferConfig config = new BufferConfig();
		config.setAppName(DEFAULT_APPNAME);
		config.setName(name);
		config.setTypePackage(typePackage);
		config.setMapperPackage(mapperPackage);
		config.setCreateFlag(createFlag);	
		config.setParent(defaultConfig);
		config.setSimpleModel(defaultConfig.isSimpleModel());
		
		return new DefaultBufferFactory(config);		
	}

}
