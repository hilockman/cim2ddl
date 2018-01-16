package com.znd.ei.ads.adf;

import java.lang.annotation.Annotation;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Map.Entry;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.FutureTask;
import java.util.concurrent.atomic.AtomicBoolean;

import javax.annotation.PostConstruct;
import javax.management.RuntimeErrorException;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Component;

import com.znd.ei.ClassFilter;
import com.znd.ei.Utils;
import com.znd.ei.ads.AdsProperties;
import com.znd.ei.ads.ServerProperties;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.UnsupportedOperation;
//import com.znd.ei.ads.apl.AplManager;
import com.znd.ei.ads.apl.AppInfo;
//import com.znd.ei.ads.apl.AplManager.AppCallBean;
//import com.znd.ei.ads.apl.AplManager.ParamInfo;
import com.znd.ei.ads.apl.annotations.AplController;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;

/**
 * 
 * @author wangheng 应用注册和管理
 *
 */
@Component
public final class AplManager {
	
	private static final Logger LOGGER = LoggerFactory
			.getLogger(AplManager.class);


	@Autowired
	private ConnectionFactory connectionFactory;

	@Autowired
	private ServerProperties serverProperties;

	public AplManager() {

	}

	@Autowired
	private ExecutorService adsThreadPool = null;

	private Map<String, List<AppCallBean>> cc2AplCallInfos = new HashMap<String, List<AppCallBean>>();

	private ArrayList<Object> apls = new ArrayList<Object>();

	@Autowired
	private ApplicationContext context;


	@Autowired
	private AdsProperties adsProperties;

	final class ParamInfo {
		public String cc;
		public Class<?> paramType;
		public boolean bIn;
	}

	final class AppCallBean {
		public AppInfo appInfo;
		public Object app;
		public Method method;
		public String name;
		public String desc;
		public List<String> inputCCs = new ArrayList<String>();
		public List<String> outputCCs = new ArrayList<String>();
		public List<Class<?>> inputTypes = new ArrayList<Class<?>>();
		public String ccOper;
		public ParamInfo[] paramInfos;
		AtomicBoolean isWorking = new AtomicBoolean(false);
		public Object dataItems[];
		public FutureTask<Integer> task;

		
		public FutureTask<Integer> formCallable() {
			FutureTask<Integer> future = new FutureTask<Integer>(new Callable<Integer>() {

				@Override
				public Integer call() throws Exception {
					int rt = 0;
					try {
						LOGGER.info(String.format(
								"------------------开始调用:%s------------------",
								desc));
						isWorking.set(true);

						// 调用业务逻辑，填充数据
						method.invoke(app, dataItems);

						LOGGER.info(String.format(
								"------------------结束调用:%s------------------",
								desc));
						
					} catch (IllegalAccessException | IllegalArgumentException
							| InvocationTargetException e) {
						e.printStackTrace();
						rt = -1;
					}  finally {
						isWorking.set(false);
					}
					return rt;
				}
			});
			
			return future;
		}
	}
	
