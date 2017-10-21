package com.znd.ei.ads.acp;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Proxy;
import java.util.ArrayList;
import java.util.List;

import com.znd.ei.ads.AdsServer;
import com.znd.ei.ads.AdsServerProxy;

public abstract class AbstractConnectionFactory implements ConnectionFactory {

	/**
	 * 
	 * @param contentCode
	 * @param key
	 * @param 接收者不唯一
	 * @throws ACPException
	 */
	public void publishData(String contentCode, String key, String content)
			throws ACPException {
		publishData(contentCode, key, content, false);
	}

	/**
	 * 发送消息和数据
	 * 
	 * @param contentCode
	 * @param key
	 * @param content
	 * @param singleton
	 *            , true 表示接收者唯一, false 表示接收者不唯一
	 * @throws ACPException
	 */
	public void publishData(String contentCode, String key, String content,
			boolean singleton) throws ACPException {
		if (singleton) {
			List<String> list = new ArrayList<String>();
			list.add(content);
			ListDataOperations<String> ops = getListDataOperations();
			ops.pushAll(key, list);
			ops.close();
		} else
			publishData(contentCode, key);
	}

	/**
	 * Get remote service object for remote invocations.
	 * <p>
	 * This method is a shortcut for
	 * 
	 * <pre>
	 * get(remoteInterface, RemoteInvocationOptions.defaults())
	 * </pre>
	 *
	 * @see RemoteInvocationOptions#defaults()
	 * @see #get(Class, RemoteInvocationOptions)
	 *
	 * @param <T>
	 *            type of remote service
	 * @param remoteInterface
	 *            - remote service interface
	 * @return remote service instance
	 */
	public <T> T getService(Class<T> remoteInterface) {
		return null;
	}

	public AdsServer getServer() {
		// 我们要代理的真实对象
		AdsServer server = getService(AdsServer.class);

		// 我们要代理哪个真实对象，就将该对象传进去，最后是通过该真实对象来调用其方法的
		InvocationHandler handler = new AdsServerProxy(server);

		/*
		 * 通过Proxy的newProxyInstance方法来创建我们的代理对象，我们来看看其三个参数 第一个参数
		 * handler.getClass().getClassLoader()
		 * ，我们这里使用handler这个类的ClassLoader对象来加载我们的代理对象
		 * 第二个参数realSubject.getClass().
		 * getInterfaces()，我们这里为代理对象提供的接口是真实对象所实行的接口，
		 * 表示我要代理的是该真实对象，这样我就能调用这组接口中的方法了 第三个参数handler， 我们这里将这个代理对象关联到了上方的
		 * InvocationHandler 这个对象上
		 */
		AdsServer subject = (AdsServer) Proxy.newProxyInstance(handler
				.getClass().getClassLoader(),
				server.getClass().getInterfaces(), handler);

		return subject;
	}

	public <T> void registerService(Class<T> remoteInterface, T serviceImp) {

	}

}
