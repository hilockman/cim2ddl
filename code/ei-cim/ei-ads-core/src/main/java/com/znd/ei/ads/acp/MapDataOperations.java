package com.znd.ei.ads.acp;

import com.znd.ei.ads.adf.MapData;

public abstract class MapDataOperations extends AbstractOperations<MapData> {

	public MapDataOperations() {
		super(MapData.class);
		// TODO Auto-generated constructor stub
	}

	public abstract String get(String key, String mkey) throws ACPException, UnsupportedOperation;

}
