package com.znd.ei.ads;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.MapDataOperations;
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
	
	@Autowired
	private ConnectionFactory connection;
	
	public void init() {
		System.out.println("AdsServer init ...");
	}
	
	@Override
	public String publish(String cc, String content) throws ACPException {
		System.out.println("cc = "+cc+", content = "+content);
		if (cc.equalsIgnoreCase(AdsServer.ADS_GET_SERVERINFOS)) {
			MapDataOperations ops = connection.getMapDataOperations();
			Map<String,String> nodeMap = ops.getAll(AdsServer.ADS_SERVERINFOS);
			
			Set<Entry<String, String>> s = nodeMap.entrySet();
			List<AdsServerInfo> infos  = new ArrayList<>();
			for (Entry<String, String> e : s) {
				AdsServerInfo info = Utils.toObject(e.getValue(), AdsServerInfo.class);
				infos.add(info);
			}
			
			return Utils.toString(infos);
		}
//		try {
//			dataFieldStorage.receivedMessage(cc, content);
//		} catch (ACPException | UnsupportedOperation e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
		return "ok";
	}

}
