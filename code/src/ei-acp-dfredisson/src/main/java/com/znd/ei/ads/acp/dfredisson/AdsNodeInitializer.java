package com.znd.ei.ads.acp.dfredisson;

import org.redisson.RedissonNode;
import org.redisson.api.RedissonClient;
import org.redisson.api.RedissonNodeInitializer;

public class AdsNodeInitializer  implements RedissonNodeInitializer {
	
	
	public AdsNodeInitializer() {
		
	}
	
    @Override
    public void onStartup(RedissonNode redissonNode) {
 //   	DFRedissonConnection connection = DFRedissonConnection.getInstance();
    	RedissonClient redisson = redissonNode.getRedisson();
    	

   // 	redisson.getRemoteService().register(AdsServer.class, connection.getAdsServer());
    	
    	 	
   //     RMap<String, Integer> map = redisson.getMap("myMap");
        // ...
        // 或

  //     redisson.getRemoteService("stateSample").register(StateSampleSeverice.class, new StatSampleSevericeImpl());
  //     System.out.println("register StatSampleSeverice with StatSampleSevericeImpl");
        // 或
       // redisson.getTopic("myNotificationTopic").publish("New node has joined. id:" + redissonNode.getId() + " remote-server:" + redissonNode.getRemoteAddress());
    }

}
