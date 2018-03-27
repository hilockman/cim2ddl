package com.znd.ei.ads.bus.config;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.znd.ei.ads.bus.binding.BindingException;
import com.znd.ei.ads.bus.binding.MapperRegistry;
import com.znd.ei.ads.bus.binding.MethodType;
import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.executor.Executor;
import com.znd.ei.ads.bus.mapping.DefaultReflectorFactory;
import com.znd.ei.ads.bus.mapping.MappedStatement;
import com.znd.ei.ads.bus.mapping.MappedStatement.Build;
import com.znd.ei.ads.bus.reflection.MetaObject;
import com.znd.ei.ads.bus.reflection.Reflector;
import com.znd.ei.ads.bus.reflection.ReflectorFactory;
import com.znd.ei.ads.bus.statement.RoutingStatementHandler;
import com.znd.ei.ads.bus.statement.StatementHandler;
import com.znd.ei.ads.bus.type.TypeHandler;
import com.znd.ei.ads.bus.type.TypeHandlerRegistry;

public class BufferConfig {
	
	private String appName;
	private String id;
	private String name;
	private String alias;
	private String typePackage;
	private String mapperPackage;
	
	private List<TableMeta> tableMetas = new ArrayList<>();
	
	private Map<String, TableMeta> metaMap = new HashMap<>();

	private MapperRegistry mapperRegistry = new MapperRegistry(this);
		
	private DefaultReflectorFactory reflectorFactory = new DefaultReflectorFactory();
	
	private Map<String, MappedStatement> statementMap = new HashMap<>();
	
	private BufferContext bufferContext;
	
	
	private TypeHandlerRegistry typeHandlerRegistry = new TypeHandlerRegistry();
	
	/**
	 * 每次重新创建buffer
	 */
	public static final String CREATE = "create"; 
	
	/**
	 * 不更新
	 */
	public static final String FALSE = "false";  
	
	/**
	 * 每次检查buffer定义，如果有变化则更新
	 */
	public static final String UPDATE = "update"; 
	
	//更新标志,值为0， 1， 2, 缺省为update
	private String createFlag = "upate"; 
	
	
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
	public String getCreateFlag() {
		return createFlag;
	}
	public void setCreateFlag(String createFlag) {
		this.createFlag = createFlag;
	}
	
	public TableMeta[] getTableMetas() {
		return tableMetas.toArray(new TableMeta[0]);
	}
	
	public void setTableMetas(TableMeta[] tableMetas) {
		if (tableMetas == null)
			return;
		
		for (int i = 0; i < tableMetas.length; i++) {
			tableMetas[i].formIndexColumn();
		}
		
		this.tableMetas = Arrays.asList(tableMetas);
	
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
	
	public void build() {

		
		
			
		if (mapperPackage != null)
			addMappers(mapperPackage);
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
