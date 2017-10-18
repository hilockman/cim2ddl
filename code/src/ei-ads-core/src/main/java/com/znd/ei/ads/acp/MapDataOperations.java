package com.znd.ei.ads.acp;

import java.util.Map;

import com.znd.ei.ads.adf.MapData;

public abstract class MapDataOperations extends AbstractOperations<MapData> {

	public MapDataOperations() {
		super(MapData.class);
		// TODO Auto-generated constructor stub
	}

	public abstract String get(String key, String mkey) throws ACPException, UnsupportedOperation;

	public abstract Long getSize(String key) ;

	public abstract void remove(String key, String...keys) ;
	
	public abstract void put(String key, String hashKey, String value);

	public  abstract Map<String, String> getAll(String key);

}
