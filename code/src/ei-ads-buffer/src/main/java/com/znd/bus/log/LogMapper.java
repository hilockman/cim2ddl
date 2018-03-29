package com.znd.bus.log;

import java.util.List;

public interface LogMapper {

	void save(Log info);
	void delete(Log info);
	List<Log> findAll();
	
	
}
