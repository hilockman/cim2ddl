package com.znd.ei.ads.apl;

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
import java.util.Map.Entry;
import java.util.Set;
import java.util.concurrent.ExecutorService;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Component;

import com.znd.ei.ClassFilter;
import com.znd.ei.Utils;
import com.znd.ei.ads.AdsProperties;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.DataFieldStorage.DataField;
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
public final class AplManager {

	public static void main(String[] args) {
		System.out.println(new String().getClass().equals(String.class));
	}

	private static final Logger LOGGER = LoggerFactory
			.getLogger(AplManager.class);

	@Autowired
	private ExecutorService adsThreadPool = null;

	private Map<String, List<AppCallInfo>> cc2AplCallInfos = new HashMap<String, List<AppCallInfo>>();

	private ArrayList<Object> apls = new ArrayList<Object>();

	@Autowired
	private ApplicationContext context;

	private DataFieldStorage dataFieldStorage;

	@Autowired
	private AdsProperties adsProperties;

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
		public String name;
		public String desc;
		public List<String> inputCCs = new ArrayList<String>();
		public List<String> outputCCs = new ArrayList<String>();
		public List<Class<?>> inputTypes = new ArrayList<Class<?>>();
		public String ccOper;
		public ParamInfo[] paramInfos;
		boolean isWorking = false;

