package org.test.redisson.mapreduce;

import java.util.Iterator;

import org.redisson.api.mapreduce.RReducer;

public class WordReducer  implements RReducer<String, Integer> {

    @Override
    public Integer reduce(String reducedKey, Iterator<Integer> iter) {
        int sum = 0;
        while (iter.hasNext()) {
           Integer i = (Integer) iter.next();
           sum += i;
        }
        return sum;
    }
    
}
