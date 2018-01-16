package com.znd.ei.ads;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.springframework.beans.factory.annotation.Autowired;

import com.znd.ei.Utils;
import com.znd.ei.ads.acp.ACPException;
import com.znd.ei.ads.acp.ConnectionFactory;
import com.znd.ei.ads.acp.MapDataOperations;
import com.znd.ei.ads.acp.UnsupportedOperation;
import com.znd.ei.ads.adf.AplManager;
//import com.znd.ei.ads.apl.AplManager;

/**
 * 
 * ads remote server implement
 * @author wangheng
 *
 */
public class AdsServerImp implements AdsServer {

//	@Autowired
//	private AplManager aplManager;
	
	@Autowired
	private AplManager aplManager;
	
	@Autowired
	private ConnectionFactory connectionFactory;
	
	private AdsServerInfo node = AdsServerInfo.create();

	@PostConstruct
	public void init() {
		System.out.println("AdsServer init ...");
		MapDataOperations ops = connectionFactory.getMapDataOperations();
		ops.put(AdsServer.ADS_SERVERINFOS, node.getId(), Utils.toJSon(node));
	}
	
	@PreDestroy
	public void destory() {
		System.out.println("AdsServer destory ...");
		MapDataOperations ops = connectionFactory.getMapDataOperations();
		ops.remove(AdsServer.ADS_SERVERINFOS, node.getId());	
	}


	@Override
	public String publish(String cc, String content) {
		//ConnectionFactory connection = dataFieldStorage.getConnectionFactory();
		
		System.out.println("cc = "+cc+", content = "+content);
		if (cc.equalsIgnoreCase(AdsServer.ADS_GET_SERVERINFOS)) {
			MapDataOperations ops = connectionFactory.getMapDataOperations();
			
			Map<String,String> nodeMap = ops.getAll(AdsServer.ADS_SERVERINFOS);
			
			Set<Entry<String, String>> s = nodeMap.entrySet();
			List<AdsServerInfo> infos  = new ArrayList<>();
			for (Entry<String, String> e : s) {
				AdsServerInfo info = Utils.toObject(e.getValue(), AdsServerInfo.class);
				infos.add(info);
			}
			
			return AdsResult.formOk(infos).toString();
		} else {
			try {
				aplManager.receivedMessage(cc, content);
				return AdsResult.formOk(null).toString();
			} catch (ACPException | UnsupportedOperation e) {
				return AdsResult.formFail(e.getMessage()).toString();
			}
		}

	}
	
	

}
