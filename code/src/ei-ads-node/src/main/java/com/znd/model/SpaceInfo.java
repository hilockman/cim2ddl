package com.znd.model;

public class SpaceInfo {
  private String dir;
  private Long totalSpace;
  private Long freeSpace;
  private Long usableSpace;
  
	public String getDir() {
		return dir;
	}
	public void setDir(String dir) {
		this.dir = dir;
	}
	public Long getTotalSpace() {
		return totalSpace;
	}
	public void setTotalSpace(Long totalSpace) {
		this.totalSpace = totalSpace;
	}
	public Long getFreeSpace() {
		return freeSpace;
	}
	public void setFreeSpace(Long freeSpace) {
		this.freeSpace = freeSpace;
	}
	public Long getUsableSpace() {
		return usableSpace;
	}
	public void setUsableSpace(Long usableSpace) {
		this.usableSpace = usableSpace;
	}
	@Override
	public String toString() {
		return "SpaceInfo [dir=" + dir + ", totalSpace=" + totalSpace
				+ ", freeSpace=" + freeSpace + ", usableSpace=" + usableSpace + "]";
	}
}
