package com.znd.ei.ads.adf;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ListDataOperations;
@SuppressWarnings("rawtypes")
public class ListData  extends DataItem  {

	private List content = new ArrayList<String>();

	public List getContent() {
		return content;
	}

	public void setContent(List content) {
		this.content = content;
	}
	
	
	public ListData() {
	}
	

	
	public String lpop() throws ACPException {
		if (operations == null)
			return null; 
		
	
		return ((ListDataOperations)operations).lpop(getKey());

	}

	@Override
	public boolean isEmpty() {
		
		return content == null || content.isEmpty();
	}
	
}
