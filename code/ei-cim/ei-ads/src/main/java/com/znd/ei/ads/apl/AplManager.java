package com.znd.ei.ads.apl;

import java.lang.annotation.Annotation;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.UUID;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.IOOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.DataItem;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.AplFunction;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;

/**
 * 
 * @author wangheng 应用管理用于应用注册
 *
 */
public  final class AplManager {

	private static final Logger LOGGER = LoggerFactory
			.getLogger(AplManager.class);

	final class ParamInfo {
		public String cc;
		public Class<?> paramType;
		public boolean bIn;
	}

	final class AppCallInfo {
		public AppTemplate app;
		public Method method;
		public List<String> inputCCs = new ArrayList<String>();
		public List<String> outputCCs = new ArrayList<String>();
		public List<Class<?>> inputTypes = new ArrayList<Class<?>>();
		public String ccOper;
		public ParamInfo[] paramInfos;
	}
	
	private Map<String, List<AppCallInfo>> cc2AplCallInfos = new HashMap<String, List<AppCallInfo>>();

	private ConnectionFactory connectionFactory;

	private ArrayList<AppTemplate> apls = new ArrayList<AppTemplate>();

	public AplManager(ConnectionFactory connectionFactory) {
		this.connectionFactory = connectionFactory;
	}

	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void loadApls(DataFieldStorage storage) throws InstantiationException,
			IllegalAccessException, ACPException {
		Set<Class<?>> classes = Utils.getClasses("com.znd.ei.ads.apl");

		Iterator<Class<?>> it = classes.iterator();
		while (it.hasNext()) {
			Class c = it.next();
			Annotation a = c.getAnnotation(Apl.class);
			if (a == null)
				continue;

			Apl apl = (Apl) a;

			AppTemplate app = (AppTemplate) c.newInstance();
			AppInfo appInfo = new AppInfo();
			String name = apl.value();
			if (name == null || name.isEmpty()) {
				name = c.getSimpleName();
			}
			appInfo.setName(name);
			appInfo.setDesc(apl.desc());
			app.setConnectionFactory(connectionFactory);
			app.setStorage(storage);
			app.setAppInfo(appInfo);
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

				AppCallInfo acInfo = new AppCallInfo();
				acInfo.app = app;
				acInfo.ccOper = af.ccOper();
				acInfo.method = m;
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
					}

					In in = param.getAnnotation(In.class);
					if (in != null) {
						paramInfo.bIn = true;
						cc = in.value();
						acInfo.inputCCs.add(cc);
						List<AppCallInfo> appCallInfos = cc2AplCallInfos.get(cc);
						if (appCallInfos == null) {
							appCallInfos = new ArrayList<AppCallInfo>();
							cc2AplCallInfos.put(cc, appCallInfos);
						}
						appCallInfos.add(acInfo);
					}
					paramInfo.cc = cc;
					
					if (out == null && in == null) {
						throw new ACPException(
								"Missing parameter annotaions : In/Out, .");
					}
					
					paramTypeNames.add(paramInfo.cc
							+ (paramInfo.bIn ? "/I" : "/O"));
					acInfo.paramInfos[pos++] = paramInfo;
					storage.register(cc, paramInfo.paramType);
				}
				LOGGER.info(String.format(
						"AplFunction : %s.%s is found, param : %s.", app
								.getAppInfo().getName(), m.getName(), "["
								+ String.join(" ", paramTypeNames) + "]"));
			}

		}
	}

	/**
	 * 调用应用方法
	 * 
	 * @param contentCode
	 * @throws ACPException 
	 * @throws UnsupportedOperation 
	 */
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void bootAplCaller(String contentCode, DataFieldStorage storage) throws ACPException, UnsupportedOperation {
		List<AppCallInfo> appCallInfos = cc2AplCallInfos.get(contentCode);
		if (appCallInfos == null) {
			return;
		}

		DataItem dataItem = storage.getData(contentCode);
		if (dataItem == null)
			return;

		// 调用业务逻辑
		for (AppCallInfo appCallInfo : appCallInfos) {

			List<String> inputCCs = appCallInfo.inputCCs;
			

			// 判断是否启动业务逻辑
			boolean boot = true;
			if (appCallInfo.ccOper.equals(AplFunction.AND)) {
				boot = true;
			} else {
				boot = false;
			}

			for (String cc : inputCCs) {
				if (appCallInfo.ccOper.equals(AplFunction.AND)
						&& !storage.contain(cc)) {
					boot = false;
					break;
				}

				if (appCallInfo.ccOper.equals(AplFunction.OR)
						&& storage.contain(cc)) {
					boot = true;
					break;
				}
			}

			if (!boot)
				continue;

			//业务逻辑参数初始化
			DataItem dataItems[] = new DataItem[appCallInfo.paramInfos.length];
			int pos = 0;
			List<DataItem> outputDataItems = new ArrayList<DataItem>();
			for (ParamInfo paramInfo : appCallInfo.paramInfos) {
				if (paramInfo.bIn) { //输入参数
					dataItems[pos++] = storage.getData(paramInfo.cc);
				} else { //输出参数
					try {
						DataItem item = (DataItem) paramInfo.paramType.newInstance();
						item.setContentCode(paramInfo.cc);
						dataItems[pos++] = item;
						outputDataItems.add(item);
					} catch (InstantiationException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						throw new ACPException(e.getMessage());
					} catch (IllegalAccessException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						throw new ACPException(e.getMessage());
					}
				}
			}
			
			AppInfo appInfo = appCallInfo.app.getAppInfo();
			String appName = appInfo.getName();
			String methodName = appCallInfo.method.getName();
			try {
				//调用业务逻辑，填充数据
				appCallInfo.method.invoke(appCallInfo.app, dataItems);
				
				//调用总线，发布数据
				for (DataItem item : outputDataItems) {
					IOOperations io = storage.createIO(item.getContentCode());
					if (item.getKey() == null || item.getKey().isEmpty()) { //自动分配一个key						
						item.setKey(item.getContentCode()+":"+UUID.randomUUID().toString());					
					}
					if (io != null)
						io.write(item);
				}
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage()+", app="+appName+", method="+methodName);
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage()+", app="+appName+", method="+methodName);
			} catch (InvocationTargetException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage()+", app="+appName+", method="+methodName);
			}


		}

		// 清除数据区域

	}
}
