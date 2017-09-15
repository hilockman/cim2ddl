package com.znd.ei.ads.apl.reliability;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.adf.ListData;
import com.znd.ei.ads.adf.MapData;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.apl.AppTemplate;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;

/**
 * StateEstimate 状态后评估软件
 * 
 * @author wangheng
 *
 */
@Apl
public class StateEstimate extends AppTemplate {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(StateEstimate.class);

	@AplFunction
	public void estimate(@In("created_EstimateTask") ListData estimateTask,
			@Out("created_EstemateResult") MapData estimateResult) throws ACPException {

		String task = null;
		int sum = 0;
		while ((task = estimateTask.lpop()) != null) {
			LOGGER.info(String.format("Receive task : %s, %d task processed",
					task, ++sum));
		}
		// if (properties == null) {
		// LOGGER.error("NULL properties, processEvent too early.");
		// return;
		// }
		// String relatedMessage = properties.getMessageType();
		// String messageType = eventContent.getControlCode();
		// if (!relatedMessage.equals(messageType))
		// return;
		//
		//
		// LOGGER.info("Lock Busy Flag ");
		// properties.getBusyLock().lock();
		// LOGGER.info("Busy Flag Locked");
		//
		// ExectueDF redisControl = dFService.registry(properties.getAppName());
		// RedissonDBList list = redisControl.RedissonDBList();
		// if (list == null) {
		// LOGGER.info("Fail to get list :" + messageType);
		// }
		//
		// String messageKey = eventContent.getEventContent();
		// ResultObject<String, String> rt = null;
		// int sum = 0;
		// try {
		// LOGGER.info("Start pop: messageKey=" + messageKey);
		// while ((rt = list.LPOP(messageKey)) != null) {
		// String str = rt.getValue();
		// if (str == null)
		// break;
		//
		// LOGGER.info(String.format(
		// "Receive task : %s, %d task processed, key=%s", str, ++sum,
		// messageKey));
		// }
		// } catch (RedissonDBException e) {
		// throw e;
		// } finally {
		// list.closedSyncControlClient();
		// properties.getBusyLock().unlock();
		// LOGGER.info("Busy Flag unLocked");
		// }

	}
}
