package com.znd;

import java.util.List;

public interface MapperInterface<T> {
	List<T> getAll();

	void insert(T o);

	void update(T o);
	
	void deleteById(String id);
	
	void deleteAll();
}
