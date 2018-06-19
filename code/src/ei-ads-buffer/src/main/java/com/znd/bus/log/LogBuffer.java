package com.znd.bus.log;

import java.util.List;

public interface LogBuffer {

	void save(Log info);
	void delete(Log info);
	List<Log> findAll();
	
	
}
