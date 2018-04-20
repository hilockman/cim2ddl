package com.znd.bus.statement;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.ColumnMeta;
import com.znd.bus.config.TableMeta;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.mapping.ParameterMapping;
import com.znd.bus.reflection.MetaObject;
import com.znd.bus.type.TypeException;
import com.znd.bus.type.TypeHandler;


public class InsertStatementHandler  extends BaseStatementHandler  {

	
	
	public InsertStatementHandler(BufferConfig config, Executor executor, MappedStatement ms, Object parameter) {
		super(config, executor, ms, parameter);
		// TODO Auto-generated constructor stub
	}

	@Override
	public Statement newStatement() {
		return new InsertStatement();
	}

	@Override
	public void parepared(Statement ps) {
		InsertStatement is = (InsertStatement)ps;
		
		//TableMeta tableMeta = mappedStatement.getTableMeta();

		//List<ColumnMeta> indexColumns = tableMeta.getIndexColumns();
		List< List<String> > columnValuesList = new ArrayList<>(); 
		//int[] indexPositions = new int[indexColumns.size()];
		//int pos = 0;
		
		ParameterMapping[] properties = mappedStatement.getProperties();
		ParameterMapping[] conditionProperties = mappedStatement.getConditionProperties();
		for (ParameterMapping c : conditionProperties) {
		
			List<String> l = new ArrayList<>();
			columnValuesList.add(l);
			is.put(c.getProperty(), l);
		}
		
//		for (ColumnMeta c : indexColumns) {
//			
//			List<String> l = new ArrayList<>();
//			columnValuesList.add(l);
//			is.put(c.getName(), l);
//		}
		
		//int columnSize = tableMeta.getColumnSize();
		int columnSize = mappedStatement.getColumnSize();

		
		List<Object> objects = (List<Object>) this.parameter;
		for (ParameterMapping paramMapping : properties) {
			is.setDbColumnIndex(paramMapping.getProperty(), paramMapping.getDbColumnIndex());
			is.setColumnIndex(paramMapping.getProperty(), paramMapping.getColumnIndex());
		}
		
		for (Object o : objects) {
		
			String[] values = new String[columnSize];
			is.add(values);
			
			MetaObject metaObject = config.newMetaObject(o);
			
			for (ParameterMapping paramMapping : properties) {
				TypeHandler typeHandler = paramMapping.getTypeHandler();
				Object value = metaObject.getValue(paramMapping.getProperty());
				if (typeHandler != null) {
					typeHandler.setParameter(ps, paramMapping.getColumnIndex(), value);
				}
			}

			int j = 0;
			
			for (ParameterMapping c : conditionProperties) {
				String v = values[c.getColumnIndex()];
				if (v == null) {
					//TODO :
					//throw new TypeException("Index column value is null :"+ c.getProperty()+","+o);
				}
				columnValuesList.get(j++).add(v);
			}

//			for (ColumnMeta c : indexColumns) {
//				columnValuesList.get(j++).add(values[c.getIndex()]);
//			}
			
		}


	}

}
