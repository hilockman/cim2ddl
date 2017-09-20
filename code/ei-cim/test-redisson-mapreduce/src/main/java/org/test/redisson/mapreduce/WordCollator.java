package org.test.redisson.mapreduce;

import java.util.Map;

import org.redisson.api.mapreduce.RCollator;

public class WordCollator implements RCollator<String, Integer, Integer> {

    @Override
    public Integer collate(Map<String, Integer> resultMap) {
        int result = 0;
        for (Integer count : resultMap.values()) {
            result += count;
        }
        return result;
    }
    
}