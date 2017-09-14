package com.znd.ei.ads.adf;

import com.znd.ei.ads.apl.ApplicationInfo;

public class ListDataFactory implements DataFactory<String, ListData> {

	@Override
	public ListData create(String name, ApplicationInfo applicationInfo) {
		ListData data = new ListData();
		data.setAppName(applicationInfo.getName());
		data.setCode(applicationInfo.getOutputCC());
		data.setName(name);
		return data;
	}

}
