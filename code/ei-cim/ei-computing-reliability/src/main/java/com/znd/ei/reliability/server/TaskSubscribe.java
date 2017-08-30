package com.znd.ei.reliability.server;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDF.Listener.Event.EventCallBack;
import com.ZhongND.RedisDF.Listener.Event.EventContent;
import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.db.DBAccess.Exception.JedisDBException;
import com.znd.ei.Application;

public abstract class TaskSubscribe {
	private DFService dFService;
	private static final Logger LOGGER = LoggerFactory.getLogger(Application.class);

	public TaskSubscribe(DFService dFService) {
		this.setDFService(dFService);
		try {
			dFService.registry(new EventCallBack() {
				@Override
				public void CallBack(int number, EventContent eventContent) {
					
					LOGGER.info("Number:"+number+",收到事件:" + eventContent.getControlCode() + "  "
							+ eventContent.getEventContent());
					try {
						processEvent(eventContent);
					} catch (JedisDBException e) {
						// TODO Auto-generated catch block
						//e.printStackTrace();
						LOGGER.error(e.getMessage());
					}

//					new Thread(new Runnable() {
//						
//						@Override
//						public void run() {
//							try {
//								processEvent(eventContent);
//							} catch (JedisDBException e) {
//								// TODO Auto-generated catch block
//								//e.printStackTrace();
//								LOGGER.warn("ERROR:"+e.getMessage());
//							}
//							
//						}
//					}).start();
					
				}
			}, false);
		} catch (JedisDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void processEvent(EventContent eventContent) throws JedisDBException
	{
		
	}

	public DFService getDFService() {
		return dFService;
	}

	public void setDFService(DFService dFService) {
		this.dFService = dFService;
	}


}
