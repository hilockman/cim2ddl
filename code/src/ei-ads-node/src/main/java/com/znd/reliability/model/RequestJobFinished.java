package com.znd.reliability.model;


public class RequestJobFinished extends ExchangeData<ExchangeContent>  {
	public RequestJobFinished() {
		super(Commands.JOB_FINISHED, null);
	}
}
