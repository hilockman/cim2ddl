package com.znd.bus.config;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import org.redisson.Redisson;
import org.redisson.api.RedissonClient;
import org.redisson.config.RedissonNodeConfig;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.bus.annotation.Index;
import com.znd.bus.binding.MapperRegistry;
import com.znd.bus.binding.MethodType;
import com.znd.bus.binding.ResolverUtil;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferContext;
import com.znd.bus.buffer.BufferFactoryBuilder;
import com.znd.bus.channel.ChannelConfig;
import com.znd.bus.channel.ChannelRegistry;
import com.znd.bus.exception.BindingException;
import com.znd.bus.exception.BufferException;
import com.znd.bus.executor.Executor;
import com.znd.bus.log.Log;
import com.znd.bus.log.LogBuffer;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.mapping.MappedStatement.Build;
import com.znd.bus.mapping.RawArrayBufferMapper;
import com.znd.bus.reflection.DefaultReflectorFactory;
import com.znd.bus.reflection.MetaObject;
import com.znd.bus.reflection.Reflector;
import com.znd.bus.reflection.ReflectorFactory;
import com.znd.bus.server.BusService;
import com.znd.bus.server.defaults.DefaultBusService;
import com.znd.bus.statement.RoutingStatementHandler;
import com.znd.bus.statement.StatementHandler;
import com.znd.bus.task.BufferTask;
import com.znd.bus.task.TaskQueue;
import com.znd.bus.type.TypeHandler;
import com.znd.bus.type.TypeHandlerRegistry;
import com.znd.bus.util.TimeCount;

public class BufferConfig {
	
	private String appName;
	private String id;
	private String name;
	private String alias;
	private List<String> typePackages = new ArrayList<>();
	private List<String> mapperPackages = new ArrayList<>();
	
	private RedissonNodeConfig redissonConfig;

	private RedissonClient redissonClient;
	
	private RedissonNodeConfig localConfig;

	private RedissonClient localClient; 
	
	private final List<TableMeta> tableMetas = new ArrayList<>();
	
	private final Map<String, TableMeta> metaMap = new HashMap<>();

	private final MapperRegistry mapperRegistry = new MapperRegistry();
		
	private final DefaultReflectorFactory reflectorFactory = new DefaultReflectorFactory();
	
	private final Map<String, MappedStatement> statementMap = new HashMap<>();
	
	private BufferContext bufferContext;
	
	
	private TypeHandlerRegistry typeHandlerRegistry = new TypeHandlerRegistry();
	
	
	private final Logger logger = LoggerFactory.getLogger(BufferConfig.class);

	
	private List<ChannelConfig> channels;

	
	private ChannelRegistry channelRegistry; 
	
	
	private BusService busServcie;
	
//	/**
//	 * 每次重新创建buffer
//	 */
//	public static final String CREATE = "create"; 
//	
//	/**
//	 * 不更新
//	 */
//	public static final String FALSE = "false";  
//	
//	/**
//	 * 每次检查buffer定义，如果有变化则更新
//	 */
//	public static final String UPDATE = "update"; 
	
	//更新标志,值为0， 1， 2, 缺省为update
	private CreateFlag createFlag = CreateFlag.UPDATE; 
	
	private boolean simpleModel = false;
	
	public BufferConfig() {
		
	}
	


	public String getAppName() {
		return appName;
	}
	public BufferConfig setAppName(String appName) {
		this.appName = appName;
		return this;
	}
	public String getName() {
		return name;
	}
	public BufferConfig setName(String name) {
		this.name = name;
		return this;
	}
	
	
	public String getKey() {
		return appName+"."+name;
	}
	public CreateFlag getCreateFlag() {
		return createFlag;
	}
	public void setCreateFlag(CreateFlag createFlag) {
		this.createFlag = createFlag;
	}
	
	public TableMeta[] getCachedTableMetas() {
		return tableMetas.toArray(new TableMeta[0]);
	}
	
	public List<TableMeta> getAllTableMetas() {
		List<String> tableNames =  bufferContext.getAllTableNames();
		
		List<TableMeta> tables = new ArrayList<>();
		for (String tableName : tableNames) {
			tables.add(getTableMeta(tableName));
		}
		
		return tables;
	}
	
	public List<String> getAllTableNames() {
		return bufferContext.getAllTableNames();
	}
	
	private boolean containTable(String tableName) {
		return metaMap.containsKey(tableName);
	}
	
