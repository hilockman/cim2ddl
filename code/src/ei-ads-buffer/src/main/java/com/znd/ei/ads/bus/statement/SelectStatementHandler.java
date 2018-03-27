package com.znd.ei.ads.bus.statement;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.config.TableMeta;
import com.znd.ei.ads.bus.executor.Executor;
import com.znd.ei.ads.bus.mapping.MappedStatement;
import com.znd.ei.ads.bus.mapping.ParameterMapping;
import com.znd.ei.ads.bus.reflection.MetaObject;
import com.znd.ei.ads.bus.type.TypeHandler;

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
