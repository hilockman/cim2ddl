package com.znd.ei.ads.acp;

public abstract class AbstractOperations<T> implements IOOperations<T> {
 
	private Class<T> dataType; 
	public AbstractOperations(Class c) {
		dataType = c;
	}
	
	public T create() {
		try {
			return dataType.newInstance();
		} catch (InstantiationException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		return null;
	}

	public Class<T> getDataType() {
		return dataType;
	}
}
