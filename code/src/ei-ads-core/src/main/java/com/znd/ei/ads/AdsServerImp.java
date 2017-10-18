package com.znd.ei.ads;

import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.adf.DataFieldStorage;
import com.znd.ei.ads.apl.AplManager;

/**
 * 
 * ads remote server implement
 * @author wangheng
 *
 */
public class AdsServerImp implements AdsServer {

	@Autowired
	private AplManager aplManager;
	
	@Autowired
	private DataFieldStorage dataFieldStorage;
	
	public void init() {
		System.out.println("AdsServer init ...");
	}
	
	@Override
	public String publish(String cc, String content) throws ACPException {
		System.out.println("cc = "+cc+", content = "+content);
//		try {
//			dataFieldStorage.receivedMessage(cc, content);
//		} catch (ACPException | UnsupportedOperation e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		return "ok";
	}

}
