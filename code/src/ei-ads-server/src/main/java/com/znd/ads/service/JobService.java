package com.znd.ads.service;

import java.util.List;

import com.znd.bus.common.model.CalcJob;

public interface JobService {

	List getAll();

	CalcJob findJob(String jobId);
	
	CalcJob findJobByName(String name);
	
	List<CalcJob> findByModel(String modelId);
	
	void cancel(String jobId);

	void restart(String jobId);

	void add(CalcJob job);

	void stop(String jobId);

	void pause(String jobId);
}
