package com.znd.ei.ads.adf;

import java.util.List;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ListDataOperations;
public class ListData<V>  extends DataItem  {

	public List<V> getContent() {
		return getOps().getAll(getKey());
	}

	public void setContent(List<V> values) {
		getOps().pushAll(getKey(), values);
	}
	
	public ListData(String key) {
		setKey(key);
	}
	public ListData() {
	}
	

	private ListDataOperations getOps() {
		return (ListDataOperations)operations;
	}
	public V lpop() throws ACPException {
		if (operations == null)
			return null; 
		
	
		return getOps().lpop(getKey());
	}

	@Override
	public boolean isEmpty() {
		
		return getOps().isEmpty(getKey());
	}

	@Override
	public void clear() {
//		if (content != null)
//			content.clear();
//		
//		content = null;
	}

	@Override
	public boolean canClear() {
		return true;
	}
	
}
