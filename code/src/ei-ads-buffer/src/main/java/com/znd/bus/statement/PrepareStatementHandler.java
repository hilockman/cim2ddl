package com.znd.bus.statement;

import java.util.Collection;
import java.util.Map;

import com.znd.bus.config.BufferConfig;
import com.znd.bus.exception.StatementException;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.mapping.ParameterMapping;
import com.znd.bus.reflection.MetaObject;
import com.znd.bus.type.TypeHandler;

public abstract class PrepareStatementHandler   extends BaseStatementHandler  {
	
	public PrepareStatementHandler(BufferConfig config, Executor executor, MappedStatement ms, Object parameter) {
		super(config, executor, ms, parameter);
	}
	

	@Override
	public void parepared(Statement ps) throws StatementException {
		PrepareStatement ss = (PrepareStatement) ps;
		

		if (parameter == null) {
		//	conditionMap = new HashMap<String, String>();
		} else if (parameter instanceof Map<?, ?> ){
			ss.putAll((Map<String, String>)(parameter)); 
		} else if (parameter instanceof Collection) {
			throw new IllegalArgumentException("Illegal parameter type : "+parameter.getClass());
		} else {			
			parameter.getClass();
			MetaObject metaObject = config.newMetaObject(parameter);
			
			ParameterMapping[] properties = mappedStatement.getConditionProperties();
			for (ParameterMapping property : properties) {
				TypeHandler typeHandler = property.getTypeHandler();
				Object value = metaObject.getValue(property.getProperty());
				if (typeHandler != null) {
					typeHandler.setParameter(ss, property.getProperty(), value);
				}
			}
			//conditionMap = mappedStatement.prepared(parameter);
			//throw new IllegalArgumentException("Illegal parameter type : "+parameter.getClass());
		}

	}

}
