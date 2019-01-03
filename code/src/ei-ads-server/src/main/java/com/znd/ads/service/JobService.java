package com.znd.ads.service;

import java.util.List;

import com.znd.ads.exception.FactoryException;
import com.znd.bus.common.model.CalcJob;

public interface JobService {

	List<CalcJob> getAll();

	CalcJob findJob(String jobId);
	
	CalcJob findJobByName(String name);
	
	List<CalcJob> findByModel(String modelId);
	
	void delete(String jobId);

	void start(String jobId);

	void create(CalcJob job);

	void cancel(String jobId);

	Object getResult(String id) throws FactoryException;

	String getFile(String folder, String file);
}
