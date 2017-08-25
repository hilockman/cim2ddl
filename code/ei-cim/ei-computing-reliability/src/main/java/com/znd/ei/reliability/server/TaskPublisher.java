package com.znd.ei.reliability.server;

import com.znd.ei.reliability.model.ComputingResult;

public interface TaskPublisher {
	ComputingResult run();
}
