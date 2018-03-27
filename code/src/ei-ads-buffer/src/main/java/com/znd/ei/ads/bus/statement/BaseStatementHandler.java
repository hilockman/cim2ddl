package com.znd.ei.ads.bus.statement;

import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.executor.Executor;
import com.znd.ei.ads.bus.mapping.MappedStatement;

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
