package com.znd.ei.ads.adf;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ListDataOperations;
@SuppressWarnings("rawtypes")
public class ListData  extends DataItem  {

	private ListDataOperations operation;
	private List content = new ArrayList<String>();

	public List getContent() {
		return content;
	}

	public void setContent(List content) {
		this.content = content;
	}
	
	
	public ListData() {
		this.operation = null;
	}
	

	
	public String lpop() throws ACPException {
		if (operation == null)
			return null; 
		
	
		return operation.lpop(getName());

	}
	
	public void close() {
		if (operation == null)
			return;
		
		try {
			operation.close();
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public ListDataOperations getOperation() {
		return operation;
	}

	public void setOperation(ListDataOperations operation) {
		this.operation = operation;
	}
}
