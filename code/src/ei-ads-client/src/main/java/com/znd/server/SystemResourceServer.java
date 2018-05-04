package com.znd.server;

import java.util.Collection;
import java.util.List;

import com.znd.model.CPUInfo;
import com.znd.model.MemoryInfo;
import com.znd.model.SpaceInfo;
import com.znd.model.SystemResourceInfo;

public interface SystemResourceServer {

	SystemResourceInfo get();
	Collection<SystemResourceInfo> getList();
	
	MemoryInfo getMemoryInfo();
	
	List<SpaceInfo> getSpaceInfos();
	
	CPUInfo getCPU();
	
	List<CPUInfo> getHistoryCpu();
}
