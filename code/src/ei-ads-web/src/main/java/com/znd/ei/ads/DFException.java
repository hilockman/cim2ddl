package com.znd.ei.ads;

import org.springframework.boot.ExitCodeGenerator;

public class DFException extends Exception implements ExitCodeGenerator {

	public DFException(Throwable e) {
		super(e);
	}
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
	public int getExitCode() {
		return -999;
	}

}
