package org.test.redisson.mapreduce;

import org.redisson.RedissonNode;
import org.redisson.api.RMap;
import org.redisson.api.RedissonNodeInitializer;

public class TestRedissonInit implements RedissonNodeInitializer {

	@Override
	public void onStartup(RedissonNode redissonNode) {
		 RMap<String, Integer> map = redissonNode.getRedisson().getMap("myMap");
	        // ...
	        // 或
	        redisson.getRemoteService("myRemoteService").register(MyRemoteService.class, new MyRemoteServiceImpl(...));
	        // 或
	        reidsson.getTopic("myNotificationTopic").publish("New node has joined. id:" + redissonNode.getId() + " remote-server:" + redissonNode.getRemoteAddress());
	}

}
