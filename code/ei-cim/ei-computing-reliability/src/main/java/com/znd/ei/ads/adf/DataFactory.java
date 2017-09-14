package com.znd.ei.ads.adf;

import com.znd.ei.ads.apl.ApplicationInfo;

public interface DataFactory<P, T> {	
	public T create(P param, ApplicationInfo applicationInfo);
}
