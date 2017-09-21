package com.znd.ei.ads.adf;

import com.znd.ei.Utils;

public class StringData extends DataItem {

//	private String content;
	

	public String getContent() {
		return getKey();
	}

	public void setContent(String content) {
		setKey(content);
	}
	
	public <T> T toObject(Class<T> clazz) {
		return Utils.toObject(getContent(), clazz);
	}
}
