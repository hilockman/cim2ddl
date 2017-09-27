package com.znd.ei.memdb;

public class DbException extends Exception  {
	
	public static int NORMAL_ERROR = -1;
	public static int TYPE_ERROR = -2;

	/**
	 * 
	 */
	private static final long serialVersionUID = 14324004030243204L;
	private int returnCode;
	private String description;
	
	
	public DbException(int returnCode, String description){
		super();
		this.returnCode = returnCode;
		this.description = description;
	}
	
	public DbException(String description){
		this(NORMAL_ERROR, description);
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
