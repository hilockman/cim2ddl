package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.MemDBData;


public abstract class MemDBDataOperations  extends AbstractOperations<MemDBData> {
	public abstract void upload(MemDBData db);
	public abstract void download(MemDBData db);
}
