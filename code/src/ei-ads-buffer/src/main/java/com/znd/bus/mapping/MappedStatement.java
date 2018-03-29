package com.znd.bus.mapping;

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Map;

import com.znd.bus.binding.MethodType;
import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.config.TableMeta;
import com.znd.bus.mapping.impl.ObjectResultSetHandler;
import com.znd.bus.reflection.Reflector;
import com.znd.bus.statement.DeleteStatementHandler;
import com.znd.bus.statement.StatementHandler;
import com.znd.bus.type.TypeHandler;

public class MappedStatement {
	
	  public static void main(String [] args) {
		  Class<?> type = args.getClass();
		  if (type.isArray()) {
			  System.out.println("Find string[] type!");
		  }
	  }
	  private String id;
	  private Class<?> resultType;
	  private ResultSetHandler<?> resultSetHandler = ResultSetHandler.DEFAULT_HANDLER;
	  private BufferConfig config;
	  private String tableName;
	  private TableMeta tableMeta;
	  private MethodType type;
	  
	 // private StatementHandler parameterHandler = null;

	  private List<ParameterMapping> pamameterMappings = new ArrayList<>();
	  
	  private ParameterMapping[] normalProperties;
	  private ParameterMapping[] conditionProperties;
	  
	  private Map<String, Integer> columnIndexMap;
		
	  public static class Build {
		  private MappedStatement mappedStatement = new MappedStatement();
		  private final Method method;
		  public Build(BufferConfig config, MethodType type, String id, Method method, Class<?> resultType, String tableName) {
			  mappedStatement.tableName = tableName;
			  mappedStatement.id = id;
			  mappedStatement.config = config;
			  mappedStatement.resultType = resultType;
			  mappedStatement.type = type;
			  this.method = method;
			  
		  }
		  
		  private void addParameter(String argName, Class<?> argType) {
			  TypeHandler<?> typeHandler = mappedStatement.config.getTypeHandler(argType);
			  if (typeHandler != null) {
				  ColumnMeta column = mappedStatement.tableMeta.findColumn(argName);
				  if (column == null) 
					  throw new MappingError(String.format("Unknow argName : %s.%s.%s", method.getDeclaringClass().getName(), method.getName(), argName));
				  ParameterMapping parameterMapping = new ParameterMapping(argName,column.getIndex(), column.getDbIndex(), typeHandler, column.isIndexable());
				  mappedStatement.pamameterMappings.add(parameterMapping);
			  } else {
				  throw new MappingError(String.format("Unknow argType : %s.%s.%s argType=%s", method.getDeclaringClass().getName(), method.getName(), argName, argType.getName()));
			  }
		  }
		  
		  private void initParameterMapping(Class<?> clazz) {
			  Reflector reflector = mappedStatement.config.getReflector(clazz);
			  String[] properties = reflector.getGetablePropertyNames();					  
			  for (int i = 0; i < properties.length; i++) {
				  String property = properties[i];

				  addParameter(property, reflector.getGetterType(property));
			  } 
		  }
		  
		  public MappedStatement build() {

			  
			  if (mappedStatement.tableName != null) {
				  mappedStatement.tableMeta = mappedStatement.config.getTableMeta(mappedStatement.tableName);
				  if (mappedStatement.tableMeta == null) {
					  throw new MappingError("Unknow table name : "+mappedStatement.tableName);
				  }
			  }
			  

			  mappedStatement.columnIndexMap = mappedStatement.tableMeta.getColumnIndexMap();
			  
			  Parameter[] params = method.getParameters();
			  if (params.length == 1) {
				  Parameter param = params[0];
				  String argName = param.getName();
				  Class<?> argType = param.getType();
				  
				  if (mappedStatement.config.hasTypeHandler(argType))
					  addParameter(argName, argType);
				  else if (argType.isArray()) {
					  int i = 0;
					  for (; i < mappedStatement.tableMeta.getColumnSize(); i++) {
						  addParameter("param"+i, String.class);
						  i++;
					  }
				  } else if (Collection.class.isAssignableFrom(argType)) {
					  
					  Type[] typeArgs = ((ParameterizedType)param.getParameterizedType()).getActualTypeArguments();
					  initParameterMapping((Class<?>)typeArgs[0]);
				  } else {
					   initParameterMapping(argType);
				  }
			  } else {
				  for (int i = 0; i < params.length; i++) {
					  Parameter param = params[i];
					  String argName = param.getName();
					  Class<?> argType = param.getType();
					  addParameter(argName, argType);
				  }
			  }
			  
			  List<ParameterMapping> normalParams = new ArrayList<>();
			  List<ParameterMapping> conditionParams = new ArrayList<>();
			  for (ParameterMapping paramaterMapping : mappedStatement.pamameterMappings) {
				  if (paramaterMapping.isIndexable())
					  conditionParams.add(paramaterMapping);
				  else
					  normalParams.add(paramaterMapping);
			  }
			  
			  mappedStatement.normalProperties = normalParams.toArray(new ParameterMapping[0]);
			  mappedStatement.conditionProperties = conditionParams.toArray(new ParameterMapping[0]);
			  
			  if (mappedStatement.resultType != null) {
				  mappedStatement.resultSetHandler = new ObjectResultSetHandler<Object>(mappedStatement.resultType, 
						  mappedStatement.config.getReflectorFactory(), 
						  mappedStatement.config.getTypeHandlerRegistry(),
						  mappedStatement.getColumnIndexMap());			  
			  }
			  
			  return mappedStatement;
		  }
	  }
	  
	  
	  @SuppressWarnings("unchecked")
	  public <T> List<T> handler(ResultSet resultSet) {
		  return (List<T>) resultSetHandler.handle(resultSet);
	  }
	  
	public String getId() {
		return id;
	}
	public Class<?> getResultType() {
		return resultType;
	}
	public ResultSetHandler<?> getResultSetHandler() {
		return resultSetHandler;
	}
	public BufferConfig getConfig() {
		return config;
	}



	public TableMeta getTableMeta() {
		return tableMeta;
	}

	public ParameterMapping[] getProperties() {
		return this.pamameterMappings.toArray(new ParameterMapping[0]);
	}
	public ParameterMapping[] getNormalProperties() {
		return normalProperties;
	}

	public ParameterMapping[] getConditionProperties() {
		return conditionProperties;
	}

	public Map<String, Integer> getColumnIndexMap() {
		return columnIndexMap;
	}

	public MethodType getType() {
		return type;
	}

	

}
