package com.znd.ei.ads.acp;

public abstract class DataFactory<T> {

	private ConnectionFactory connection;
	
	public abstract T download();
	public abstract void upload(T o);
	
	public ConnectionFactory getConnection() {
		return connection;
	}
	public void setConnection(ConnectionFactory connection) {
		this.connection = connection;
	}
}
