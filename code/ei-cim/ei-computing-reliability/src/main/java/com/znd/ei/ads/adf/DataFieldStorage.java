package com.znd.ei.ads.adf;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.IOOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.apl.AplManager;

/**
 * 
 * @author wangheng 本地数据域存储
 *
 */
@Component
public class DataFieldStorage {

	private static final Logger LOGGER = LoggerFactory
			.getLogger(DataFieldStorage.class);

	@Autowired
	AplManager aplManager;

	ConnectionFactory connectionFactory;

	@Autowired
	public DataFieldStorage(ConnectionFactory connectionFactory) {
		this.connectionFactory = connectionFactory;
	}

	private Map<String, DataItem> dataFields = new HashMap<String, DataItem>();
	private Map<String, Method> cc2Operations = new HashMap<String, Method>();

	public boolean contain(String contentCode) {
		return dataFields.containsKey(contentCode);
	}

	private boolean isIOOperationType(Class<?> clazz) {
		try {
			if (clazz.asSubclass(IOOperations.class) != null) {
				return true;
			}
			return false;
		} catch (ClassCastException e) {
			return false;
		}

	}

	public void register(String contentCode, Class dataType) {

		Method[] methods = ConnectionFactory.class.getMethods();
		for (Method m : methods) {
			Class<?> rtType = m.getReturnType();
			if (isIOOperationType(rtType)) {
				Method m1 = null;
				try {
					m1 = rtType.getMethod("create");
				} catch (NoSuchMethodException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (SecurityException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				if (m1 == null)
					continue;

				String ioname = rtType.getSimpleName();
				String dataTypeName = dataType.getSimpleName();
				if (ioname.contains(dataTypeName)) {
					cc2Operations.put(contentCode, m);
					LOGGER.info(String.format(
							"Succeed to regist data field : cc=%s io=%s.",
							contentCode, rtType.getSimpleName()));
					break;
				}

			}
		}

	}

	public void receivedMessage(String contentCode, String content)
			throws ACPException, UnsupportedOperation {
		LOGGER.info(String.format("Receive: cc=%s, content=%s"));
		if (!cc2Operations.containsKey(contentCode)) {

			return;
		}

		LOGGER.info(String
				.format("Begin to update data field: cc=%s, content=%s"));
		Method m = cc2Operations.get(contentCode);
		IOOperations io = null;
		try {
			io = (IOOperations) m.invoke(connectionFactory);
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			throw new ACPException(e);
		} catch (IllegalArgumentException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			throw new ACPException(e);
		} catch (InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			throw new ACPException(e);
		}
		DataItem dataItem = (DataItem) io.create();
		dataItem.setCode(contentCode);
		io.read(dataItem);
		dataFields.put(contentCode, dataItem);
		LOGGER.info(String
				.format("Success to update data field: cc=%s, content=%s"));
		aplManager.beginWork(contentCode);
	}

	public DataItem getData(String contentCode) {
		return dataFields.get(contentCode);
	}
}
