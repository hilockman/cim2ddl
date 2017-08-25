package com.znd.ei.reliability.server;

import com.ZhongND.RedisDF.Listener.Event.EventCallBack;
import com.ZhongND.RedisDF.Listener.Event.EventContent;
import com.ZhongND.RedisDF.Service.DFService;

public abstract class TaskSubscribe {
	private DFService dFService;
	
	public TaskSubscribe(DFService dFService) {
		this.setDFService(dFService);
		dFService.registry(new EventCallBack() {
			@Override
			public void CallBack(int number, EventContent eventContent) {
				new Thread(new Runnable() {
					
					@Override
					public void run() {
						processEvent(eventContent);
						
					}
				}).start();;
				
			}
		}, false);
	}
	
	public void processEvent(EventContent eventContent)
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
