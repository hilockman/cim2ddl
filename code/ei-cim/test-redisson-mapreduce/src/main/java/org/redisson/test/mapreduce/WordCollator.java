package org.redisson.test.mapreduce;

import java.util.Map;

import org.redisson.api.mapreduce.RCollator;

public class WordCollator implements RCollator<String, Integer, Integer> {

    /**
	 * 
	 */
	private static final long serialVersionUID = 9455435232543251L;

	@Override
    public Integer collate(Map<String, Integer> resultMap) {
        int result = 0;
        for (Integer count : resultMap.values()) {
            result += count;
        }
        return result;
    }
    
}