package com.znd.ei.ads.bus.mapping;

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.ArrayList;
import java.util.List;

import com.znd.ei.ads.bus.binding.BindingException;
import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.TableMeta;
import com.znd.ei.ads.bus.mapping.impl.ObjectResultSetHandler;

public class MappedStatement {
	  private String id;
	  private Class<?> resultType;
	  private ResultSetHandler<?> resultSetHandler = ResultSetHandler.DEFAULT_HANDLER;
	  private BufferConfig config;
	  private String tableName;
	  private TableMeta tableMeta;
	  
	  private ParameterHandler parameterHandler = ParameterHandler.DefaultParameterHandler;

	  private List<ParameterMapping> pamameterMappings = new ArrayList<>();
		
	  public static class Build {
		  private MappedStatement mappedStatement = new MappedStatement();
		  private final Method method;
		  public Build(BufferConfig config, String id, Method method, Class<?> resultType, String tableName) {
			  mappedStatement.tableName = tableName;
			  mappedStatement.id = id;
			  mappedStatement.config = config;
			  mappedStatement.resultType = resultType;
			  this.method = method;
			  
		  }
		  
		  public MappedStatement build() {
			  if (mappedStatement.resultType != null) {
				  mappedStatement.resultSetHandler = new ObjectResultSetHandler<Object>(mappedStatement.resultType);			  
			  }
			  
			  if (mappedStatement.tableName != null) {
				  mappedStatement.tableMeta = mappedStatement.config.getTableMeta(mappedStatement.tableName);
				  if (mappedStatement.tableMeta == null) {
					  throw new BindingException("Unknow table name : "+mappedStatement.tableName);
				  }
			  }
			  
			  Parameter[] params = method.getParameters();
			  for (int i = 0; i < params.length; i++) {
				  Parameter param = params[i];
				  String argName = param.getName();
				  Class<?> argType = param.getType();
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

		public ParameterHandler getParameterHandler() {
			return parameterHandler;
		}

		public TableMeta getTableMeta() {
			return tableMeta;
		}

		public String[] getKeyProperties() {
			// TODO Auto-generated method stub
			return null;
		}

}
