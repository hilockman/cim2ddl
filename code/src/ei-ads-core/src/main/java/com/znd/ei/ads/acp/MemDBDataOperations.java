package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.MemDBData;


public interface MemDBDataOperations  extends IOOperations<MemDBData> {
	void upload(MemDBData db);
	void download(MemDBData db);
}
