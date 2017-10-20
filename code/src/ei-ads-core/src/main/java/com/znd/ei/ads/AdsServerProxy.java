package com.znd.ei.ads;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import com.znd.ei.ads.acp.ACPException;

public class AdsServerProxy implements InvocationHandler {
	// 　这个就是我们要代理的真实对象
	private Object subject;

	// 构造方法，给我们要代理的真实对象赋初值
	public AdsServerProxy(Object subject) {
		this.subject = subject;
	}

	@Override
	public Object invoke(Object object, Method method, Object[] args)
			throws Throwable {

		//System.out.println("in proxy.");
		try {
			// 当代理对象调用真实对象的方法时，其会自动的跳转到代理对象关联的handler对象的invoke方法来进行调用
			Object rt= method.invoke(subject, args);
			//System.out.println("out proxy.");
			return rt;
		} catch (InvocationTargetException e) {
			//e.printStackTrace();
			Throwable e1 = e.getTargetException();
			if (e1 != null) {
				
				return AdsResult.formFail(e1.getMessage()).toString();
				//throw new ACPException(e1.getMessage());
			} else {
				return AdsResult.formFail(e.getMessage()).toString();
			}
			
		}

	}

}