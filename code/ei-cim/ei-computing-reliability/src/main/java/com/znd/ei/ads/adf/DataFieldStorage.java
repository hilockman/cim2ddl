package com.znd.ei.ads.adf;

import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.znd.ei.ads.acp.IOOperations;
import com.znd.ei.ads.apl.AplManager;
import com.znd.ei.ads.apl.AppTemplate;

/**
 * 
 * @author wangheng
 * 本地数据域存储
 *
 */
@Component
public class DataFieldStorage {

	@Autowired
	AplManager aplManager;
	
	private Map<String, DataItem> dataFields = new HashMap<String, DataItem>();
	private Map<String, IOOperations> cc2Operations = new HashMap<String, IOOperations>();
	public boolean containInput(String contentCode) {
		return dataFields.containsKey(contentCode);
	}

	

	
	public void register(String contentCode, IOOperations io) {
		cc2Operations.put(contentCode, io);
		
		
	}
	
	public void receivedMessage(String contentCode, String content) {
		aplManager.beginWork(contentCode);
	}




	public DataItem getData(String contentCode) {
		return dataFields.get(contentCode);
	}
}
