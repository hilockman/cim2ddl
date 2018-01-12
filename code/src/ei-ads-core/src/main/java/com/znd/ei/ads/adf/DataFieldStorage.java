package com.znd.ei.ads.adf;

import java.util.HashMap;
import java.util.Map;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.ads.ServerProperties;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.apl.AplManager;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;

/**
 * 
 * @author wangheng 本地数据域存储
 *
 */
@Component
public final class DataFieldStorage {
	

//	public static void main(String [] args) {
//		Method[] methods = ConnectionFactory.class.getMethods();
//		for (Method m : methods) {
//			Class<?> rtType = m.getReturnType();
//			String name = rtType.getSimpleName();
//			System.out.println("search:"+m.getName());
//			if (!isIOOperationType(rtType))
//				continue;
//
//			
//			
//			String typeRex = "(\\w+)Operations";
//			Pattern pattern = Pattern.compile(typeRex);
//			Matcher mather = pattern.matcher(name);
//			String typeName = null;
//			if (mather.find()) {
//				typeName = mather.group(1);
//				System.out.println("find:"+typeName);
//				
//			}
//
//	
//		}
//
//	}
	

	private static final Logger LOGGER = LoggerFactory
			.getLogger(DataFieldStorage.class);

	@Autowired
	private AplManager aplManager;

	@Autowired
	private ConnectionFactory connectionFactory;

	@Autowired
	private ServerProperties serverProperties;

	//private Map<String, Method> dataType2IOMethod = new HashMap<String, Method>();
	

	public DataFieldStorage() {

	}

	@PostConstruct
	public void init() {
		try {
			aplManager.loadApls(this);
			connectionFactory.register(this);

		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	private Map<String, DataField> dataFields = new HashMap<String, DataField>();

	// private Map<String, Method> cc2Operations = new HashMap<String,
	// Method>();

	public boolean contain(String contentCode) {
		return dataFields.containsKey(contentCode);
	}
	


	public String getServerName() {
		if (serverProperties.getPort() == null)
			return serverProperties.getName();

		return serverProperties.getName() + serverProperties.getPort();
	}



	public final class DataField {
		public String contentCode = null;
		public boolean autoLoad = false;
	}

	/**
	 * 注册数据域
	 * @param contentCode
	 * @param dataType
	 * @param paramName
	 * @param autoLoad
	 * @return
	 * @throws ACPException
	 */
	public DataField register(String contentCode, Class<?> dataType,
			String paramName, boolean autoLoad) throws ACPException {
		if (contentCode.isEmpty())
			contentCode = paramName;

		if (dataFields.containsKey(contentCode)) {
			DataField df = dataFields.get(contentCode);
			if (autoLoad) {
				df.autoLoad = true;
			}

			return df;
		}

		DataField df = new DataField();

//		String typeName = dataType.getSimpleName();
//		df.dataType = dataType;
//		if (!dataType2IOMethod.containsKey(typeName)) {
//			if (dataType.equals(String.class)) {
//				df.dataType = ObjectRefData.class;
//				typeName = df.dataType.getSimpleName();
//			} else {
//				throw new ACPException(
//						String.format(
//								"Fail to regist data field: cc=%s, unknow dataType : %s",
//								contentCode, dataType.getName()));
//			}
//		}

		df.contentCode = contentCode;
//		df.ioMethod = dataType2IOMethod.get(typeName);
		df.autoLoad = autoLoad;
		dataFields.put(contentCode, df);
		return df;
	}

	/**
	 * 根据输入参数注册数据域
	 * @param a
	 * @param dataType
	 * @param paramName
	 * @return
	 * @throws ACPException
	 */
	public DataField register(In a, Class<?> dataType, String paramName)
			throws ACPException {
		return register(a.value(), dataType, paramName, a.autoLoad());
	}

	/**
	 * 根据输出参数注册数据域
	 * @param a
	 * @param dataType
	 * @param paramName
	 * @return
	 * @throws ACPException
	 */
	public DataField register(Out a, Class<?> dataType, String paramName)
			throws ACPException {
		return register(a.value(), dataType, paramName, false);
	}


//	/**
//	 * 注册IO
//	 * 
//	 * @param contentCode
//	 *            内容代码
//	 * @param dataType
//	 *            数据类型
//	 * @throws ACPException
//	 */
//	public void registerIO() throws ACPException {
//
//		Method[] methods = connectionFactory.getClass().getMethods();
//		for (Method m : methods) {
//			
//			Class<?> rtType = m.getReturnType();
//			String name = rtType.getSimpleName();
//			//System.out.println("search:"+m.getName());
//			if (!isIOOperationType(rtType))
//				continue;
//
//						
//			String typeRex = "(\\w+)Operations";
//			Pattern pattern = Pattern.compile(typeRex);
//			Matcher mather = pattern.matcher(name);
//			String typeName = null;
//			if (mather.find()) {
//				typeName = mather.group(1);
//				//System.out.println("find:"+typeName);
//				dataType2IOMethod.put(typeName, m);	
//			}
//			
//
//		}
//
//	}

	/**
	 * 处理从总线收到的消息
	 * @param contentCode
	 * @param content
	 * @throws ACPException
	 * @throws UnsupportedOperation
	 */
	public void receivedMessage(String contentCode, String content)
			throws ACPException, UnsupportedOperation {
		LOGGER.info("DataField Receive: cc={}, content={}", contentCode,
				content);
		if (!dataFields.containsKey(contentCode)) {
			LOGGER.info("Dump uninterested cc={}", contentCode);
			return;
		}

		aplManager.bootAplCaller(contentCode, content);
	}
	

//	/**
//	 * 处理从总线收到的消息
//	 * @param contentCode
//	 * @param content
//	 * @throws ACPException
//	 * @throws UnsupportedOperation
//	 */
//	public void receivedMessage(String contentCode, String content)
//			throws ACPException, UnsupportedOperation {
//		LOGGER.info("DataField Receive: cc={}, content={}", contentCode,
//				content);
//		if (!dataFields.containsKey(contentCode)) {
//			LOGGER.info("Dump uninterested cc={}", contentCode);
//			return;
//		}
//
//		LOGGER.info("Begin to update data field: cc={}, content={}",
//				contentCode, content);
//
//	
//		DataField df = dataFields.get(contentCode);
//		try {
//			if (df.isEmpty()){ //数据域为空，则初始化
//				df.initDataItem(content);
//				LOGGER.info("Success to update data field: cc={}, content={}",
//						contentCode, content);
//			}
////			else if(df.dataItem.getKey() != null && df.dataItem.getKey().equals(content)) {
////				LOGGER.info("Data file is not empty and key is same, omit update.");
////			} 
//			else  { //数据域不为空，数据key值与消息不一致
//				if (!df.isEmpty())
//					clear(df);
//					 
//				df.initDataItem(content);
//				LOGGER.info("Success to update data field: cc={}, content={}",
//						contentCode, content);
//			} 
//		} catch (IllegalAccessException | IllegalArgumentException
//				| InvocationTargetException | InstantiationException e) {
//
//			e.printStackTrace();
//			throw new ACPException(e);
//		}
//
//		
//		aplManager.bootAplCaller(contentCode, this);
//	}

//	public void clear(DataField df) {
//		LOGGER.info("清除数据域:"+df.contentCode);
//		df.clear();
//	}

	public DataField getDataField(String contentCode) {
		return dataFields.get(contentCode);
	}

	public AplManager getAplManager() {
		return aplManager;
	}

	public ConnectionFactory getConnectionFactory() {
		return connectionFactory;
	}
}
