package com.znd.ei.ads.adf;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.ads.ServerProperties;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.IOOperations;
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
	
	public static void main(String [] args) {
		Method[] methods = ConnectionFactory.class.getMethods();
		for (Method m : methods) {
			Class<?> rtType = m.getReturnType();
			String name = rtType.getSimpleName();
			System.out.println("search:"+m.getName());
			if (!isIOOperationType(rtType))
				continue;

			
			
			String typeRex = "(\\w+)Operations";
			Pattern pattern = Pattern.compile(typeRex);
			Matcher mather = pattern.matcher(name);
			String typeName = null;
			if (mather.find()) {
				typeName = mather.group(1);
				System.out.println("find:"+typeName);
				
			}

	
		}

	}
	

	private static final Logger LOGGER = LoggerFactory
			.getLogger(DataFieldStorage.class);

	@Autowired
	private AplManager aplManager;

	@Autowired
	private ConnectionFactory connectionFactory;

	@Autowired
	private ServerProperties serverProperties;

	private Map<String, Method> dataType2IOMethod = new HashMap<String, Method>();
	

	public DataFieldStorage() {

	}

	@PostConstruct
	public void init() {
		try {
			registerIO();
			aplManager.loadApls(this);
//			ApplicationContext context = aplManager.getContext();
//			AdsServer server = context.getBean(AdsServer.class);
//			if (server != null && server instanceof AdsServerImp) {
//				AdsServerImp serverImp = (AdsServerImp) server;
//				serverImp.init();
//			}

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
	private Map<String, DataField> dataFields = new HashMap<String, DataField>();

	// private Map<String, Method> cc2Operations = new HashMap<String,
	// Method>();

	public boolean contain(String contentCode) {
		return dataFields.containsKey(contentCode);
	}
	
	/**
	 * 数据域是否准备好
	 * @param contentCode
	 * @return
	 */
	public boolean prepared(String contentCode) {
		if (!contain(contentCode))
			return false;
		
		DataField df = dataFields.get(contentCode);
		if (df != null && !df.isEmpty())
			return true;
		
		return false;
	}

	public String getServerName() {
		if (serverProperties.getPort() == null)
			return serverProperties.getName();

		return serverProperties.getName() + serverProperties.getPort();
	}

	public static boolean isIOOperationType(Class<?> clazz) {
		try {
			if (clazz.asSubclass(IOOperations.class) != null) {
				return true;
			}
			return false;
		} catch (ClassCastException e) {
			return false;
		}

	}



	public final class DataField {
		public String contentCode = null;
		public boolean autoLoad = false;
		public DataItem dataItem = null;
		public Method ioMethod = null;
		public Class<?> dataType = null;

		IOOperations createIO() throws ACPException, IllegalAccessException,
				IllegalArgumentException, InvocationTargetException {
			return (IOOperations) ioMethod.invoke(connectionFactory);
		}

		public DataItem createData() throws InstantiationException,
				IllegalAccessException, IllegalArgumentException, InvocationTargetException, ACPException {
			DataItem d = (DataItem) dataType.newInstance();
			IOOperations io = createIO();
			// dataItem.setContentCode(contentCode);
			d.setOperations(io);
			return d;
		}

		boolean isEmpty() {
			return dataItem == null;
		}

		


		public void initDataItem(String key) throws IllegalAccessException,
				IllegalArgumentException, InvocationTargetException,
				InstantiationException, ACPException, UnsupportedOperation {
			dataItem = createData();
			dataItem.setKey(key);
			if (autoLoad) {				
				dataItem.getOperations().read(dataItem);
			}			
		}

		/**
		 * 发布数据到总线
		 * 
		 * @throws ACPException
		 * @throws InvocationTargetException
		 * @throws IllegalArgumentException
		 * @throws IllegalAccessException
		 * @throws UnsupportedOperation
		 */
		@SuppressWarnings("unchecked")
		public void publishToBus() throws IllegalAccessException,
				IllegalArgumentException, InvocationTargetException,
				ACPException, UnsupportedOperation {
			//IOOperations io = createIO();
			if (dataItem != null && !dataItem.isEmpty()) {
				if (contentCode == null) {
					LOGGER.error("cc is empty.");
				}
				if (dataItem.getKey() == null || dataItem.getKey().isEmpty()) { // 自动分配一个key
					dataItem.setKey(contentCode + ":"
							+ UUID.randomUUID().toString());
				}
				IOOperations<DataItem> io = dataItem.getOperations();
				LOGGER.info(String.format("Upload data : key = %s.", dataItem.getKey()));
				io.write(dataItem);
				LOGGER.info(String.format("Publish data :cc = %s key = %s.",contentCode, dataItem.getKey()));
				connectionFactory.publishData(contentCode, dataItem.getKey());
			}

		}

		void clear() {
			if (dataItem != null)
				dataItem.clear();
			
			dataItem = null;
		}
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
			
			if (dataType.equals(MemDBData.class)) {
				df.autoLoad = true;
			}

			return df;
		}

		DataField df = new DataField();

		String typeName = dataType.getSimpleName();
		df.dataType = dataType;
		if (!dataType2IOMethod.containsKey(typeName)) {
			if (dataType.equals(String.class)) {
				df.dataType = StringRefData.class;
				typeName = df.dataType.getSimpleName();
			} else {
				throw new ACPException(
						String.format(
								"Fail to regist data field: cc=%s, unknow dataType : %s",
								contentCode, dataType.getName()));
			}
		}

		df.contentCode = contentCode;
		df.ioMethod = dataType2IOMethod.get(typeName);
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


	/**
	 * 注册IO
	 * 
	 * @param contentCode
	 *            内容代码
	 * @param dataType
	 *            数据类型
	 * @throws ACPException
	 */
	public void registerIO() throws ACPException {

		Method[] methods = connectionFactory.getClass().getMethods();
		for (Method m : methods) {
			
			Class<?> rtType = m.getReturnType();
			String name = rtType.getSimpleName();
			//System.out.println("search:"+m.getName());
			if (!isIOOperationType(rtType))
				continue;

						
			String typeRex = "(\\w+)Operations";
			Pattern pattern = Pattern.compile(typeRex);
			Matcher mather = pattern.matcher(name);
			String typeName = null;
			if (mather.find()) {
				typeName = mather.group(1);
				//System.out.println("find:"+typeName);
				dataType2IOMethod.put(typeName, m);	
			}
			
			// Method m1 = null;
			// try {
			// m1 = rtType.getMethod("create");
			// } catch (NoSuchMethodException e) {
			// e.printStackTrace();
			// throw new ACPException(
			// String.format(
			// "Fail to regist data field: io:%s doesn't implement create method for data type %s, cc=  ",
			// rtType.getSimpleName(), dataType.getName(),contentCode));
			// } catch (SecurityException e) {
			//
			// e.printStackTrace();
			// throw new ACPException(e);
			// }
			// if (m1 == null)
			// continue;

			// if (isRelatedIO(rtType, dataType)) {
			// cc2Operations.put(contentCode, m);
			// LOGGER.info(String.format(
			// "Succeed to regist data field : cc=%s io=%s.",
			// contentCode, rtType.getSimpleName()));
			// return;
			// }
		}

	}

	// @SuppressWarnings("rawtypes")
	// public IOOperations createIO(String contentCode) throws ACPException {
	// Method m = cc2Operations.get(contentCode);
	// IOOperations io = null;
	// try {
	// io = (IOOperations) m.invoke(connectionFactory);
	// } catch (IllegalAccessException e) {
	// // TODO Auto-generated catch block
	// e.printStackTrace();
	// throw new ACPException(e);
	// } catch (IllegalArgumentException e) {
	// // TODO Auto-generated catch block
	// e.printStackTrace();
	// throw new ACPException(e);
	// } catch (InvocationTargetException e) {
	// // TODO Auto-generated catch block
	// e.printStackTrace();
	// throw new ACPException(e);
	// }
	//
	// return io;
	// }

	/**
	 * 处理从总线收到的消息
	 * @param contentCode
	 * @param content
	 * @throws ACPException
	 * @throws UnsupportedOperation
	 */
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void receivedMessage(String contentCode, String content)
			throws ACPException, UnsupportedOperation {
		LOGGER.info("DataField Receive: cc={}, content={}", contentCode,
				content);
		if (!dataFields.containsKey(contentCode)) {
			LOGGER.info("Dump uninterested cc={}", contentCode);
			return;
		}

		LOGGER.info("Begin to update data field: cc={}, content={}",
				contentCode, content);

	
		DataField df = dataFields.get(contentCode);
		try {
			if (df.isEmpty()){ //数据域为空，则初始化
				df.initDataItem(content);
				LOGGER.info("Success to update data field: cc={}, content={}",
						contentCode, content);
			} else if(df.dataItem.getKey() != null && df.dataItem.getKey().equals(content)) {
				LOGGER.info("Data file is not empty and key is same, omit update.");
			} else  { //数据域不为空，数据key值与消息不一致
				if (!df.isEmpty())
					clear(df);
					 
				df.initDataItem(content);
				LOGGER.info("Success to update data field: cc={}, content={}",
						contentCode, content);
			} 
		} catch (IllegalAccessException | IllegalArgumentException
				| InvocationTargetException | InstantiationException e) {

			e.printStackTrace();
			throw new ACPException(e);
		}

		
		aplManager.bootAplCaller(contentCode, this);
	}

	public void clear(DataField df) {
		synchronized(df) {
			LOGGER.info("清除数据域:"+df.contentCode);
			df.clear();
		}
	}

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
