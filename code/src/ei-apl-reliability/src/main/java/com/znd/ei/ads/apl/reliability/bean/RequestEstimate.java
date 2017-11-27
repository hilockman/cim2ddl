package com.znd.ei.ads.apl.reliability.bean;

import com.znd.ei.memdb.reliabilty.domain.FState;

public class RequestEstimate extends ExchangeData<RequestEstimate.Content> {

	public static class Content extends ExchangeContent {
		private  FState FState;

		public FState getFState() {
			return FState;
		}

		public void setFState(FState fState) {
			FState = fState;
		}

	}
	
	public RequestEstimate() {
		super(Commands.STATE_ESTIMATE, new Content());
	}
	
	
}
