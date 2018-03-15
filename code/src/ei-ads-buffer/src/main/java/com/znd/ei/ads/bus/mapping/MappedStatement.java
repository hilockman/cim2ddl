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
	  private TableMeta tableMeta;
	  
	  private ParamerterHandler parameterHandler = ParamerterHandler.DefaultParameterHandler;

		
	  public static class Build {
		  private MappedStatement mappedStatement = new MappedStatement();
		  
		  public Build(BufferConfig config, String id, Class<?> resultType) {
			  
			  mappedStatement.id = id;
			  mappedStatement.config = config;
			  mappedStatement.resultType = resultType;
			  
		  }
		  
		  public MappedStatement build() {
			  if (mappedStatement.resultType != null) {
				  mappedStatement.resultSetHandler = new ObjectResultSetHandler<Object>(mappedStatement.resultType);
				  
				  
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

		public ParamerterHandler getParameterHandler() {
			return parameterHandler;
		}

		public TableMeta getTableMeta() {
			return tableMeta;
		}

}
