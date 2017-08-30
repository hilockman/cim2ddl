package com.znd.ei.reliability.server.impl;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.ZhongND.RedisDF.Control.RedisControl;
import com.ZhongND.RedisDF.Control.Content.ControlList;
import com.ZhongND.RedisDF.Listener.Event.EventContent;
import com.ZhongND.RedisDF.Service.DFService;
import com.ZhongND.RedisDF.db.DBAccess.Exception.JedisDBException;
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

	private ReliabilityProperites properties;
	
	private DFService dFService;
	
	@Autowired
	public EvaluateService(DFService dFService, ReliabilityProperites properties) throws JedisDBException {
		super(dFService);
		// TODO Auto-generated constructor stub
		this.dFService = dFService;
		this.properties = properties;
	
	}

	@Override
	public void processEvent(EventContent eventContent) throws JedisDBException {

		if (properties == null) {
			LOGGER.error("NULL properties, processEvent too early.");
			return;
		}
		String relatedMessage = properties.getMessageType();
		String messageType = eventContent.getControlCode();
		if (!relatedMessage.equals(messageType))
			return;


		LOGGER.info("Lock Busy Flag ");
		properties.getBusyLock().lock();
		LOGGER.info("Busy Flag Locked");
		
		RedisControl redisControl = dFService.registry(properties.getAppName());
		ControlList list = redisControl.controlList();
		if (list == null) {
			LOGGER.info("Fail to get list :" + messageType);
		}

		String messageKey = eventContent.getEventContent();
		String str = null;
		int sum = 0;
		try {
			LOGGER.info("Start pop: messageKey=" + messageKey);
			while ((str = list.lpop(messageKey)) != null) {
				LOGGER.info(String.format(
						"Receive task : %s, %d task processed, key=%s", str, ++sum, messageKey));
			}
		} catch (JedisDBException e) {
			throw e;
		} finally {
			properties.getBusyLock().unlock();
			LOGGER.info("Busy Flag unLocked");
		}

	}

}
