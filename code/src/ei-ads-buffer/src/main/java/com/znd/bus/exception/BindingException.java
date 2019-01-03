package com.znd.bus.exception;

public class BindingException extends AdsException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1904324342L;

	public BindingException(String string) {
		super(string);
	}

	public BindingException(String string, Throwable t) {
		super(string, t);
	}

}
