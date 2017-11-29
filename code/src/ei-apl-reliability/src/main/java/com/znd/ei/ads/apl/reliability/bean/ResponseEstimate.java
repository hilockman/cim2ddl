package com.znd.ei.ads.apl.reliability.bean;

import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.ACBus;
import com.znd.ei.memdb.reliabilty.domain.FState;

public class ResponseEstimate extends ExchangeData<ResponseEstimate.Content> {

	public static class Content extends ExchangeContent {
		private List<ACBus> ACBus;
		private List<FState> FState;

		public List<ACBus> getACBus() {
			return ACBus;
		}

		public void setACBus(List<ACBus> aCBus) {
			ACBus = aCBus;
		}

		public List<FState> getFState() {
			return FState;
		}

		public void setFState(List<FState> fState) {
			FState = fState;
		}



	}
}
