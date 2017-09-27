package com.znd.ei.codegen.service;

import com.znd.ei.memdb.MemTable;

public interface ClassCreateService {

	void createClasses();
	
    void deleteAll();
    
    void store(MemTable table);
    
    
    void init();
}