	public void setTableMetas(TableMeta[] tableMetas) {
		if (tableMetas == null)
			return;
		
		for (int i = 0; i < tableMetas.length; i++) {
			tableMetas[i].formIndexColumn();
		}
		
		this.tableMetas.addAll(Arrays.asList(tableMetas));
	
		metaMap.clear();
		for (TableMeta meta : tableMetas) {
			metaMap.put(meta.getName(), meta);
		}
	}
	
	public TableMeta getTableMeta(String tableName) {
		if (metaMap.containsKey(tableName))
			return metaMap.get(tableName);
		
		TableMeta tableMeta = loadTableMetaFromDb(tableName);
		if (tableMeta != null) {
			tableMetas.add(tableMeta);
			metaMap.put(tableName, tableMeta);
			
		}
		return tableMeta;
	}
	
	
	private TableMeta loadTableMetaFromDb(String tableName) {	
		
		TableMeta tableMeta = new TableMeta();
		tableMeta.setName(tableName);
		
	    bufferContext.updateTableMeta(tableMeta);
		return tableMeta;
	}	
	  
	private void addType(Class<?> clazz) {
		if (clazz.isEnum()) {
			return;
		}
		
		String tableName = clazz.getSimpleName();
		if (containTable(tableName)) {
			TableMeta oldMeta = metaMap.get(tableName);
			throw new BufferConfigException(String.format("Types's name is conflict: '%s', '%s'"
					,oldMeta.getClazz() != null ? oldMeta.getClazz().toString() : oldMeta.getName()
					, clazz.toString()));
		}
		Reflector reflector = reflectorFactory.findForClass(clazz);
		TableMeta tableMeta = new TableMeta();
		tableMeta.setName(tableName);
		tableMeta.setClazz(clazz);
		
		String[] names = reflector.getGetablePropertyNames();

		//System.out.println("class : +"+clazz+", columns:["+Arrays.asList(names)+"]");
		for (String name : names) {
			ColumnMeta fieldMeta = new ColumnMeta();
			fieldMeta.setName(name);
			fieldMeta.setAlias(name);
			
			Field f;
			try {
				f = clazz.getDeclaredField(name);
			} catch (NoSuchFieldException | SecurityException e) {
				//throw new BufferConfigException("No such field or inaccessable :"+name+" in class:"+clazz, e);
				continue;
			}
			
			Index idx = f.getAnnotation(Index.class);
			fieldMeta.setIndexable(idx != null || name.equalsIgnoreCase("id") ? true : false);
			tableMeta.getColumns().add(fieldMeta);
		}
		tableMeta.formIndexColumn();
		
		tableMetas.add(tableMeta);
		metaMap.put(tableMeta.getName(), tableMeta);
	}
	
	private void createDefaultTables(Class<?> ... clazzes) {
		for (Class<?> clazz  : clazzes) {
			addType(clazz);
		}
	}	
	

	
	  public void addTypes(String packageName, Class<?> superType) {
	    ResolverUtil<Class<?>> resolverUtil = new ResolverUtil<Class<?>>();
	    resolverUtil.find(new ResolverUtil.IsA(superType), packageName.trim());
	    Set<Class<? extends Class<?>>> mapperSet = resolverUtil.getClasses();
	    for (Class<?> mapperClass : mapperSet) {
	     // System.out.println(mapperClass+"<-"+packageName);
	      addType(mapperClass);
	    }
	  }
	
	  public void addTypes(String packageName) {
	    addTypes(packageName, Object.class);
	  }
	  
	private void addTypes(){
		if (!typePackages.isEmpty()) {
			for (String typePackage : typePackages) {
				addTypes(typePackage);
			}
		}
		createDefaultTables(Log.class, BufferTask.class);
		logger.info("{} types are added to buffer : {}", tableMetas.size(), getKey());
	}
	
	private void addMappers() {	
		bufferContext.initOperation();
		
		List<String> tableNames =  bufferContext.getAllTableNames();		
		for (String tableName : tableNames) {
			mapperRegistry.addRawMapper(tableName);	
		}
		
		if (!mapperPackages.isEmpty()) {
			
			for (String mapperPackage : mapperPackages)
				addMappers(mapperPackage);
		}
		
		this.addMapper(LogBuffer.class);
		//this.addMapper(CalcJobMapper.class);
	}
	
	private void updateTables(BufferContext context) {
		for (TableMeta tableMeta : tableMetas) {
			context.updateTableMeta(tableMeta);
		}
	}
	
