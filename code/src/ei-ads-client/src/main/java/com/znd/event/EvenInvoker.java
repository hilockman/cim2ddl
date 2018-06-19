package com.znd.event;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class EvenInvoker {
	
	private Object object;
	private Method method;
	
	private AplContext context;
	
	public static class EvenListenerBulder {
		
		private EvenInvoker listener;
		public EvenListenerBulder(Object object, Method method, AplContext context) {
			listener = new EvenInvoker();
			listener.object = object;
			listener.method = method;
			listener.context = context;
		}
		
		public EvenInvoker build() {
			return listener;
		}
	}
	
	public void invoke(String msg)
	{
		String[] args = {msg};
		try {
			this.context.setRunning(true);
			method.invoke(object, args);
			
		} catch (IllegalAccessException | IllegalArgumentException
				| InvocationTargetException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
			this.context.setRunning(false);
		}		
	}

	public AplContext getContext() {
		return context;
	}
	
	

}
