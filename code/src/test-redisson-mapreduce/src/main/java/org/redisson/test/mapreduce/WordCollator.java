package org.redisson.test.mapreduce;

import java.util.Map;

import org.redisson.api.mapreduce.RCollator;

public class WordCollator implements RCollator<String, Integer, Integer> {

    /**
	 * 
	 */
	private static final long serialVersionUID = 9455435232543251L;

	public static int count = 0;
	@Override
    public Integer collate(Map<String, Integer> resultMap) {
		System.out.println(String.format("WordCollator.collate index = %s", count++));
        int result = 0;
        for (Integer count : resultMap.values()) {
            result += count;
        }
        return result;
    }
    
}