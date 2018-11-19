package com.znd.ads.service;

import java.util.List;

import com.znd.bus.log.Log;

public interface LogService {

	void save(Log info);
	void delete(Log info);
	List<Log> findAll();
	
}
