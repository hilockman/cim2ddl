package com.znd.ei.ads.adf;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.ei.ads.ServerProperties;
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

public final class DataFieldStorage {

	private static final Logger LOGGER = LoggerFactory
			.getLogger(DataFieldStorage.class);


	private AplManager aplManager;

	private ConnectionFactory connectionFactory;

	private ServerProperties serverProperties;
	
	public DataFieldStorage(ServerProperties serverProperties, ConnectionFactory connectionFactory, AplManager aplManager) {
		this.serverProperties = serverProperties;
		this.connectionFactory = connectionFactory;
		this.aplManager = aplManager;
		try {
			aplManager.loadApls(this);
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		connectionFactory.register(this);
		
		
	}

	private Map<String, DataItem> dataFields = new HashMap<String, DataItem>();
	private Map<String, Method> cc2Operations = new HashMap<String, Method>();

	public boolean contain(String contentCode) {
		return dataFields.containsKey(contentCode);
	}
	
	public String getServerName() {
		if (serverProperties.getPort() == null)
			return serverProperties.getName();
		
		return serverProperties.getName() + serverProperties.getPort();
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
	
	private boolean isRelatedIO(Class<?> ioClass, Class<?> dataTypeClass) {
		String ioname = ioClass.getSimpleName();
		String dataTypeName = dataTypeClass.getSimpleName();
		return ioname.contains(dataTypeName);
	}

	/**
	 * 注册数据域
	 * 
	 * @param contentCode
	 *            内容代码
	 * @param dataType
	 *            数据类型
	 * @throws ACPException
	 */
	public void register(String contentCode, Class<?> dataType)
			throws ACPException {

		
		Method[] methods = connectionFactory.getClass().getMethods();
		for (Method m : methods) {
			Class<?> rtType = m.getReturnType();
			if (!isIOOperationType(rtType))
				continue;

//			Method m1 = null;
//			try {
//				m1 = rtType.getMethod("create");
//			} catch (NoSuchMethodException e) {
//				e.printStackTrace();
//				throw new ACPException(
//						String.format(
//								"Fail to regist data field: io:%s doesn't implement create method for data type %s, cc=  ",
//								rtType.getSimpleName(), dataType.getName(),contentCode));
//			} catch (SecurityException e) {
//
//				e.printStackTrace();
//				throw new ACPException(e);
//			}
//			if (m1 == null)
//				continue;

			if (isRelatedIO(rtType, dataType)) {
				cc2Operations.put(contentCode, m);
				LOGGER.info(String.format(
						"Succeed to regist data field : cc=%s io=%s.",
						contentCode, rtType.getSimpleName()));
				return;			
			}
		}
		
		throw new ACPException(
				String.format(
						"Fail to regist data field: cc=%s, unknow dataType : %s",
						contentCode, dataType.getName()));

	}

	@SuppressWarnings("rawtypes")
	public IOOperations createIO(String contentCode) throws ACPException {
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

		return io;
	}

	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void receivedMessage(String contentCode, String content)
			throws ACPException, UnsupportedOperation {
		LOGGER.info("DataField Receive: cc={}, content={}", contentCode,
				content);
		if (!cc2Operations.containsKey(contentCode)) {
			LOGGER.info("Dump uninterested cc={}", contentCode);
			return;
		}

		LOGGER.info("Begin to update data field: cc={}, content={}",
				contentCode, content);
		IOOperations io = createIO(contentCode);
		DataItem dataItem = (DataItem) io.create();
		dataItem.setContentCode(contentCode);
		dataItem.setKey(content);
		dataItem.setContentCode(contentCode);
		io.read(dataItem);
		dataFields.put(contentCode, dataItem);
		LOGGER.info("Success to update data field: cc={}, content={}",
				contentCode, content);
		aplManager.bootAplCaller(contentCode, this);
	}

	public DataItem getData(String contentCode) {
		return dataFields.get(contentCode);
	}
}
