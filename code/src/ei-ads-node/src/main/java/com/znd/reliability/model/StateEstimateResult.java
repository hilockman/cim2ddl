package com.znd.reliability.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;

public class StateEstimateResult  implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1555555554353253254L;
	private FState state;
	private List<FStateFDev> devs = new ArrayList<FStateFDev>();
	private List<FStateMIsland> mislands = new ArrayList<FStateMIsland>();
	private List<FStateOvlDev> ovlDevs = new ArrayList<FStateOvlDev>();
	private List<FStateOvlAd> ovlAds = new ArrayList<FStateOvlAd>();

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

	public List<FStateMIsland> getMislands() {
		return mislands;
	}

	public void setMislands(List<FStateMIsland> mislands) {
		this.mislands = mislands;
	}

	public List<FStateOvlDev> getOvlDevs() {
		return ovlDevs;
	}

	public void setOvlDevs(List<FStateOvlDev> ovlDevs) {
		this.ovlDevs = ovlDevs;
	}

	public List<FStateOvlAd> getOvlAds() {
		return ovlAds;
	}

	public void setOvlAds(List<FStateOvlAd> ovlAds) {
		this.ovlAds = ovlAds;
	}
}
