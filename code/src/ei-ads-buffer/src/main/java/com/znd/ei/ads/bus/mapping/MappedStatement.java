package com.znd.ei.ads.bus.mapping;

import java.util.List;

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

		
	  public static class Build {
		  private MappedStatement mappedStatement = new MappedStatement();
		  
		  public Build(BufferConfig config, String id, Class<?> resultType, String tableName) {
			  mappedStatement.tableName = tableName;
			  mappedStatement.id = id;
			  mappedStatement.config = config;
			  mappedStatement.resultType = resultType;
			  
		  }
		  
		  public MappedStatement build() {
			  if (mappedStatement.resultType != null) {
				  mappedStatement.resultSetHandler = new ObjectResultSetHandler<Object>(mappedStatement.resultType);			  
			  }
			  
			  if (mappedStatement.tableName != null) {
				  mappedStatement.tableMeta = mappedStatement.config.getTable(mappedStatement.tableName);
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

}
