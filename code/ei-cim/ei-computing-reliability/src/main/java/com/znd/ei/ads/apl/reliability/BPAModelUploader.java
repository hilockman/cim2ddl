package com.znd.ei.ads.apl.reliability;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.ContentCodeDefines;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.apl.AppTemplate;
import com.znd.ei.ads.apl.annotations.Apl;

@Apl(value = "BPAModelUploader")
public class BPAModelUploader extends AppTemplate {

	public void upload() throws ACPException, UnsupportedOperation {
		MemDBData db = new MemDBData();
		db.setName("MemDB.Bpa");
		
		writeDataField(ContentCodeDefines.created_BPAModel, db, getConnectionFactory().getMemDBOperations());
		
	}
}
