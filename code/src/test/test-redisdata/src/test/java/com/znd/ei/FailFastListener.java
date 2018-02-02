package com.znd.ei;

import org.junit.runner.notification.Failure;
import org.junit.runner.notification.RunListener;

public class FailFastListener extends RunListener {
	@Override
	public void testFailure(Failure failure) throws Exception {
		failure.getException().printStackTrace();
		System.out.println(">>>>>>>>>>>>>>>>>>>>>>>>>>>Fail Fast>>>>>>>>>>>>>");
		System.exit(-1);
	}
}
