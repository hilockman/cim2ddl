package com.znd.bus.buffer;


public class BufferException extends RuntimeException {

	public BufferException(Throwable cause) {
		super(cause);
	}

	public BufferException(String message, Throwable e) {
		super(message, e);
	}

	public BufferException(String message) {
		super(message);
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = -1109267786428320497L;

}
