package org.test.redisson.mapreduce;

import org.redisson.api.mapreduce.RCollector;
import org.redisson.api.mapreduce.RMapper;

public class WordMapper implements RMapper<String, String, String, Integer> {

    @Override
    public void map(String key, String value, RCollector<String, Integer> collector) {
        String[] words = value.split("[^a-zA-Z]");
        for (String word : words) {
            collector.emit(word, 1);
        }
    }
    
}
