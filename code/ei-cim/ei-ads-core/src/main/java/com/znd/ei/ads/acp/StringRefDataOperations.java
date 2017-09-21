package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.StringRefData;

public abstract class StringRefDataOperations extends AbstractOperations<StringRefData> {

	public StringRefDataOperations() {
		super(StringRefData.class);
		// TODO Auto-generated constructor stub
	}

	public abstract String get(String key);



}
