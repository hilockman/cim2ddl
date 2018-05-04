package com.znd.model;

import java.util.Date;
import java.util.List;

public class SystemResourceInfo {

	private Date time;
	private MemoryInfo memory;
	private List<SpaceInfo> spaces;
	
	private CPUInfo cpu;
	
	public MemoryInfo getMemory() {
		return memory;
	}
	public void setMemory(MemoryInfo memoryInfo) {
		this.memory = memoryInfo;
	}
	public List<SpaceInfo> getSpaces() {
		return spaces;
	}
	public void setSpaces(List<SpaceInfo> spaceInfos) {
		this.spaces = spaceInfos;
	}
	public Date getTime() {
		return time;
	}
	public void setTime(Date time) {
		this.time = time;
	}
	public CPUInfo getCpu() {
		return cpu;
	}
	public void setCpu(CPUInfo cpuInfo) {
		this.cpu = cpuInfo;
	}
}
