package com.znd.bus.config;

import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.znd.bus.annotation.Index;
import com.znd.bus.binding.BindingException;
import com.znd.bus.binding.MapperRegistry;
import com.znd.bus.binding.MethodType;
import com.znd.bus.binding.ResolverUtil;
import com.znd.bus.buffer.Buffer;
import com.znd.bus.buffer.BufferContext;
import com.znd.bus.buffer.BufferException;
import com.znd.bus.executor.Executor;
import com.znd.bus.log.Log;
import com.znd.bus.log.LogMapper;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.mapping.MappedStatement.Build;
import com.znd.bus.reflection.DefaultReflectorFactory;
import com.znd.bus.reflection.MetaObject;
import com.znd.bus.reflection.Reflector;
import com.znd.bus.reflection.ReflectorFactory;
import com.znd.bus.statement.RoutingStatementHandler;
import com.znd.bus.statement.StatementHandler;
import com.znd.bus.task.CalcJob;
import com.znd.bus.task.CalcJobMapper;
import com.znd.bus.type.TypeHandler;
import com.znd.bus.type.TypeHandlerRegistry;

public class BufferConfig {
	
	private String appName;
	private String id;
	private String name;
	private String alias;
	private String typePackage;
	private String mapperPackage;
	
	private final List<TableMeta> tableMetas = new ArrayList<>();
	
	private final Map<String, TableMeta> metaMap = new HashMap<>();

	private final MapperRegistry mapperRegistry = new MapperRegistry(this);
		
	private final DefaultReflectorFactory reflectorFactory = new DefaultReflectorFactory();
	
	private final Map<String, MappedStatement> statementMap = new HashMap<>();
	
	private BufferContext bufferContext;
	
	
	private TypeHandlerRegistry typeHandlerRegistry = new TypeHandlerRegistry();
	
	
	private final Logger logger = LoggerFactory.getLogger(BufferConfig.class);

	
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
	
	public TableMeta[] getTableMetas() {
		return tableMetas.toArray(new TableMeta[0]);
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
		String tableName = clazz.getSimpleName();
		if (containTable(tableName))
			return;
		Reflector reflector = reflectorFactory.findForClass(clazz);
		TableMeta tableMeta = new TableMeta();
		tableMeta.setName(tableName);
		
		String[] names = reflector.getGetablePropertyNames();

		for (String name : names) {
			ColumnMeta fieldMeta = new ColumnMeta();
			fieldMeta.setName(name);
			fieldMeta.setAlias(name);
			
			Field f;
			try {
				f = clazz.getDeclaredField(name);
			} catch (NoSuchFieldException | SecurityException e) {
				throw new BufferConfigException("No such field or inaccessable :"+name+" in class:"+clazz, e);
			}
			
			Index idx = f.getAnnotation(Index.class);
			fieldMeta.setIndexable(idx != null? true : false);
			tableMeta.getColumns().add(fieldMeta);
		}
		tableMeta.formIndexColumn();
		
		tableMetas.add(tableMeta);
	}
	
	private void createDefaultTables(Class<?> ... clazzes) {
		for (Class<?> clazz  : clazzes) {
			addType(clazz);
		}
	}	
	

	  public void addTypes(String packageName, Class<?> superType) {
	    ResolverUtil<Class<?>> resolverUtil = new ResolverUtil<Class<?>>();
	    resolverUtil.find(new ResolverUtil.IsA(superType), packageName);
	    Set<Class<? extends Class<?>>> mapperSet = resolverUtil.getClasses();
	    for (Class<?> mapperClass : mapperSet) {
	      addType(mapperClass);
	    }
	  }


	  public void addTypes(String packageName) {
	    addTypes(packageName, Object.class);
	  }
	  
	private void addTypes(){
		if (typePackage != null && !typePackage.isEmpty())
			addTypes(this.typePackage);
		createDefaultTables(Log.class, CalcJob.class);
	}
	
