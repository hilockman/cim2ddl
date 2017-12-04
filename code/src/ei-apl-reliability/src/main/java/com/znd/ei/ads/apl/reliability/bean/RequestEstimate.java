package com.znd.ei.ads.apl.reliability.bean;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.FState;

public class RequestEstimate extends ExchangeData<RequestEstimate.Content> {

	public static class Content extends ExchangeContent {
		private  List<FState> FState;

		public List<FState> getFState() {
			if (FState == null)
				FState = new ArrayList<>();
			return FState;
		}

		public void setFState(List<FState> fState) {
			FState = fState;
		}


	}
	
	public RequestEstimate() {
		super(Commands.STATE_ESTIMATE, new Content());
	}
	
	
}
