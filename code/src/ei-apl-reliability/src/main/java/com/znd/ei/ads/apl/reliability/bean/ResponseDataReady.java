package com.znd.ei.ads.apl.reliability.bean;


public class ResponseDataReady extends ExchangeData<RequestDataReady.Content> {

	public static class Content extends ExchangeContent {
		private String message;

		public String getMessage() {
			return message;
		}

		public void setMessage(String message) {
			this.message = message;
		}

	}
	
	
}
