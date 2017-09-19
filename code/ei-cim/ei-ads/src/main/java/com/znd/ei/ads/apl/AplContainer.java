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
public  final class AplContainer {

	
	public static void main(String [] args) {
		System.out.println(new String().getClass().equals(String.class));
	}
	private static final Logger LOGGER = LoggerFactory
			.getLogger(AplContainer.class);

	final class ParamInfo {
		public String cc;
		public Class<?> paramType;
		public boolean bIn;
		public DataFieldStorage.DataField dataField;
		
		boolean isItemDataType() {
			return dataField.dataType.equals(paramType);
		}
		
	}

	final class AppCallInfo {
		public AppInfo appInfo;
		public Object app;
		public Method method;
		public List<String> inputCCs = new ArrayList<String>();
		public List<String> outputCCs = new ArrayList<String>();
		public List<Class<?>> inputTypes = new ArrayList<Class<?>>();
		public String ccOper;
		public ParamInfo[] paramInfos;
	}
	
	private Map<String, List<AppCallInfo>> cc2AplCallInfos = new HashMap<String, List<AppCallInfo>>();

	private ArrayList<Object> apls = new ArrayList<Object>();

	public AplContainer() {
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

			Object app = c.newInstance();
			AppInfo appInfo = new AppInfo();
			String name = apl.value();
			if (name == null || name.isEmpty()) {
				name = c.getSimpleName();
			}
			appInfo.setName(name);
			appInfo.setDesc(apl.desc());
//			app.setConnectionFactory(connectionFactory);
//			app.setStorage(storage);
//			app.setAppInfo(appInfo);
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
				acInfo.appInfo = appInfo;
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
						
						paramInfo.dataField = storage.register(out, paramInfo.paramType, param.getName());
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
						paramInfo.dataField = storage.register(in, paramInfo.paramType, param.getName());
					}
					paramInfo.cc = cc;
					
					if (out == null && in == null) {
						throw new ACPException(
								"Missing parameter annotaions : In/Out, .");
					}
					
					paramTypeNames.add(paramInfo.cc
							+ (paramInfo.bIn ? "/I" : "/O"));
					acInfo.paramInfos[pos++] = paramInfo;
					//storage.register(cc, paramInfo.paramType);
				}
				LOGGER.info(String.format(
						"AplFunction : %s.%s is found, param : %s.", appInfo.getName(), m.getName(), "["
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

		if (!storage.contain(contentCode))
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
			Object dataItems[] = new DataItem[appCallInfo.paramInfos.length];
			int pos = 0;
			List<ParamInfo> outputDataItems = new ArrayList<ParamInfo>();
			for (ParamInfo paramInfo : appCallInfo.paramInfos) {
				if (paramInfo.bIn) { //输入参数
					dataItems[pos++] = paramInfo.dataField.dataItem;
				} else { //输出参数
					try {
						paramInfo.dataField.initDataItem();
						Object item = paramInfo.dataField.dataItem;
						dataItems[pos++] = item;
						outputDataItems.add(paramInfo);
						
					} catch (InstantiationException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						throw new ACPException(e.getMessage());
					} catch (IllegalAccessException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						throw new ACPException(e.getMessage());
					} catch (IllegalArgumentException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} catch (InvocationTargetException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
			
			AppInfo appInfo = appCallInfo.appInfo;
			String appName = appInfo.getName();
			String methodName = appCallInfo.method.getName();
			try {
				//调用业务逻辑，填充数据
				appCallInfo.method.invoke(appCallInfo.app, dataItems);
				
				//通过总线，发布数据
				for (ParamInfo paramInfo : outputDataItems) {
					DataFieldStorage.DataField df = paramInfo.dataField;
					df.write();			
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
