package org.redisson.test.mapreduce;

import org.redisson.RedissonNode;
import org.redisson.api.RedissonClient;
import org.redisson.api.RedissonNodeInitializer;
import org.redisson.api.mapreduce.RCollator;
import org.redisson.api.mapreduce.RMapper;
import org.redisson.api.mapreduce.RReducer;

public class MyRedissonNodeInitializer implements RedissonNodeInitializer {
	
	
    @Override
    public void onStartup(RedissonNode redissonNode) {
    	RedissonClient redisson = redissonNode.getRedisson();
   //     RMap<String, Integer> map = redisson.getMap("myMap");
        // ...
        // 或

       redisson.getRemoteService("stateSample").register(StatSampleSeverice.class, new StatSampleSevericeImpl());
       System.out.println("register StatSampleSeverice with StatSampleSevericeImpl");
        // 或
       // redisson.getTopic("myNotificationTopic").publish("New node has joined. id:" + redissonNode.getId() + " remote-server:" + redissonNode.getRemoteAddress());
    }

}
