package com.znd.bus.executor;

import java.util.List;

import com.znd.bus.mapping.MappedStatement;
import com.znd.bus.statement.Statement;

public interface Executor {

	<E> List<E> query(MappedStatement ms, Statement st);
	int update(MappedStatement ms, Statement st);
	int delete(MappedStatement ms, Statement st);
	void insert(MappedStatement ms, Statement ps);
}