	public void upateTables(TableMeta tableMeta) {
		this.bufferContext.updateTableMeta(tableMeta);
		tableMeta.setInitialized(true);
	}
	 
	
	public static boolean exist(String dbid) {
		BufferConfig config = new BufferConfig();
		config.setSimpleModel(true);
		
		BufferContext context = new BufferContext.Builder(BufferFactoryBuilder.DEFAULT_APPNAME, dbid).build();
		try {
			return context.checkAvailable();
		} catch (Throwable e) {
			return false;
		}
			
	}
	
	public void buildAll() {
		if (!simpleModel) {
			addTypes();
		}
	
		try {
			bufferContext = new BufferContext.Builder(this).build();
			
			if (!simpleModel) {
			  channelRegistry = new ChannelRegistry(bufferContext);
			  busServcie = new DefaultBusService(channelRegistry);
			}
			final BufferContext context = bufferContext;
			
			
			boolean changed = false;
			if (getCreateFlag() == CreateFlag.UPDATE) { //更新buffer
				boolean createFlag = false;
				if (context.checkAvailable()) {
					context.initOperation();
					if (tableMetas != null && !tableMetas.isEmpty()) {					
						if (context.isBufferDefineChanged(this)) {// check buffer define changed or not ?
							logger.info("Buffer config changed, buffer definition will be removed : {}. ", getKey());
							// remove buffer
							context.removeBuffer();
							createFlag = true;
						}
					}	
				} else {
					createFlag = true;
				}
				
									
				if (createFlag) {
					logger.info("Buffer definition will be created : {}. ", getKey());
					// make buffer
					context.makeBuffer(tableMetas);
				}
				
				changed = createFlag;
				
			} else if (getCreateFlag()  == CreateFlag.CREATE) {
				// remove buffer
				logger.info("Buffer definition will be removed : {}. ", getKey());
				context.removeBuffer();
				
				// make buffer
				logger.info("Buffer definition will be created : {}. ", getKey());
				context.makeBuffer(tableMetas);
			} else { //check buffer is available or not
				if (!context.checkAvailable()) {
					throw new BufferException("Buffer definition is not available, create buffer definition first : "+ getName());
				}			
			}
			
			
//			new TimeCount.Builder()
//			.name("update %d table(s)", tableMetas.size())
//			.logger(logger).runnable(()->{
//						updateTables(context);
//
//				}
//			).build().exec();
			
				
			addMappers();
			if (!simpleModel) {
				addChannels();
			    buildClient();
			}
		} catch (RedissonDBException e) { //低层redisdatabus出错
			throw new BufferConfigException(e.getMessage(), e);
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(0);
		} finally {
			logger.info("Succeed to build buffer : "+getKey());
		}
	}

	
	private void buildClient() {
		if (redissonConfig != null)
		 redissonClient = Redisson.create(redissonConfig);
		
		if (localConfig != null) {
			localClient = Redisson.create(localConfig);
		}
	}



	private void addChannels() {
		channelRegistry.addChannels(channels);
	}

//	public void add(TableMeta tableMeta) {
//		tableMetas.add(tableMeta);
//		metaMap.put(tableMeta.getName(), tableMeta);
//	}
	