	private void addMappers() {	
		bufferContext.initOperation();
		if (mapperPackage != null)
			addMappers(mapperPackage);
		
		this.addMapper(LogMapper.class);
		this.addMapper(CalcJobMapper.class);
	}
	
	public void buildAll() {
		addTypes();
	
		try {
			BufferContext context = getBufferContext();
			TableMeta[] tableMetas = getTableMetas();
						
			if (getCreateFlag() == CreateFlag.UPDATE) { //更新buffer
				boolean createFlag = false;
				if (context.checkAvailable()) {
					context.initOperation();
					if (tableMetas != null && tableMetas.length > 0) {					
						if (context.isBufferDefineChanged(this)) {// check buffer define changed or not ?
							logger.info("Buffer config changed, will be removed : {}. ", getKey());
							// remove buffer
							context.removeBuffer();
							createFlag = true;
						}
					}	
				} else {
					createFlag = true;
				}
				
									
				if (createFlag) {
					logger.info("Buffer will be created : {}. ", getKey());
					// make buffer
					context.makeBuffer(tableMetas);
				}
				
			} else if (getCreateFlag()  == CreateFlag.CREATE) {
				// remove buffer
				logger.info("Buffer config will be removed : {}. ", getKey());
				context.removeBuffer();
				
				// make buffer
				logger.info("Buffer will be created : {}. ", getKey());
				context.makeBuffer(tableMetas);
			} else { //check buffer is available or not
				if (!context.checkAvailable()) {
					throw new BufferException("Buffer is not available, create buffer first : "+ getName());
				}			
			}
			
			for (TableMeta tableMeta : tableMetas) {
				context.updateTableMeta(tableMeta);
			}
		
			addMappers();
		} catch (RedissonDBException e) { //低层redisdatabus出错
			throw new BufferConfigException(e.getMessage(), e);
		} finally {
			logger.info("Succeed to build buffer : "+getKey());
		}
	}

	
	public void add(TableMeta tableMeta) {
		tableMetas.add(tableMeta);
		metaMap.put(tableMeta.getName(), tableMeta);
	}
	
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
	
	public void addMappers(String packageName, Class<?> superType) {
		    mapperRegistry.addMappers(packageName, superType);
	}

	  public void addMappers(String packageName) {
	    mapperRegistry.addMappers(packageName);
	  }
	
	  public <T> void addMapper(Class<T> type) {
	    mapperRegistry.addMapper(type);
	  }
		  
	public MappedStatement getMappedStatement(String statement) {
		MappedStatement mappedStatement = statementMap.get(statement);
		return mappedStatement;
	}
	
	public MappedStatement initMappedStatement(MethodType type, String id, Method method, Class<?> returnType) {
	
		Class<?> declaringClass = method.getDeclaringClass();
		String className = declaringClass.getSimpleName();
		if (!className.endsWith("Mapper")) {
			throw new BindingException("Informat mapper name , not endsWith 'mapper': "+declaringClass.getName());
		}
		
		String tableName = className.substring(0, className.length() - 6);
		
		Build builder = new MappedStatement.Build(this, type, id, method, returnType, tableName);
		MappedStatement mappedStatement = builder.build();
		statementMap.put(id, mappedStatement);
		
		return getMappedStatement(id);
	}
	

	public Reflector getReflector(Class<?> type) {
		return reflectorFactory.findForClass(type);
	}
	

	public String getTypePackage() {
		return typePackage;
	}
	public void setTypePackage(String typePackage) {
		this.typePackage = typePackage;
	}
	public String getMapperPackage() {
		return mapperPackage;
	}
	public void setMapperPackage(String mapperPackage) {
		this.mapperPackage = mapperPackage;
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
		if (bufferContext == null)
			bufferContext = new BufferContext.Builder(this).build();
		return bufferContext;
	}
	public ReflectorFactory getReflectorFactory() {
		return reflectorFactory;
	}
	
	public StatementHandler newStatementHandler(Executor executor, MappedStatement mappedStatement, Object parameter) {
		return new RoutingStatementHandler(executor, mappedStatement, parameter);
	}
}
