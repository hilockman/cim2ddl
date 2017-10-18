package org.test.proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class GirlImprove implements InvocationHandler {

	private Object girl;
	public GirlImprove(Object girl) {
		this.girl = girl;
	}
	
	@Override
	public Object invoke(Object proxy, Method method, Object[] args)
			throws Throwable {
		System.out.println("----------start invoke --------------");
		
		method.invoke(girl, args);
		System.out.println("----------after invoke --------------");
		return null;
	}

	
	public Object proxyIntance() {
		return Proxy.newProxyInstance(girl.getClass().getClassLoader(), girl.getClass().getInterfaces(), this);
	}
	
	public static void main(String [] args) {
		TeacherCang c = new TeacherCang();
		GirlImprove g = new GirlImprove(c);
		Girl g1 = (Girl)g.proxyIntance();
		g1.date(1.8f);
	}
}
