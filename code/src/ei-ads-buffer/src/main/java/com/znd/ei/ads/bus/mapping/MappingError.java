package com.znd.ei.ads.bus.mapping;

public class MappingError extends RuntimeException {

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
