package org.redisson.test.mapreduce;

import java.util.concurrent.Callable;

import org.redisson.api.RMap;
import org.redisson.api.RedissonClient;
import org.redisson.api.annotation.RInject;

public class CallableTask implements Callable<Long> {

    @RInject
    private RedissonClient redissonClient;

    @Override
    public Long call() throws Exception {
    	System.out.println("call CallableTask");
        RMap<String, Integer> map = redissonClient.getMap("myMap");
        Long result = 12l;
        for (Integer value : map.values()) {
            result += value;
        }
        return result;
    }

    
}