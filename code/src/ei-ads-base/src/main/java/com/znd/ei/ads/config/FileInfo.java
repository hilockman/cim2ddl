package com.znd.ei.ads.config;

public class FileInfo {
	
	private String name;
	private Integer blockSize;
	private Integer length;
	
	
	public FileInfo(String name, Integer blockSize, Integer length) {
		this.name = name;
		this.blockSize = blockSize;
		this.length = length;
	}
	
	
	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public Integer getBlockSize() {
		return blockSize;
	}


	public void setBlockSize(Integer blockSize) {
		this.blockSize = blockSize;
	}


	public Integer getLength() {
		return length;
	}


	public void setLength(Integer length) {
		this.length = length;
	}





}
