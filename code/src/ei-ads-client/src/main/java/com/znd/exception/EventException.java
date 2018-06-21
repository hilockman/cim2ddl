package com.znd.exception;


public class EventException extends RuntimeException {

	public EventException(String string) {
		super(string);
	}

	public EventException(String string, Exception e) {
		super(string, e);
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = 3217859764465777460L;

}
