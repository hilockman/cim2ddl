package com.znd.reliability.model;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.memdb.reliabilty.domain.ACBus;
import com.znd.ei.memdb.reliabilty.domain.FState;
import com.znd.ei.memdb.reliabilty.domain.FStateMIsland;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlAd;
import com.znd.ei.memdb.reliabilty.domain.FStateOvlDev;

public class ResponseEstimate extends ExchangeData<ResponseEstimate.Content> {

	public static class Content extends ExchangeContent {
		private List<ACBus> ACBus;
		private List<FState> FState;

		private List<FStateOvlDev> FStateOvlDev = new ArrayList<FStateOvlDev>();
		private List<FStateOvlAd> FStateOvlAd = new ArrayList<FStateOvlAd>();
		private List<FStateMIsland> FStateMIsland = new ArrayList<>();
		
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

		public List<FStateOvlDev> getFStateOvlDev() {
			return FStateOvlDev;
		}

		public void setFStateOvlDev(List<FStateOvlDev> fStateOvlDev) {
			FStateOvlDev = fStateOvlDev;
		}

		public List<FStateOvlAd> getFStateOvlAd() {
			return FStateOvlAd;
		}

		public void setFStateOvlAd(List<FStateOvlAd> fStateOvlAd) {
			FStateOvlAd = fStateOvlAd;
		}

		public List<FStateMIsland> getFStateMIsland() {
			return FStateMIsland;
		}

		public void setFStateMIsland(List<FStateMIsland> fStateMIsland) {
			FStateMIsland = fStateMIsland;
		}



	}
}
