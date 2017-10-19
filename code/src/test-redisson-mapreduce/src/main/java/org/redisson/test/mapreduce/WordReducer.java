package org.redisson.test.mapreduce;

import java.util.Iterator;

import org.redisson.api.mapreduce.RReducer;

public class WordReducer  implements RReducer<String, Integer> {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1043243453245L;

	private static int count = 0;
	@Override
    public Integer reduce(String reducedKey, Iterator<Integer> iter) {
		System.out.println(String.format("WordReducer.reduce index = %s, reducedKey = %s", count++, reducedKey));
		int sum = 0;
        while (iter.hasNext()) {
           Integer i = (Integer) iter.next();
           sum += i;
        }
        return sum;
    }
    
}
