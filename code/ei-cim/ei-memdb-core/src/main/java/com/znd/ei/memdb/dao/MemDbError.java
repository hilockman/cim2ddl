package com.znd.ei.memdb.dao;

public class MemDbError extends Exception  {
	private int returnCode;
	private String description;
	
	
	public MemDbError(int returnCode, String description){
		super();
		this.returnCode = returnCode;
		this.description = description;
	}

	public int getReturnCode() {
		return returnCode;
	}
	public void setReturnCode(int returnCode) {
		this.returnCode = returnCode;
	}
	public String getDescription() {
		return description;
	}
	public void setDescription(String description) {
		this.description = description;
	}
}
