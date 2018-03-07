package com.znd.ei.ads.buffer;

import java.io.Closeable;
import java.util.List;
import java.util.Map;

public interface Buffer  extends Closeable {	
	List<TableMeta> tables();
	
	<T> T selectOne(String statement, Object parameter);
	<E> List<E> selectList(String statement, Object parameter);
	<K,V> Map<K,V> selectMap(String statement, Object parameter, String mapKey);
	int insert(String statement, Object parameter);
	
	
	int update(String statement, Object parameter);
	int delete(String statement, Object parameter);
	
	<T> T selectOne(String statement);
	<E> List<E> selectList(String statement);
	<K,V> Map<K,V> selectMap(String statement, String mapKey);
	int insert(String statement);
	int update(String statement);
	int delete(String statement);
	void commit();
	@Override
	public void close();
	
	
}