		/**
		 * 判断数据区域是否可以清除
		 * 
		 * @param df
		 * @return
		 */
		public boolean canClear(DataField df) {

			if (df.dataItem != null && !df.dataItem.canClear())
				return false;

			List<AppCallInfo> appCallers = findRelatedAppCalls(df, this);
			return appCallers.isEmpty();
		}
	}

	public AplManager() {
	}

	/**
	 * 找到与appCaller相关的，所有input为df的appCallers
	 * 
	 * @param inputDataField
	 * @param appCaller
	 * @return
	 */
	public List<AppCallInfo> findRelatedAppCalls(DataField inputDataField,
			AppCallInfo appCaller) {
		Set<AppCallInfo> appCallers = new HashSet<AppCallInfo>();

		System.out.println("");
		internalFindRelatedAppCalls(appCallers, inputDataField,
				appCaller.outputCCs);

		return new ArrayList<AppCallInfo>(appCallers);
	}

	private void internalFindRelatedAppCalls(Set<AppCallInfo> appCallerSet,
			DataField inputDataField, List<String> inputCCs) {
		for (String cc : inputCCs) {
			List<AppCallInfo> appCallers = cc2AplCallInfos.get(cc);
			if (appCallers != null && !appCallers.isEmpty()) {
				for (AppCallInfo info : appCallers) {
					if (info.inputCCs.contains(inputDataField.contentCode)) {
						appCallerSet.add(info);
					}

					internalFindRelatedAppCalls(appCallerSet, inputDataField,
							info.outputCCs);
				}
			}
		}
	}

	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void loadApls(DataFieldStorage storage)
			throws InstantiationException, IllegalAccessException, ACPException {
		this.dataFieldStorage = storage;
		List skips = adsProperties.getAplSkip();
		ClassFilter filter = (Class<?> c) -> (c.getAnnotation(Apl.class) != null); 
		Set<Class<?>> classes = Utils.getClasses("com.znd.ei.ads.apl",
				filter);
		if (classes.size() == 1) // 只包含InternalAdsApls则退出
			return;

		LOGGER.info("Skip apls : {}", String.join(",", skips));
		Iterator<Class<?>> it = classes.iterator();

		while (it.hasNext()) {
			Class c = it.next();
			Annotation a = c.getAnnotation(Apl.class);
			Apl apl = (Apl) a;

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

				AppCallInfo acInfo = new AppCallInfo();
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

						paramInfo.dataField = storage.register(out,
								paramInfo.paramType, param.getName());
					}

					In in = param.getAnnotation(In.class);
					if (in != null) {
						paramInfo.bIn = true;
						cc = in.value();
						acInfo.inputCCs.add(cc);
						List<AppCallInfo> appCallInfos = cc2AplCallInfos
								.get(cc);
						if (appCallInfos == null) {
							appCallInfos = new ArrayList<AppCallInfo>();
							cc2AplCallInfos.put(cc, appCallInfos);
						}
						appCallInfos.add(acInfo);
						paramInfo.dataField = storage.register(in,
								paramInfo.paramType, param.getName());
					}
					paramInfo.cc = cc;

					if (out == null && in == null) {
						throw new ACPException(
								"Missing parameter annotaions : In/Out, .");
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
		Set<Entry<String, List<AppCallInfo>>> entrys = cc2AplCallInfos
				.entrySet();
		for (Entry<String, List<AppCallInfo>> e : entrys) {
			LOGGER.info(e.getKey());
			List<AppCallInfo> l = e.getValue();
			for (AppCallInfo c : l)
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
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public void bootAplCaller(String contentCode, DataFieldStorage storage)
			throws ACPException, UnsupportedOperation {
		List<AppCallInfo> appCallInfos = cc2AplCallInfos.get(contentCode);
		if (appCallInfos == null) {
			return;
		}

		// if (!storage.contain(contentCode))
		// return;

		// 调用业务逻辑
		for (final AppCallInfo appCallInfo : appCallInfos) {
			// 正在工作则不响应
			if (appCallInfo.isWorking)
				continue;

			List<String> inputCCs = appCallInfo.inputCCs;

			// 判断是否启动业务逻辑
			boolean boot = true;
			if (appCallInfo.ccOper.equals(AplFunction.AND)) {
				boot = true;
				System.out.println("");
				for (String cc : inputCCs) {
					if (!storage.prepared(cc)) {
						boot = false;
						break;
					}
				}
			} else {
				boot = false;
				for (String cc : inputCCs) {
					if (storage.prepared(cc)) {
						boot = true;
						break;
					}
				}
			}

			if (!boot)
				continue;

			// 业务逻辑参数初始化
			Object dataItems[] = new DataItem[appCallInfo.paramInfos.length];
			int pos = 0;
			List<ParamInfo> outputDataItems = new ArrayList<ParamInfo>();
			List<DataFieldStorage.DataField> inputDataFields = new ArrayList<DataFieldStorage.DataField>();
			List<DataFieldStorage.DataField> outputDataFields = new ArrayList<DataFieldStorage.DataField>();
			List<DataItem> outputDatas = new ArrayList<DataItem>();
			for (ParamInfo paramInfo : appCallInfo.paramInfos) {
				if (paramInfo.bIn) { // 输入参数
					dataItems[pos++] = paramInfo.dataField.dataItem;
					inputDataFields.add(paramInfo.dataField);
				} else { // 输出参数
					try {
						// paramInfo.dataField.initDataItem();
						outputDataFields.add(paramInfo.dataField);
						DataItem item = paramInfo.dataField.createData();
						dataItems[pos++] = item;
						outputDataItems.add(paramInfo);
						outputDatas.add(item);
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

			adsThreadPool.execute(new Runnable() {

				@Override
				public void run() {
					try {
						LOGGER.info(String.format(
								"------------------开始调用:%s------------------",
								appCallInfo.desc));
						appCallInfo.isWorking = true;

						// 调用业务逻辑，填充数据
						appCallInfo.method.invoke(appCallInfo.app, dataItems);

						// 清理输入数据区域
						for (DataFieldStorage.DataField df : inputDataFields) {
							if (appCallInfo.canClear(df)) {
								dataFieldStorage.clear(df);
							}
						}

						// 更新数据域
						for (int i = 0; i < outputDataFields.size(); i++) {
							DataFieldStorage.DataField df = outputDataFields
									.get(i);
							DataItem dataItem = outputDatas.get(i);
							df.dataItem = dataItem;
						}
						// 通过总线，发布数据
						for (ParamInfo paramInfo : outputDataItems) {
							DataFieldStorage.DataField df = paramInfo.dataField;

							df.publishToBus();

						}

						LOGGER.info(String.format(
								"------------------结束调用:%s------------------",
								appCallInfo.desc));
					} catch (IllegalAccessException | IllegalArgumentException
							| InvocationTargetException | ACPException
							| UnsupportedOperation e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						LOGGER.error(e.getMessage() + ", app=" + appName
								+ ", method=" + methodName);
					} finally {
						appCallInfo.isWorking = false;
					}
				}
			});

		}

		// 清除数据区域

	}

	public ApplicationContext getContext() {
		return context;
	}
}
