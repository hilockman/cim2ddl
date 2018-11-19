package com.znd.reliability.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;

public class StateSampleTask  implements Serializable {
	private FState state;
	private List<FStateFDev> devs = new ArrayList<FStateFDev>();
	
	public FState getState() {
		return state;
	}
	public void setState(FState state) {
		this.state = state;
	}
	public List<FStateFDev> getDevs() {
		return devs;
	}
	public void setDevs(List<FStateFDev> devs) {
		this.devs = devs;
	}
}
