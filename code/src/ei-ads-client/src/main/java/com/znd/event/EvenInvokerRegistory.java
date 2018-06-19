package com.znd.event;

import java.lang.annotation.Annotation;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.annotation.PostConstruct;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.stereotype.Component;

import com.znd.apl.annotation.AplController;
import com.znd.apl.annotation.AplFunction;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.ei.ClassFilter;
import com.znd.ei.Utils;

@Component
public class EvenInvokerRegistory {

	private static final Logger logger = LoggerFactory
			.getLogger(EvenInvokerRegistory.class);
	

	private String aplPackage = "com.znd.apl";
	
	private final List<AplBean> aplBeans = new ArrayList<>();

	
	private Map<MessageCodeEnum, EvenInvoker> listenerMap = new HashMap<>();
	public EvenInvoker find(MessageCodeEnum code) {
		return listenerMap.get(code);
	}

	
	@PostConstruct
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
			//Annotation a = c.getAnnotation(AplController.class);
			//AplController apl = (AplController) a;

			// 从spring上下文获得apl对象
			Object app = context.getBean(c);
			
			Method[] methods = c.getMethods();
			
			AplBean aplBean = new AplBean.AplBeanBuilder(app).build();
			aplBeans.add(aplBean );
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
						"AplFunction : %s.%s is found, param : %s.",
						c.getName(), m.getName(),
						"[" + String.join(" ", paramTypeNames) + "]"));
				
				listenerMap.put(af.in(), new EvenInvoker.EvenListenerBulder(app, m, aplBean.getContext()).build());

			}

		}

		
	}

}
