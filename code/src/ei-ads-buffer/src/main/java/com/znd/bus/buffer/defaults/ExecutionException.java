package com.znd.bus.buffer.defaults;


public class ExecutionException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = -2672507918261762060L;

	public ExecutionException(String message, Throwable t) {
		super(message, t);
	}

	public ExecutionException(Throwable e) {
		super(e);
	}
}
