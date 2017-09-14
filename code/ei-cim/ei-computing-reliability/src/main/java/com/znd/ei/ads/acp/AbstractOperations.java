package com.znd.ei.ads.acp;

public abstract class AbstractOperations<T> implements IOOperations<T> {
 
	private Class<T> clazz; 
	public AbstractOperations(Class c) {
		clazz = c;
	}
	
	public T create() {
		try {
			return clazz.newInstance();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return null;
	}
}
