package com.znd.ei.ads.apl;

import java.lang.annotation.Annotation;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
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
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.adf.DataItem;
import com.znd.ei.ads.apl.annotations.Apl;

/**
 * 
 * @author wangheng
 * 应用管理用于应用注册
 *
 */
@Component
public class AplManager {
	private static final Logger LOGGER = LoggerFactory
			.getLogger(AplManager.class);


	@Autowired
	private ConnectionFactory connectionFactory;
	
	@Autowired
	private DataFieldStorage storage;
	
	private ArrayList<AppTemplate> apls = new ArrayList<AppTemplate>();
	
	@Autowired
	public AplManager(ConnectionFactory connectionFactory) {
		this.connectionFactory = connectionFactory;
		
		try {
			loadApls();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	
	@SuppressWarnings({ "rawtypes", "unchecked" })
	private void loadApls() throws InstantiationException, IllegalAccessException {
		Set<Class<?>> classes = Utils.getClasses("com.znd.ei.ads.apl");
		
		Iterator<Class<?>> it = classes.iterator();
		while (it.hasNext()) {
			Class c = it.next();
			Annotation a = c.getAnnotation(Apl.class);
			if (a != null) {
				Apl apl = (Apl)a;

				AppTemplate app = (AppTemplate) c.newInstance();
				app.setConnectionFactory(connectionFactory);
				app.setStorage(storage);
				apls.add(app);
				LOGGER.info(String.format("apl : %s is activated.", apl.value()));				
			}	
		}	
	}
	
	public void processEvent(String contentCode, String content) {
		
	}
	
	public static class AppInfo
	{
		public AppTemplate app;
		public Method method;	
	}
	
	
	private Map<String, List<AppInfo> > cc2Apl = new HashMap<String, List<AplManager.AppInfo> >();
	
	
	/**
	 * 启动应用
	 * @param contentCode
	 */
	public void beginWork(String contentCode) {
		// TODO Auto-generated method stub
		List<AppInfo> appInfos = cc2Apl.get(contentCode);
		if (appInfos == null) {
			return;
		}
		
		DataItem dataItem = storage.getData(contentCode);
		if (dataItem == null)
			return;
		
		for (AppInfo appInfo : appInfos) {
			try {
				appInfo.method.invoke(appInfo.app, dataItem);
			} catch (IllegalAccessException | IllegalArgumentException
					| InvocationTargetException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
}
