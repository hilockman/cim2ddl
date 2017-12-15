package com.znd.ei.ads.apl.reliability.bean;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateFDev;

public class RequestEstimate extends ExchangeData<RequestEstimate.Content> {

	public static class Content extends ExchangeContent {
		private  List<FState> FState;
		private List<FStateFDev> FStateFDev; 

		public List<FState> getFState() {
			if (FState == null)
				FState = new ArrayList<>();
			return FState;
		}

		public void setFState(List<FState> fState) {
			FState = fState;
		}

		public List<FStateFDev> getFStateFDev() {
			if (FStateFDev == null)
				FStateFDev = new ArrayList<>();
			return FStateFDev;
		}

		public void setFStateFDev(List<FStateFDev> fStateFDev) {
			FStateFDev = fStateFDev;
		}


	}
	
	public RequestEstimate() {
		super(Commands.STATE_ESTIMATE, new Content());
	}
	
	
}
