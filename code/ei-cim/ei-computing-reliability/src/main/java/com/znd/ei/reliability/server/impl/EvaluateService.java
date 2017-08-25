package com.znd.ei.reliability.server.impl;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.ZhongND.RedisDF.Control.ControlList;
import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Listener.Event.EventContent;
import com.ZhongND.RedisDF.Service.DFService;
import com.znd.ei.reliability.config.ReliabilityProperites;
import com.znd.ei.reliability.server.TaskSubscribe;

/**
 * 
 * @author wangheng 后评估
 *
 */
@Service
public class EvaluateService extends TaskSubscribe {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(EvaluateService.class);

	@Autowired
	private ReliabilityProperites properties;

	@Autowired
	private RedisControl redisControl;

	@Autowired
	public EvaluateService(DFService dFService) {
		super(dFService);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void processEvent(EventContent eventContent) {
		System.out.println("收到事件:" + eventContent.getControlCode() + "  "
				+ eventContent.getEventContent());

		String relatedMessage = properties.getMessageType();
		String messageType = eventContent.getControlCode();
		if (!relatedMessage.equals(messageType))
			return;

		System.out.println("Lock");
		properties.getBusyLock().lock();
		ControlList list = redisControl.controlList(messageType);
		if (list == null) {
			LOGGER.info("Fail to get list :" + messageType);
			;
		}

		String messageKey = eventContent.getEventContent();
		String str = null;
		int sum = 0;
		try {
			while ((str = list.lpop(messageKey)) != null) {
				System.out.println(String.format("Receive task : %s, %d task processed.", str, ++sum));
			}
		} catch (NullPointerException e) {
			properties.getBusyLock().unlock();
		}

	}

}
