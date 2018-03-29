package com.znd.bus.statement;

import com.znd.bus.config.BufferConfig;
import com.znd.bus.executor.Executor;
import com.znd.bus.mapping.MappedStatement;


public class DeleteStatementHandler extends PrepareStatementHandler {

	public DeleteStatementHandler(BufferConfig config, Executor executor, MappedStatement ms, Object parameter) {
		super(config, executor, ms, parameter);
	}

	@Override
	public Statement newStatement() {
		return new DeleteStatement();
	}
}
