package org.test.redisson.mapreduce;

import org.redisson.Redisson;
import org.redisson.RedissonNode;
import org.redisson.api.RMap;
import org.redisson.api.RedissonNodeInitializer;
import org.springframework.beans.factory.annotation.Autowired;

public class TestRedissonInit implements RedissonNodeInitializer {

	@Autowired
	private Redisson redisson;

	@Override
	public void onStartup(RedissonNode redissonNode) {
		RMap<String, Integer> map = redissonNode.getRedisson().getMap("myMap");
		// ...
		// 或
		redisson.getRemoteService("myRemoteService").register(
				MyRemoteService.class, new MyRemoteServiceImpl());
		// 或
		redisson.getTopic("myNotificationTopic").publish(
				"New node has joined. id:" + redissonNode.getId()
						+ " remote-server:" + redissonNode.getRemoteAddress());
	}

}
