package com.znd.ei.ads.bus.reflection;

public class ReflectionException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = -23525513616341698L;

	
	public ReflectionException(String message) {
		super(message);
	}


	public ReflectionException(String message, Throwable t) {
		super(message, t);
	}
}
