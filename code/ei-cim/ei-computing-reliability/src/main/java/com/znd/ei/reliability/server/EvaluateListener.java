package com.znd.ei.reliability.server;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.ZhongND.RedisDF.Control.ControlList;
import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Listener.Event.EventContent;
import com.ZhongND.RedisDF.Service.DFService;

/**
 * 
 * @author wangheng
 * 后评估
 *
 */
@Service
public class EvaluateListener extends ComputingListener {
	
	@Autowired
	private RedisControl redisControl;
	
	@Autowired
	public EvaluateListener(DFService dFService) {
		super(dFService);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void run(EventContent eventContent)
	{
		System.out.println("收到事件:" + eventContent.getControlCode() + "  "
				+ eventContent.getEventContent());
		
		String messageType = eventContent.getControlCode();
		String messageKey = eventContent.getEventContent();
		
		ControlList list = redisControl.controlList(messageType);
		
		String str = null;
		try {
		while ((str = list.lpop(messageKey)) != null) {
			System.out.println("Task:"+str);
		}
		} catch (NullPointerException e) {
			
		}
	}

}
