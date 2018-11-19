package com.znd.exception;


public class MemoryException extends AdsExcption {

	public MemoryException(String string, Throwable e) {
		super(string, e);
	}

	public MemoryException(String string) {
		super(string);
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = 6506108137824109374L;

}
