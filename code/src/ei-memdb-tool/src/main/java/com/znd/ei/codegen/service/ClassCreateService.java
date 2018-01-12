package com.znd.ei.codegen.service;

import java.nio.file.Path;

import com.znd.ei.memdb.MetaTable;

public interface ClassCreateService {

	void createClasses();
	
    //void deleteAll();
    
    void store(MetaTable table, Path location, String packageName);
    
    
    void init();
    
	Path getRootLocation();
}
