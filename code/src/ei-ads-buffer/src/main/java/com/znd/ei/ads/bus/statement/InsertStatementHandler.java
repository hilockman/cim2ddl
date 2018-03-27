package com.znd.ei.ads.bus.statement;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.ColumnMeta;
import com.znd.ei.ads.bus.config.TableMeta;
import com.znd.ei.ads.bus.executor.Executor;
import com.znd.ei.ads.bus.mapping.MappedStatement;
import com.znd.ei.ads.bus.mapping.ParameterMapping;
import com.znd.ei.ads.bus.reflection.MetaObject;
import com.znd.ei.ads.bus.type.TypeHandler;


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
		
		TableMeta tableMeta = mappedStatement.getTableMeta();

		List<ColumnMeta> indexColumns = tableMeta.getIndexColumns();
		List< List<String> > columnValuesList = new ArrayList<>(); 
		for (ColumnMeta c : indexColumns) {
			List<String> l = new ArrayList<>();
			columnValuesList.add(l);
			is.put(c.getName(), l);
		}
		
		int columnSize = tableMeta.getColumnSize();
		
		ParameterMapping[] properties = mappedStatement.getProperties();
		ParameterMapping[] conditionProperties = mappedStatement.getConditionProperties();
		
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
				columnValuesList.get(j++).add(values[c.getColumnIndex()]);
			}
			
		}


	}

}
