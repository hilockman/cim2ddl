package com.znd.event;

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
import org.springframework.context.ApplicationContext;

import com.znd.annotation.AplController;
import com.znd.annotation.AplFunction;
import com.znd.ei.ClassFilter;
import com.znd.ei.Utils;
import com.znd.exception.EventException;

//@Component
public class EvenInvokerRegistory {

	private static final Logger logger = LoggerFactory
			.getLogger(EvenInvokerRegistory.class);
	

	private String aplPackage = "com.znd.apl";
	
	private final List<AplBean> aplBeans = new ArrayList<>();

	private Map<String, AplBean> aplMap = new HashMap<>();
	
	private final Map<String, Map<String, EvenInvoker>> invoderMap = new HashMap<>();
	
	
		
	public EvenInvoker find(String jobType, String code) {
		Map<String, EvenInvoker> m = invoderMap.get(jobType);
		if (m == null)
			throw new EventException("Fail to find invoker map , jobtype : "+ jobType);
		EvenInvoker invoker = m.get(code);
		
		
		if (invoker == null)
			throw new EventException("Fail to find envent invoker , job:"+jobType+", event code : "+ code);
		
		return invoker;
	}

	
	
	public void init(ApplicationContext context) {
		loadApls(context);
	}
	
	private void loadApls(ApplicationContext context) {

		ClassFilter filter = (Class<?> c) -> (c.getAnnotation(AplController.class) != null); 
		Set<Class<?>> classes = Utils.getClasses(aplPackage, filter);


		logger.info("Load apls from package : {}", aplPackage);
		Iterator<Class<?>> it = classes.iterator();

		while (it.hasNext()) {
			Class<?> c = it.next();
			AplController apl = c.getAnnotation(AplController.class);


			// 从spring上下文获得apl对象
			Object app = context.getBean(c);
			
			Method[] methods = c.getMethods();
			
			AplBean aplBean = new AplBean.AplBeanBuilder(app, apl).build();
			aplBeans.add(aplBean);
			
			if (aplMap.containsKey(aplBean.getJobType())) {
				throw new EventException("Apl exists for jobtype: "+ aplBean.getJobType());
			}
			
			aplMap.put(aplBean.getJobType(), aplBean);
			
			for (Method m : methods) {

				AplFunction af = m.getAnnotation(AplFunction.class);
				if (af == null) {
					continue;
				}
				
				Parameter[] params = m.getParameters();
				List<String> paramTypeNames = new ArrayList<String>();
				for (Parameter param : params) {
					paramTypeNames.add(param.getName());
				}

				
				logger.info(String.format(
						"AplFunction : '%s.%s' is found, params : %s.",
						c.getName(), m.getName(),
						"[" + String.join(" ", paramTypeNames) + "]"));
				
				Map<String, EvenInvoker> map = invoderMap.get(aplBean.getJobType());
				if (map == null) {
					map = new HashMap<>();
					invoderMap.put(aplBean.getJobType(), map);
				}
				
				EvenInvoker listener = new EvenInvoker.EvenListenerBuilder(app, m, aplBean.getContext()).build();
				map.put(listener.getInputMessage().name(), listener);

			}

		}

		
	}


	public AplBean findApl(String typeId) {
		return aplMap.get(typeId);
	}

}
