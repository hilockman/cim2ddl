package com.znd.bus.statement;

import java.util.Map;

import com.znd.bus.exception.ExecutionException;

public interface RowUpdateHandler {
	void update(Map<Short, String> columns, Map<String, String> conditions) throws ExecutionException;
}
