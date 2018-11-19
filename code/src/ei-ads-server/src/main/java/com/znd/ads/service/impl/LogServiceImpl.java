package com.znd.ads.service.impl;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.znd.ads.service.LogService;
import com.znd.bus.log.Log;
import com.znd.bus.log.LogBuffer;

@Service
public class LogServiceImpl implements LogService {
	@Autowired
	private LogBuffer logBuffer;

	public void save(Log info) {
		logBuffer.save(info);
	}

	public void delete(Log info) {
		logBuffer.delete(info);
	}

	public List<Log> findAll() {
		return logBuffer.findAll();
	}
	
}
