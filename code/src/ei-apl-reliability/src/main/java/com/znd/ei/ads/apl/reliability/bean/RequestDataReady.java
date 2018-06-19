package com.znd.ei.ads.apl.reliability.bean;

import com.znd.ads.model.dto.PRAdequacySetting;

public class RequestDataReady extends ExchangeData<RequestDataReady.Content> {

	public static class Content extends ExchangeContent {
		private PRAdequacySetting PRAdequacySetting;

		public PRAdequacySetting getPRAdequacySetting() {
			return PRAdequacySetting;
		}

		public void setPRAdequacySetting(PRAdequacySetting pRAdequacySetting) {
			PRAdequacySetting = pRAdequacySetting;
		}
	}
	
	public RequestDataReady() {
		super(Commands.DATA_READY, new Content());
	}
}
