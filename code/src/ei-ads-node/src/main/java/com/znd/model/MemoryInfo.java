package com.znd.model;

public class MemoryInfo {
	private Double globalUsedMemoryRate;
	 /* Total amount of free memory available to the JVM */
	private Long freeMemory;
	
	/* Maximum amount of memory the JVM will attempt to use */
	private Long maxMemory;
	
	/* Total memory currently available to the JVM */
	private Long totalMemory;
	
	
	private Long usedMemory;
	
	
	private Long globalTotalMemory;
	
	private Long globalFreeMemory;
	
	private Long globalUsedMemory;
	
	private Long swapTotalMemory;
	
	private Long swapUsedMemory;
	
	public Long getFreeMemory() {
		return freeMemory;
	}
	public void setFreeMemory(Long freeMemory) {
		this.freeMemory = freeMemory;
	}
	public Long getMaxMemory() {
		return maxMemory;
	}
	public void setMaxMemory(Long maxMemory) {
		this.maxMemory = maxMemory;
	}
	public Long getTotalMemory() {
		return totalMemory;
	}
	public void setTotalMemory(Long totalMemory) {
		this.totalMemory = totalMemory;
	}
	
	@Override
	public String toString() {
		return "MemoryInfo [freeMemory=" + freeMemory + ", maxMemory="
				+ maxMemory + ", totalMemory=" + totalMemory + "]";
	}
	public Long getGlobalTotalMemory() {
		return globalTotalMemory;
	}
	public void setGlobalTotalMemory(Long globalTotalMemory) {
		this.globalTotalMemory = globalTotalMemory;
	}
	public Long getGlobalFreeMemory() {
		return globalFreeMemory;
	}
	public void setGlobalFreeMemory(Long globalFreeMemory) {
		this.globalFreeMemory = globalFreeMemory;
	}
	public Long getSwapTotalMemory() {
		return swapTotalMemory;
	}
	public void setSwapTotalMemory(Long swapTotalMemory) {
		this.swapTotalMemory = swapTotalMemory;
	}
	public Long getSwapUsedMemory() {
		return swapUsedMemory;
	}
	public void setSwapUsedMemory(Long swapUsedMemory) {
		this.swapUsedMemory = swapUsedMemory;
	}
	public Long getGlobalUsedMemory() {
		return globalUsedMemory;
	}
	public void setGlobalUsedMemory(Long globalUsedMemory) {
		this.globalUsedMemory = globalUsedMemory;
	}
	public Long getUsedMemory() {
		return usedMemory;
	}
	public void setUsedMemory(Long usedMemory) {
		this.usedMemory = usedMemory;
	}
	public Double getGlobalUsedMemoryRate() {
		return globalUsedMemoryRate;
	}
	public void setGlobalUsedMemoryRate(Double globalUsedMemoryRate) {
		this.globalUsedMemoryRate = globalUsedMemoryRate;
	}

}
