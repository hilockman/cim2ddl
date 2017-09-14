package com.znd.ei.ads.adf;

import java.util.ArrayList;
import java.util.List;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ListOperations;
@SuppressWarnings("rawtypes")
public class ListData  extends DataItem  {

	private ListOperations operation;
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
	

	
	public String lpop() {
		if (operation == null)
			return null; 
		
		try {
			return operation.lpop(getName());
		} catch (ACPException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return null;
		}
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

	public ListOperations getOperation() {
		return operation;
	}

	public void setOperation(ListOperations operation) {
		this.operation = operation;
	}
}
