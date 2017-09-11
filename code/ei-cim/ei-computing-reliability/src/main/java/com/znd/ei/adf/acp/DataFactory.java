package com.znd.ei.adf.acp;

public abstract class DataFactory<T> {

	private Connection connection;
	
	public abstract T download();
	public abstract void upload(T o);
	
	public Connection getConnection() {
		return connection;
	}
	public void setConnection(Connection connection) {
		this.connection = connection;
	}
}
