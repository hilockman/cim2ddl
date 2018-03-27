package com.znd.ei.ads.bus.statement;

import com.znd.ei.ads.bus.config.BufferConfig;
import com.znd.ei.ads.bus.executor.Executor;
import com.znd.ei.ads.bus.mapping.MappedStatement;


public class DeleteStatementHandler extends PrepareStatementHandler {

	public DeleteStatementHandler(BufferConfig config, Executor executor, MappedStatement ms, Object parameter) {
		super(config, executor, ms, parameter);
	}

	@Override
	public Statement newStatement() {
		return new DeleteStatement();
	}
}
