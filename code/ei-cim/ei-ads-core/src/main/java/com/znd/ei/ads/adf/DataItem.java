package com.znd.ei.ads.adf;

import com.znd.ei.ads.acp.IOOperations;

public abstract class DataItem {
	protected IOOperations operations;
	private String key;

	public String getKey() {
		return key;
	}

	public void setKey(String name) {
		this.key = name;
	}

	public IOOperations getOperations() {
		return operations;
	}

	public void setOperations(IOOperations operations) {
		this.operations = operations;
	}

	public  void clear() {
		
	}

	public abstract boolean isEmpty();

}
