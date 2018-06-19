package com.znd.ads.exception;

public class JobException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 8541247648951592200L;

	public JobException(String message) {
		super(message);
	}
	
	public JobException(String message, Throwable e) {
		super(message, e);
	}
}
