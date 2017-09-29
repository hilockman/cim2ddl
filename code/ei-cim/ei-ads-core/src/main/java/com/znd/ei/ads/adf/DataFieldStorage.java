package com.znd.ei.ads.adf;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;
import java.util.UUID;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.ads.ServerProperties;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.IOOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.apl.AplContainer;
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

	private AplContainer aplManager;

	private ConnectionFactory connectionFactory;

	private ServerProperties serverProperties;

	private Map<String, Method> dataType2IOMethod = new HashMap<String, Method>();
	
	@Autowired
	public DataFieldStorage(ServerProperties serverProperties,
			ConnectionFactory connectionFactory, AplContainer aplManager) {
		this.serverProperties = serverProperties;
		this.connectionFactory = connectionFactory;
		this.aplManager = aplManager;

		try {
			registerIO();
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

	private boolean isRelatedIO(Class<?> ioClass, Class<?> dataTypeClass) {
		String ioname = ioClass.getSimpleName();
		String dataTypeName = dataTypeClass.getSimpleName();
		return ioname.contains(dataTypeName);
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

		DataItem createData() throws InstantiationException,
				IllegalAccessException {
			dataItem = (DataItem) dataType.newInstance();
			return dataItem;
		}

		boolean isEmpty() {
			return dataItem == null;
		}

		/**
		 * 初始化数据存储
		 * 
		 * @param key
		 * @throws IllegalAccessException
		 * @throws IllegalArgumentException
		 * @throws InvocationTargetException
		 * @throws ACPException
		 * @throws InstantiationException
		 * @throws UnsupportedOperation
		 */
		public void initDataItem() throws IllegalAccessException,
				IllegalArgumentException, InvocationTargetException,
				ACPException, InstantiationException, UnsupportedOperation {
			dataItem = createData();

			IOOperations io = createIO();
			// dataItem.setContentCode(contentCode);
			dataItem.setOperations(io);

		}

		public void initDataItem(String key) throws IllegalAccessException,
				IllegalArgumentException, InvocationTargetException,
				InstantiationException, ACPException, UnsupportedOperation {
			initDataItem();
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
		public void write() throws IllegalAccessException,
				IllegalArgumentException, InvocationTargetException,
				ACPException, UnsupportedOperation {
			//IOOperations io = createIO();
			if (dataItem != null) {
				if (dataItem.getKey() == null || dataItem.getKey().isEmpty()) { // 自动分配一个key
					dataItem.setKey(contentCode + ":"
							+ UUID.randomUUID().toString());
				}
				IOOperations io = dataItem.getOperations();
				io.write(dataItem);

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
			if (df.isEmpty()) //数据域为空，则初始化
				df.initDataItem(content);
			else if (!df.dataItem.getKey().equals(content)) { //数据域不为空，数据key值与消息不一致
				df.clear(); 
			}
		} catch (IllegalAccessException | IllegalArgumentException
				| InvocationTargetException | InstantiationException e) {

			e.printStackTrace();
			throw new ACPException(e);
		}

		LOGGER.info("Success to update data field: cc={}, content={}",
				contentCode, content);
		aplManager.bootAplCaller(contentCode, this);
	}

	public DataField getDataField(String contentCode) {
		return dataFields.get(contentCode);
	}
}
