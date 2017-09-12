package com.znd.ei.reliability.server;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.db.DBAccess.Exception.RedissonDBException;
import com.ZhongND.RedisDF.messageDF.Listener.MessageContent;
import com.ZhongND.RedisDF.messageDF.Listener.Event.EventCallBack;
import com.znd.ei.Application;

public abstract class TaskSubscribe {
	private DFService dFService;
	private static final Logger LOGGER = LoggerFactory.getLogger(Application.class);

	public TaskSubscribe(DFService dFService) {
		this.setDFService(dFService);
		try {
			dFService.registry(new EventCallBack() {


				@Override
				public void CallBack(int number, MessageContent eventContent) {
					LOGGER.info("Number:"+number+",收到事件:" + eventContent.getControlCode() + "  "
							+ eventContent.getEventContent());
					try {
						processEvent(eventContent);
					} catch (RedissonDBException e) {
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
		} catch (RedissonDBException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void processEvent(MessageContent eventContent) throws RedissonDBException
	{
		
	}

	public DFService getDFService() {
		return dFService;
	}

	public void setDFService(DFService dFService) {
		this.dFService = dFService;
	}


}
