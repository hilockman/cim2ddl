package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.MemDBData;


public abstract class MemDbOperations  extends AbstractOperations<MemDBData> {

	public MemDbOperations() {
		super(MemDBData.class);
	}

}
