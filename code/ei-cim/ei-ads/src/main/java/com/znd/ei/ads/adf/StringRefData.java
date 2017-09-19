package com.znd.ei.ads.adf;

import com.znd.ei.Utils;
import com.znd.ei.ads.acp.StringRefDataOperations;


public class StringRefData extends DataItem {

	private String content;
	

	public String getContent() {
		if (content != null)
			return content;
		else if (operations != null)
			content = ((StringRefDataOperations)operations).get(getKey());
		return content;
	}

	public void setContent(String content) {
		this.content = content;
	}
	
	public <T> T toObject(Class<T> clazz) {
		return Utils.toObject(getContent(), clazz);
	}
}
