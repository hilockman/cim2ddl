package com.znd.ei.service;

import com.znd.ei.memdb.dao.MemTable;

public interface ClasssCreateService {

	void createClasses();
	
    void deleteAll();
    
    void store(MemTable table);
    
    
    void init();
}
