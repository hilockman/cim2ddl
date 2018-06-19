package com.znd.ads.property;

public class PropertyException extends RuntimeException {

	public PropertyException(String message, Throwable e) {
		super(message, e);
	}

	public PropertyException(String message) {
		super(message);
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = -1376465658570935963L;

}
