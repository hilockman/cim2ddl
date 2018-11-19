package com.znd.reliability.model;

import java.io.Serializable;

public class ReliabilityIndexResult implements Serializable {
	private com.znd.ei.memdb.reliabilty.domain.System sys;

	public com.znd.ei.memdb.reliabilty.domain.System getSys() {
		return sys;
	}

	public void setSys(com.znd.ei.memdb.reliabilty.domain.System sys) {
		this.sys = sys;
	}
}
