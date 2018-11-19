package com.znd.exception;

public class AdsExcption  extends RuntimeException {

	public AdsExcption(String string, Throwable e) {
		super(string, e);
	}

	public AdsExcption(String string) {
		super(string);
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = -4744591281494252549L;

}
