package com.znd.ads.exception;

import com.znd.bus.exception.AdsException;

public class FactoryException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 538110309669230227L;

	public FactoryException(String string) {
		super(string);
	}

	public FactoryException(AdsException e) {
		super(e);
	}

}
