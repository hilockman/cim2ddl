package com.znd.bus.exception;

public class AdsException extends Exception {

	public AdsException(String string) {
		super(string);
	}

	public AdsException(String string, Throwable t) {
		super(string, t);
	}

	public AdsException(Throwable cause) {
		super(cause);
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = -6294892621536594336L;

}
