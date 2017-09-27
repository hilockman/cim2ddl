package com.znd.ei.ads.apl.reliability;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.MemDBData;
import com.znd.ei.ads.adf.StringData;
import com.znd.ei.ads.apl.annotations.Apl;
import com.znd.ei.ads.apl.annotations.In;
import com.znd.ei.ads.apl.annotations.Out;

@Apl(value = "BPALoader")
public class BPALoader {

	public void upload(@In("create_BPAModel") StringData createConfig,
			@Out("created_BPAModel") MemDBData bPAModel) throws ACPException,
			UnsupportedOperation {

		bPAModel.setKey("MemDB.Bpa");

		// writeDataField(ContentCodeDefines.created_BPAModel, db,
		// getConnectionFactory().getMemDBDataOperations());

	}
}
