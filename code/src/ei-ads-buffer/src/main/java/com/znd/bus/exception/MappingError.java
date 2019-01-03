package com.znd.bus.exception;

public class MappingError extends AdsException {

	/**
	 * 
	 */
	private static final long serialVersionUID = -676963354261897674L;

	
	public MappingError(String message) {
		super(message);
	}
	
	public MappingError(String message, Throwable t) {
		super(message, t);
	}
	
	public MappingError(Throwable t) {
		super(t);
	}
	
}
