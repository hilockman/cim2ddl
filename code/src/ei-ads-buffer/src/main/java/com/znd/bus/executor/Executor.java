package com.znd.bus.executor;

import java.util.List;

import com.znd.bus.exception.ExecutionException;
import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.statement.Statement;

public interface Executor {

	<E> List<E> query(MappedStatement ms, Statement st) throws ExecutionException;
	int update(MappedStatement ms, Statement st) throws ExecutionException;
	int delete(MappedStatement ms, Statement st) throws ExecutionException;
	void insert(MappedStatement ms, Statement ps) throws ExecutionException;
}
