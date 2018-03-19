package com.znd.ei.ads.bus.config;

import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.ZhongND.RedisDataBus.ServiceFactory;
import com.ZhongND.RedisDataBus.Api.DFService;
import com.ZhongND.RedisDataBus.Api.RBufferOperation;
import com.ZhongND.RedisDataBus.Api.RMemDBApi;
import com.ZhongND.RedisDataBus.Api.RMemDBBuilder;
import com.ZhongND.RedisDataBus.Api.RTableOperation;
import com.ZhongND.RedisDataBus.Exception.RedissonDBException;
import com.ZhongND.RedisDataBus.Object.RedisColumnContent;
import com.znd.ei.ads.bus.binding.BindingException;
import com.znd.ei.ads.bus.binding.MapperRegistry;
import com.znd.ei.ads.bus.buffer.Buffer;
import com.znd.ei.ads.bus.buffer.BufferFactoryBuilder;
import com.znd.ei.ads.bus.mapping.MappedStatement;
import com.znd.ei.ads.bus.mapping.MappedStatement.Build;
import com.znd.ei.ads.bus.mapping.ObjectReflector;

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
		
	private Map<Class<?>, ObjectReflector> reflectorMap = new HashMap<>();
	
	private Map<String, MappedStatement> statementMap = new HashMap<>();
	
	/**
	 * 每次重新创建buffer
	 */
	public static final Integer CREATE = 0; 
	
	/**
	 * 不更新
	 */
	public static final Integer FALSE = 1;  
	
	/**
	 * 每次检查buffer定义，如果有变化则更新
	 */
	public static final Integer UPDATE = 2; 
	
	//更新标志,值为0， 1， 2, 缺省为update
	private int createFlag = UPDATE; 
	

	
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
	public int getCreateFlag() {
		return createFlag;
	}
	public void setCreateFlag(int createFlag) {
		this.createFlag = createFlag;
	}
	
	public TableMeta[] getTableMetas() {
		return tableMetas.toArray(new TableMeta[0]);
	}
	
	public void setTableMetas(TableMeta[] tableMetas) {
		if (tableMetas == null)
			return;
		
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
		try {
			DFService service = ServiceFactory.getService();
			RMemDBApi memDBApi = service.connect(getAppName());
			
			RMemDBBuilder memDBBuilder = memDBApi
					.getRMemDBBuilder(getName());
			boolean available = memDBBuilder.checkAvailability();
			if (!available) {
				throw new BindingException("Fail to call check memDb availability : "+getName());
			}
			
			RBufferOperation bufferOperation = memDBBuilder
					.getBufferOperation();
			RTableOperation tableOps = bufferOperation.getTableOperation(tableName);
			if (tableOps == null) {
				throw new BindingException("Fail to get table operations : "+tableName);
			}
			
			TableMeta tableMeta = new TableMeta();
			tableMeta.setName(tableName);
			
		
			List<String> columnNames = tableOps.getColumnNameArray();
			for (String columnName : columnNames) {
				ColumnMeta columnMeta = new ColumnMeta();
				RedisColumnContent colDefine = tableOps.getColumnDefine(columnName);
				colDefine.getIndexType();
				columnMeta.setIndexable(colDefine.getIndexType());
				columnMeta.setName(columnName);
				columnMeta.setType(BufferFactoryBuilder.toType(colDefine.getType()));
				columnMeta.setDbIndex(tableOps.getColumnIndex(columnName));
				tableMeta.getColumns().add(columnMeta);
			}
			tableMeta.formIndexColumn();
			return tableMeta;
		} catch (RedissonDBException e) {
			throw new BindingException(e.getMessage(), e);
		}

	}
	public void build() {
		for (int i = 0; i < tableMetas.size(); i++) {
			tableMetas.get(i).formIndexColumn();
		}
		
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
	
	public MappedStatement initMappedStatement(String id, Method method, Class<?> returnType) {
	
		Class<?> declaringClass = method.getDeclaringClass();
		String className = declaringClass.getSimpleName();
		if (!className.endsWith("Mapper")) {
			throw new BindingException("Informat mapper name , not endsWith 'mapper': "+declaringClass.getName());
		}
		
		String tableName = className.substring(0, className.length() - 6);
		
		Build builder = new MappedStatement.Build(this, id, method, returnType, tableName);
		MappedStatement mappedStatement = builder.build();
		statementMap.put(id, mappedStatement);
		
		return getMappedStatement(id);
	}
	

	public ObjectReflector getReflector(Class<?> type) {
		ObjectReflector reflectory = reflectorMap.get(type);
		if (reflectory == null) {
			reflectory = createReflector(type);
			reflectorMap.put(type, reflectory);
		}
		
		return reflectory;
	}
	
	private ObjectReflector createReflector(Class<?> type) {
		return new ObjectReflector(type);
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
		// TODO Auto-generated method stub
		return null;
	}
}
