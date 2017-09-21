package com.znd.ei.ads.adf;

import com.znd.ei.ads.apl.AppInfo;

public interface DataFactory<P, T> {	
	public T create(P param, AppInfo applicationInfo);
}
