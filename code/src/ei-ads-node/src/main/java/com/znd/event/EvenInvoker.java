package com.znd.event;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Parameter;

import com.znd.annotation.AplFunction;
import com.znd.annotation.AplParam;
import com.znd.bus.channel.MessageCodeEnum;
import com.znd.exception.EventException;

public class EvenInvoker {
	
	private Object object;
	private Method method;
	private String name;
	private AplContext context;
	private ParamInfo[] paramInfos;
	
	private MessageCodeEnum inputMessage;
	private MessageCodeEnum outputMessage;
	
	public static class ParamInfo {
		private Class<?> type;
		private String name;
		//private Boolean hasAnnotation; 
	}
	
	public static class EvenListenerBuilder {
		
		private EvenInvoker listener;
		public EvenListenerBuilder(Object object, Method method, AplContext context) {
			listener = new EvenInvoker();
			listener.object = object;
			listener.method = method;
			listener.context = context;
			
			
		}
		
		public EvenInvoker build() {
			Parameter[] parameters = listener.method.getParameters();
			listener.paramInfos = new ParamInfo[parameters.length];
			for (int i = 0; i < parameters.length; i++) {
				Parameter p  = parameters[i];
				ParamInfo info = new ParamInfo();
				info.type = p.getType();
				
				AplParam a = p.getAnnotation(AplParam.class);
				if (a != null) {
					info.name = a.value();
				}
				if (info.name == null || info.name.isEmpty()) {
					info.name = p.getName();	
				}
				listener.paramInfos[i] = info;
			}
			
			AplFunction af = listener.method.getAnnotation(AplFunction.class);
			listener.name = af.value();
			if (listener.name.isEmpty()) {
				listener.name = listener.method.getName();
			}
			
			listener.inputMessage = af.in();
			listener.outputMessage = af.out();
			return listener;
		}
	}
	
	public void invoke(String msg)
	{
		Object[] args = new Object[paramInfos.length];
		for (int i = 0; i < paramInfos.length; i++) {
			ParamInfo info = paramInfos[i];
			if (info.type.isAssignableFrom(AplContext.class)) {
				args[i] = context;
				continue;
			} else {
				args[i] = context.getAttribute(info.name);
				if (args[i] == null && info.type == String.class) {
					args[i] = msg;
				}
			}
			
			
		}
		
		if (args.length == 1 && args[0] == null) {
			args[0] = msg;
		}
		
		try {
			this.context.setRunning(true);
			method.invoke(object, args);
			
		} catch (IllegalAccessException | IllegalArgumentException
				| InvocationTargetException e) {
			// TODO Auto-generated catch block
			//e.printStackTrace();
			throw new EventException("Fail to invoke " + this.object+", method = "+ name, e);
		} finally {
			this.context.setRunning(false);
		}		
	}

	public AplContext getContext() {
		return context;
	}

	public String getName() {
		return name;
	}


	public MessageCodeEnum getInputMessage() {
		return inputMessage;
	}


	public MessageCodeEnum getOutputMessage() {
		return outputMessage;
	}

	
	

}
