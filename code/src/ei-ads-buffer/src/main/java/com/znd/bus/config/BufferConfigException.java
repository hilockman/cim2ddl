package com.znd.bus.config;



public class BufferConfigException extends RuntimeException {

	/**
	 * 
	 */
	private static final long serialVersionUID = 6303319214306156782L;

	public BufferConfigException(String message) {
		super(message);
	}

	public BufferConfigException(String message, Throwable e) {
		super(message, e);
	}

	public BufferConfigException(Throwable e) {
		super(e);
	}
}
