package com.znd.ei.ads.apl.reliability.bean;

import com.znd.ei.ads.config.PRAdequacySetting;

public class DataReady extends ExchangeData<DataReady.Content> {

	public static class Content extends ExchangeContent {
		private PRAdequacySetting PRAdequacySetting;

		public PRAdequacySetting getPRAdequacySetting() {
			return PRAdequacySetting;
		}

		public void setPRAdequacySetting(PRAdequacySetting pRAdequacySetting) {
			PRAdequacySetting = pRAdequacySetting;
		}
	}
	
	public DataReady() {
		super(DATA_READY, new Content());
	}
	
	public static String DATA_READY = "DataReady";
}
