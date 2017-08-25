package com.znd.ei.reliability.server;

import com.ZhongND.RedisDF.Listener.Event.EventCallBack;
import com.ZhongND.RedisDF.Listener.Event.EventContent;
import com.ZhongND.RedisDF.Service.DFService;

public abstract class ComputingListener {
	private DFService dFService;
	
	public ComputingListener(DFService dFService) {
		this.setDFService(dFService);
		dFService.registry(new EventCallBack() {
			@Override
			public void CallBack(int number, EventContent eventContent) {
				run(eventContent);
			}
		}, false);
	}
	
	public void run(EventContent eventContent)
	{
		System.out.println("收到事件:" + eventContent.getControlCode() + "  "
				+ eventContent.getEventContent());
		
	}

	public DFService getDFService() {
		return dFService;
	}

	public void setDFService(DFService dFService) {
		this.dFService = dFService;
	}


}
