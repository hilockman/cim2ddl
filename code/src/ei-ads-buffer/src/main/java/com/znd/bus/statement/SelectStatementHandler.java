package com.znd.bus.statement;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import com.znd.bus.config.BufferConfig;
import com.znd.bus.config.TableMeta;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.mapping.ParameterMapping;
import com.znd.bus.reflection.MetaObject;
import com.znd.bus.type.TypeHandler;

public class SelectStatementHandler  extends PrepareStatementHandler {

	public SelectStatementHandler(BufferConfig config, Executor executor, MappedStatement ms, Object parameter) {
		super(config, executor, ms, parameter);
		// TODO Auto-generated constructor stub
	}

	@Override
	public Statement newStatement() {
		return new SelectStatement();
	}

}