	public String getAlias() {
		return alias;
	}
	public void setAlias(String alias) {
		this.alias = alias;
	}
	
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}	
	
	
	public <T> T getMapper(Class<T> type, Buffer buffer) {
		return mapperRegistry.getMapper(type, buffer);
	}
	
	public RawArrayBufferMapper getMapper(Class<RawArrayBufferMapper> type,
			String tableName, Buffer buffer) {
		return mapperRegistry.getMapper(tableName, buffer);
	}
	
	
	public void addMappers(String packageName, Class<?> superType) {
		mapperRegistry.addMappers(packageName, superType);
	}

	public void addMappers(String packageName) {
	    mapperRegistry.addMappers(packageName);
	}
	
	public <T> void addMapper(Class<T> type) {
	    mapperRegistry.addMapper(type);
	}

	public Collection<Class<?> > getMappers() {

		
		return mapperRegistry.getMappers();
	}
	public MappedStatement getMappedStatement(String statement) {
		MappedStatement mappedStatement = statementMap.get(statement);
		return mappedStatement;
	}
	
	public static String resolveTableName(Type sourceType) {
		if (sourceType instanceof ParameterizedType) {
			ParameterizedType parameterizedType = (ParameterizedType)sourceType;
			Type[] typeArgs = parameterizedType.getActualTypeArguments();
		    if (typeArgs.length > 0) {
		    	return resolveTypeName(typeArgs[0]);
		    }
		} else if (sourceType instanceof Class) {
			String name = ((Class<?>)sourceType).getSimpleName();
			
			if (name.endsWith("Mapper")) {
				return name.substring(0, name.length() - 6);
			} else if (name.endsWith("Buffer")) {
				return name.substring(0, name.length() - 6);
			}
		}
		
		return null;
		 
	}
	
	private static String resolveTypeName(Type type) {
		if (type instanceof ParameterizedType) {
			ParameterizedType parameterizedType = (ParameterizedType)type;
			Type[] typeArgs = parameterizedType.getActualTypeArguments();
		    if (typeArgs.length > 0) {
		    	return resolveTypeName(typeArgs[0]);
		    }
		} else if (type instanceof Class) {
			return ((Class<?>)type).getSimpleName();
		} 
		
		return null;
		
	}
	
	public MappedStatement initMappedStatement(MethodType type, String id, Method method, Class<?> returnType, Class<?> sourceType, String tableName) {
	
		if (tableName == null)
		    tableName = resolveTableName(sourceType);
		
		if (tableName == null || tableName.isEmpty()) {
			throw new BindingException("Informat mapper name , not endsWith 'mapper': "+sourceType.getName());
		}
//		Class<?> declaringClass = method.getDeclaringClass();
//		
//		String className = declaringClasmappedStatements.getSimpleName();
//		if (!className.endsWith("Mapper")) {
//			
//			throw new BindingException("Informat mapper name , not endsWith 'mapper': "+declaringClass.getName());
//		}
//		
//		String tableName = className.substring(0, className.length() - 6);
		
		Build builder = new MappedStatement.Build(this, type, id, method, returnType, tableName, sourceType);
		MappedStatement mappedStatement = builder.build();
		statementMap.put(id, mappedStatement);
		
		return mappedStatement;
	}
	

	public Reflector getReflector(Class<?> type) {
		return reflectorFactory.findForClass(type);
	}
	

	public void setTypePackage(String typePackage) {
		if (typePackage != null && !typePackage.isEmpty())
			this.typePackages.addAll(Arrays.asList(typePackage.split(";|,")));
	}

	public void setMapperPackage(String mapperPackage) {
		if (mapperPackage != null && !mapperPackage.isEmpty()) {
		    this.mapperPackages.addAll(Arrays.asList(mapperPackage.split(";|,")));;
		}
	}
	public MetaObject newMetaObject(Object object) {
		return MetaObject.forObject(object, reflectorFactory);
	}
	
	public TypeHandler<?> getTypeHandler(Class<?> type) {
		return typeHandlerRegistry.getTypeHandler(type);
	}
	
	public TypeHandlerRegistry getTypeHandlerRegistry() {
		return typeHandlerRegistry;
	}
	
	public boolean hasTypeHandler(Class<?> type) {
		return typeHandlerRegistry.hasTypeHandler(type);
	}
	public BufferContext getBufferContext() {
		return bufferContext;
	}
	public ReflectorFactory getReflectorFactory() {
		return reflectorFactory;
	}
	
	public StatementHandler newStatementHandler(Executor executor, MappedStatement mappedStatement, Object parameter) {
		return new RoutingStatementHandler(executor, mappedStatement, parameter);
	}
	
	public List<ChannelConfig> getChannels() {
		return channels;
	}

	public void setChannels(List<ChannelConfig> channels) {
		this.channels = channels;
	}

	public ChannelRegistry getChannelRegistry() {
		return channelRegistry;
	}

	public <T> TaskQueue<T> getTaskList(String id) {
		if (redissonClient == null)
			return null;
		
		return new TaskQueue<T>(redissonClient, id);
	}
	
	public void setRedissonConfig(RedissonNodeConfig redissonConfig) {
		this.redissonConfig = redissonConfig;
	}

	public void setParent(BufferConfig defaultConfig) {
		if (defaultConfig == null)
			return;
		
		this.redissonClient = defaultConfig.redissonClient;
		this.localClient = defaultConfig.localClient;
	}



	public RedissonClient getRedissonClient() {
		return redissonClient;
	}



	public RedissonNodeConfig getLocalConfig() {
		return localConfig;
	}



	public void setLocalConfig(RedissonNodeConfig localConfig) {
		this.localConfig = localConfig;
	}



	public RedissonClient getLocalClient() {
		return localClient;
	}

	public void setLocalClient(RedissonClient localClient) {
		this.localClient = localClient;
	}
	
	public BusService getBuservice()
	{
		return busServcie;	
	}



	public boolean isSimpleModel() {
		return simpleModel;
	}



	public void setSimpleModel(boolean simpleModel) {
		this.simpleModel = simpleModel;
	}
	
}