	@PostConstruct
	public void init() {
		try {
			loadApls();
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
	//private Map<String, DataField> dataFields = new HashMap<String, DataField>();
	private Set<String> dataFields = new HashSet<String>();

	// private Map<String, Method> cc2Operations = new HashMap<String,
	// Method>();

	public boolean contain(String contentCode) {
		return dataFields.contains(contentCode);
	}
	


	public String getServerName() {
		if (serverProperties.getPort() == null)
			return serverProperties.getName();

		return serverProperties.getName() + serverProperties.getPort();
	}



//	public final class DataField {
//		public String contentCode = null;
//		public boolean autoLoad = false;
//	}

	/**
	 * 注册数据域
	 * @param contentCode
	 * @param dataType
	 * @param paramName
	 * @param autoLoad
	 * @return
	 * @throws ACPException
	 */
//	public DataField register(String contentCode, Class<?> dataType,
//			String paramName, boolean autoLoad) throws ACPException {
//		if (contentCode.isEmpty())
//			contentCode = paramName;
//
//		if (dataFields.containsKey(contentCode)) {
//			DataField df = dataFields.get(contentCode);
//			if (autoLoad) {
//				df.autoLoad = true;
//			}
//
//			return df;
//		}
//
//		DataField df = new DataField();
//
////		String typeName = dataType.getSimpleName();
////		df.dataType = dataType;
////		if (!dataType2IOMethod.containsKey(typeName)) {
////			if (dataType.equals(String.class)) {
////				df.dataType = ObjectRefData.class;
////				typeName = df.dataType.getSimpleName();
////			} else {
////				throw new ACPException(
////						String.format(
////								"Fail to regist data field: cc=%s, unknow dataType : %s",
////								contentCode, dataType.getName()));
////			}
////		}
//
//		df.contentCode = contentCode;
////		df.ioMethod = dataType2IOMethod.get(typeName);
//		df.autoLoad = autoLoad;
//		dataFields.put(contentCode, df);
//		return df;
//	}
	public void register(String contentCode, Class<?> dataType,
			String paramName, boolean autoLoad) throws ACPException {
		if (contentCode.isEmpty())
			contentCode = paramName;

		dataFields.add(contentCode);
	}
	
//	/**
//	 * 根据输入参数注册数据域
//	 * @param a
//	 * @param dataType
//	 * @param paramName
//	 * @return
//	 * @throws ACPException
//	 */
//	public DataField register(In a, Class<?> dataType, String paramName)
//			throws ACPException {
//		return register(a.value(), dataType, paramName, a.autoLoad());
//	}
	/**
	 * 根据输入参数注册数据域
	 * @param a
	 * @param dataType
	 * @param paramName
	 * @return
	 * @throws ACPException
	 */
	public void register(In a, Class<?> dataType, String paramName)
			throws ACPException {
		register(a.value(), dataType, paramName, a.autoLoad());
	}

//	/**
//	 * 根据输出参数注册数据域
//	 * @param a
//	 * @param dataType
//	 * @param paramName
//	 * @return
//	 * @throws ACPException
//	 */
//	public DataField register(Out a, Class<?> dataType, String paramName)
//			throws ACPException {
//		return register(a.value(), dataType, paramName, false);
//	}
	/**
	 * 根据输出参数注册数据域
	 * @param a
	 * @param dataType
	 * @param paramName
	 * @return
	 * @throws ACPException
	 */
	public void register(Out a, Class<?> dataType, String paramName)
			throws ACPException {
		register(a.value(), dataType, paramName, false);
	}




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
		if (!dataFields.contains(contentCode)) {
			LOGGER.info("Dump uninterested cc={}", contentCode);
			return;
		}

		bootAplCaller(contentCode, content);
	}
	


//	public AplManager getAplManager() {
//		return aplManager;
//	}

	public ConnectionFactory getConnectionFactory() {
		return connectionFactory;
	}
	
	
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void loadApls()
			throws InstantiationException, IllegalAccessException, ACPException {
		List skips = adsProperties.getAplSkip();
		ClassFilter filter = (Class<?> c) -> (c.getAnnotation(AplController.class) != null); 
		Set<Class<?>> classes = Utils.getClasses("com.znd.ei.ads.apl",
				filter);


		LOGGER.info("Skip apls : {}", String.join(",", skips));
		Iterator<Class<?>> it = classes.iterator();

		while (it.hasNext()) {
			Class c = it.next();
			Annotation a = c.getAnnotation(AplController.class);
			AplController apl = (AplController) a;

			// Object app = c.newInstance();
			// 从spring上下文获得apl对象
			Object app = context.getBean(c);
			AppInfo appInfo = new AppInfo();
			String name = apl.value();
			if (name == null || name.isEmpty()) {
				name = c.getSimpleName();
			}
			appInfo.setName(name);
			appInfo.setDesc(apl.desc());

			// app.setConnectionFactory(connectionFactory);
			// app.setStorage(storage);
			// app.setAppInfo(appInfo);
			apls.add(app);
			LOGGER.info(String.format(
					"apl : %s is activated.",
					(appInfo.getDesc() == null || appInfo.getDesc().isEmpty() ? appInfo
							.getName() : appInfo.getDesc())));

			Method[] methods = c.getMethods();
			for (Method m : methods) {

				AplFunction af = m.getAnnotation(AplFunction.class);
				if (af == null) {
					continue;
				}

				AppCallBean acInfo = new AppCallBean();
				acInfo.appInfo = appInfo;
				acInfo.app = app;
				acInfo.ccOper = af.ccOper();
				acInfo.method = m;
				acInfo.name = af.value();
				acInfo.desc = af.desc();
				if (acInfo.name.isEmpty()) {
					acInfo.name = m.getName();
				}

				if (acInfo.desc.isEmpty()) {
					acInfo.desc = acInfo.name;
				}

				if (skips.contains(acInfo.name)) {
					LOGGER.info("Skip app :name={},desc={}", acInfo.name,
							acInfo.desc);
					continue;
				}

				Parameter[] params = m.getParameters();
				acInfo.paramInfos = new ParamInfo[params.length];
				int pos = 0;
				List<String> paramTypeNames = new ArrayList<String>();
				for (Parameter param : params) {
					ParamInfo paramInfo = new ParamInfo();
					paramInfo.paramType = param.getType();

					Out out = param.getAnnotation(Out.class);
					String cc = null;
					if (out != null) {
						paramInfo.bIn = false;
						cc = out.value();
						acInfo.outputCCs.add(cc);

						register(out,
								paramInfo.paramType, param.getName());
					}

					In in = param.getAnnotation(In.class);
					if (in != null) {
						paramInfo.bIn = true;
						cc = in.value();
						acInfo.inputCCs.add(cc);
						List<AppCallBean> appCallInfos = cc2AplCallInfos
								.get(cc);
						if (appCallInfos == null) {
							appCallInfos = new ArrayList<AppCallBean>();
							cc2AplCallInfos.put(cc, appCallInfos);
						}
						appCallInfos.add(acInfo);
						register(in,
								paramInfo.paramType, param.getName());
					}
					paramInfo.cc = cc;

					if (out == null && in == null) {
						throw new ACPException(
								String.format("Missing parameter annotaions : In/Out, %s.%s.%s .", c.getName(), m.getName(), param.getName()));
					}

					paramTypeNames.add(paramInfo.cc
							+ (paramInfo.bIn ? "/I" : "/O"));
					acInfo.paramInfos[pos++] = paramInfo;
					// storage.register(cc, paramInfo.paramType);
				}
				LOGGER.info(String.format(
						"AplFunction : %s.%s is found, param : %s.",
						appInfo.getName(), m.getName(),
						"[" + String.join(" ", paramTypeNames) + "]"));

			}

		}

		print();
	}

	private void print() {
		LOGGER.info("--------------------Registered apl------------------");
		Set<Entry<String, List<AppCallBean>>> entrys = cc2AplCallInfos
				.entrySet();
		for (Entry<String, List<AppCallBean>> e : entrys) {
			LOGGER.info(e.getKey());
			List<AppCallBean> l = e.getValue();
			for (AppCallBean c : l)
				LOGGER.info(" {}({})", c.desc, c.name);
		}
		LOGGER.info(String
				.format("--------------------Apl : cc count=%d, apl count=%s------------------",
						cc2AplCallInfos.size(), apls.size()));
	}

	public int getAplCount() {
		return apls.size();
	}	
	/**
	 * 调用应用方法
	 * 
	 * @param contentCode
	 * @throws ACPException
	 * @throws UnsupportedOperation
	 */
	public void bootAplCaller(String contentCode, String content)
			throws ACPException, UnsupportedOperation {
		List<AppCallBean> appCallInfos = cc2AplCallInfos.get(contentCode);
		if (appCallInfos == null) {
			return;
		}

		// if (!storage.contain(contentCode))
		// return;

		// 调用业务逻辑
		for (final AppCallBean appCallInfo : appCallInfos) {
			// 正在工作则不响应
			AppInfo appInfo = appCallInfo.appInfo;
			String appName = appInfo.getName();
			String methodName = appCallInfo.method.getName();

			if (appCallInfo.isWorking.get()) {
				System.out.println("app is busy : app = "+appName+", method = "+methodName);
				continue;
			}
		

			// 业务逻辑参数初始化
			appCallInfo.dataItems = new Object[]{content};		
			if (appCallInfo.task == null) {
				appCallInfo.task = appCallInfo.formCallable();
			}
			adsThreadPool.submit(appCallInfo.task);
			appCallInfo.task = null;


		}

	}

	

	
    /**
     * 通过内部通道广播消息。
     * 本地会收到并处理该内容码,处理完成后再返回
     * @param contentCode
     * @param key
     * @param localRunnable
     */	
	public void publishAndWait(String contentCode, String key) {
		List<AppCallBean> appCallInfos = cc2AplCallInfos.get(contentCode);
		List<FutureTask<Integer> > tasks = new ArrayList<>();
		if (appCallInfos != null) {
			for (AppCallBean bean : appCallInfos) {
				bean.task = bean.formCallable();
				tasks.add(bean.task);
			}
		}
		
		connectionFactory.inner_publish(contentCode, key);
		
		if (!tasks.isEmpty()) {		
				int i = 0;
				for (FutureTask<Integer> task : tasks) {
					try {
						if (task.get() < 0) {
							throw new RuntimeErrorException(new Error("Fail to call task :"+appCallInfos.get(i++).desc));
						}
					} catch (InterruptedException | ExecutionException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						throw new RuntimeErrorException(new Error(e.getMessage()+ ", Fail to call task :"+appCallInfos.get(i++).desc));
					}			
				}
			
		}
	}
	
	
}
