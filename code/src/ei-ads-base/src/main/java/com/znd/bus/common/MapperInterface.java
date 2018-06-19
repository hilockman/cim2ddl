package com.znd.bus.common;

import java.util.List;

public interface MapperInterface<T> {
	T findById(String id);
	
	int insert(T o);
	
	void update(T o);
	
	void delete(T o);
	
	List<T> findAll();
	
	void insertList(List<T> objects);
	
	void deleteById(String id);
	
	void deleteAll();
	
	void save(T o);
}
