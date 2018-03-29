package com.znd.bus.statement;

import com.znd.bus.config.BufferConfig;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;

public abstract class BaseStatementHandler  implements StatementHandler {

	protected final MappedStatement mappedStatement;
	protected final Object parameter;
	protected final Executor executor;
	protected final BufferConfig config;
	
	public BaseStatementHandler(BufferConfig config, Executor executor, MappedStatement ms, Object parameter) {
		this.config = config;
		this.executor = executor;
		this.mappedStatement = ms;
		this.parameter = parameter;
	}
	
}
