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

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
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
@Component
public class AplManager {

	private static final Logger LOGGER = LoggerFactory
			.getLogger(AplManager.class);

	public static class ParamInfo {
		public String cc;
		public Class<?> paramType;
		public boolean bIn;
	}

	public static class AppCallInfo {
		public AppTemplate app;
		public Method method;
		public List<String> inputCCs = new ArrayList<String>();
		public List<String> outputCCs = new ArrayList<String>();
		public List<Class<?>> inputTypes = new ArrayList<Class<?>>();
		public String ccOper;
		public ParamInfo[] paramInfos;
	}

	private Map<String, List<AppCallInfo>> cc2Apl = new HashMap<String, List<AppCallInfo>>();

	@Autowired
	private ConnectionFactory connectionFactory;

	private DataFieldStorage storage;

	private ArrayList<AppTemplate> apls = new ArrayList<AppTemplate>();

	@Autowired
	public AplManager(DataFieldStorage storage, ConnectionFactory connectionFactory) {
		this.storage = storage;
		this.connectionFactory = connectionFactory;

		try {
			loadApls();
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
	}

	@SuppressWarnings({ "rawtypes", "unchecked" })
	private void loadApls() throws InstantiationException,
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
						List<AppCallInfo> appCallInfos = cc2Apl.get(cc);
						if (appCallInfos == null)
							appCallInfos = new ArrayList<AppCallInfo>();
						appCallInfos.add(acInfo);
					}
					paramInfo.cc = cc;
					
					if (out == null && in == null) {
						throw new ACPException(
								"Missing parameter annotaions : In/Out, .");
					}
					
					paramTypeNames.add(paramInfo.paramType.getSimpleName()
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
	 * 启动应用
	 * 
	 * @param contentCode
	 * @throws ACPException 
	 */
	public void beginWork(String contentCode) throws ACPException {
		List<AppCallInfo> appCallInfos = cc2Apl.get(contentCode);
		if (appCallInfos == null) {
			return;
		}

		DataItem dataItem = storage.getData(contentCode);
		if (dataItem == null)
			return;

		// 调用业务逻辑
		for (AppCallInfo appCallInfo : appCallInfos) {

			List<String> inputCCs = appCallInfo.inputCCs;
			AppInfo appInfo = appCallInfo.app.getAppInfo();

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

			DataItem dataItems[] = new DataItem[appCallInfo.paramInfos.length];
			int pos = 0;
			for (ParamInfo paramInfo : appCallInfo.paramInfos) {
				if (paramInfo.bIn) {
					dataItems[pos++] = storage.getData(paramInfo.cc);
				} else {
					try {
						dataItems[pos++] = (DataItem) paramInfo.paramType.newInstance();
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
			try {
				appCallInfo.method.invoke(appCallInfo.app, dataItems);
			} catch (IllegalAccessException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage());
			} catch (IllegalArgumentException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage());
			} catch (InvocationTargetException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				throw new ACPException(e.getMessage());
			}

		}

		// 清除数据区域

	}
}
