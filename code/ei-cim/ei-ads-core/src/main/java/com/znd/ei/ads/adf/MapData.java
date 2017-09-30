package com.znd.ei.ads.adf;

import java.util.HashMap;
import java.util.Map;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;

public class MapData extends DataItem {
	private MapDataOperations operation;

	private Map<String, String> content = new HashMap<String, String>();

	public Map<String, String> getContent() {
		return content;
	}

	public void setContent(Map<String, String> content) {
		this.content = content;
	}

	public MapDataOperations getOperation() {
		return operation;
	}

	public void setOperation(MapDataOperations operation) {
		this.operation = operation;
	}
	
	
	public String get(String key) throws ACPException, UnsupportedOperation {
		if (content != null) {
			return content.get(key);
		} else if (operation != null) {
			return operation.get(getKey(), key);
		} else
			return null;
	}
	
	public void set(String key, String value) {
		content.put(key, value);
	}

	@Override
	public boolean isEmpty() {
		return content == null || content.isEmpty();
	}
}
