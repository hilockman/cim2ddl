package com.znd.ei.ads.apl.reliability.bean;


public class RequestJobFinished extends ExchangeData<ExchangeContent>  {
	public RequestJobFinished() {
		super(Commands.JOB_FINISHED, null);
	}
}
