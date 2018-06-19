package com.znd.exception;

import com.znd.bus.channel.Event;

public class AplException extends RuntimeException {

	public AplException(String message) {
		super(message);
	}
	
	public AplException(String message, Throwable e) {
		super(message, e);
	}


	/**
	 * 
	 */
	private static final long serialVersionUID = 2701535944624672453L;

}
