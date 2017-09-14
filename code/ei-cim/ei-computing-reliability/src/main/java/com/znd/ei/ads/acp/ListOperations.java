package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.ListData;


public abstract class ListOperations extends AbstractOperations<ListData> {

	public ListOperations() {
		super(ListData.class);
	}

	public abstract String lpop(String key) throws ACPException;

	public abstract void close() throws ACPException;
}
