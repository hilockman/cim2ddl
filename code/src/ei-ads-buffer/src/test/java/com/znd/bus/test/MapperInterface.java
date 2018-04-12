package com.znd.bus.test;

import java.util.List;

public interface MapperInterface<T> {
	T findById(String id);
	
	int insert(T user);
	
	void update(T user);
	
	void delete(T user);
	
	List<T> findAll();
	
	void insertList(List<T> users);
	
	void deleteById(String id);
	
	void deleteAll();
}
