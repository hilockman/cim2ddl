package com.znd.ei.ads.bus.binding;

public class BindingException extends RuntimeException {

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
